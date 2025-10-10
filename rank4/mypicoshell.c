#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void child_process(int prev_pipe, int pip[2], char *cmd[])
{
	if (prev_pipe != -1){
		if (dup2(prev_pipe, STDIN_FILENO) == -1){
			close(prev_pipe);
			if (pip[0] != -1){
				close(pip[0]);
				close(pip[1]);
			}
			exit(1);
		}
		close(prev_pipe);
	}
	if (pip[0] != -1){
		close(pip[0]);
		if (dup2(pip[1], STDOUT_FILENO) == -1){
			close(pip[1]);
			exit(1);
		}
		close(pip[1]);
	}
	execvp(*cmd, cmd);
	exit(1);
}

void close_pipe_ends(int prev_pipe, int pip[2])
{
	if (prev_pipe != -1){
		close(prev_pipe);
	}
	if (pip[0] != -1){
		close(pip[0]);
		close(pip[1]);
	}
}

int picoshell(char **cmds[])
{
	int prev_pipe = -1;
	int pip[2];
	int status;
	pid_t pid;
	int i = 0;

	while (cmds[i])
	{
		if (cmds[i + 1]){
			if (pipe(pip) == -1){
				close_pipe_ends(prev_pipe, pip);
				return 1;
			}
		}
		else{
			pip[0] = -1;
			pip[1] = -1;
		}
		pid = fork();
		if (pid == -1){
			close_pipe_ends(prev_pipe, pip);
			return 1;
		}
		if (pid == 0){
			child_process(prev_pipe, pip, cmds[i]);
		}
		if (pip[0] != -1){
			if (prev_pipe != -1){
				close(prev_pipe);
			}
			prev_pipe = pip[0];
			pip[0] = -1;
			close(pip[1]);
			pip[1] = -1;
		}
		else{
			if (prev_pipe != -1){
				close(prev_pipe);
				prev_pipe = -1;
			}
		}
		wait(&status);
		if (!WIFEXITED(status)){
			close_pipe_ends(prev_pipe, pip);
			return 1;
		}
		if (WEXITSTATUS(status)){
			close_pipe_ends(prev_pipe, pip);
			return 1;
		}
		i++;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc < 2)
		return 1;
	int cmd_count = 1;
	for (int i = 1; i < argc; i++)
		if (!strcmp(argv[i], "|"))
			cmd_count++;
	char ***cmds = calloc(cmd_count + 1, sizeof(char **));
	if (!cmds) {
		printf("calloc err %m");
		return 1;
	}

	cmds[0] = argv + 1;
	int cmds_i = 1;
	
	for (int i = 1; i < argc; i++)
		if (!strcmp(argv[i], "|")) {
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}

	int ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return (ret);
}