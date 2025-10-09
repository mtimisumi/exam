#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void setup_input_output(int pip[2], int prev_pipe)
{
	if (prev_pipe != -1){
		if (pip[0] != -1){
			close(pip[0]); pip[0] = -1;
		}
		if (dup2(prev_pipe, STDIN_FILENO) == -1){
			exit(1);
		}
		close(prev_pipe); prev_pipe = -1;
	}
	if (pip[1] != -1){
		if (dup2(pip[1], STDOUT_FILENO) == -1){
			exit(1);
		}
		close(pip[1]); pip[1] = -1;
	}
}

void child_process(int pip[2], int prev_pipe, char *cmd[])
{
	setup_input_output(pip, prev_pipe);
	if (execvp(*cmd, cmd) == -1)
		exit(1);
}

int wait_for_child()
{
	int status;
	wait(&status);
	if (!WIFEXITED(status))
		return 1;
	if (WEXITSTATUS(status))
		return 1;
	return 0;
}

int picoshell(char **cmds[])
{
	int prev_pipe = -1;
	int pip[2];
	pid_t pid;
	int i = 0;
	int exit;

	while (cmds[i])
	{
		pip[0] = -1;
		pip[1] = -1;
		if (cmds[i + 1]){
			if (pipe(pip) == -1)
				return 1;
		}
		pid = fork();
		if (pid == -1)
			return 1;
		if (pid == 0)
			child_process(pip, prev_pipe, cmds[i]);
		if (pip[0] != -1){
			prev_pipe = pip[0];
			close(pip[1]);
		}
		else{
			if (prev_pipe != -1)
				close(prev_pipe);
		}
		exit = wait_for_child();
		i++;
	}
	return exit;
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