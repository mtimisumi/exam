#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int pipe_to_read(pid_t pid, int pip[2], char **cmd)
{
	pid = fork();
	if (pid == -1){
		return -1;
	}
	if (pid == 0){
		if (dup2(pip[1], STDOUT_FILENO) == -1)
			exit(1);
		close(pip[1]);
		close(pip[0]);
		if (execvp(*cmd, cmd) == -1)
			exit(1);
	}
	close(pip[1]);
	return 0;
}

int pipe_to_write(pid_t pid, int pip[2], char **cmd)
{
	pid = fork();
	if (pid == -1){
		return -1;
	}
	if (pid == 0){
		if (dup2(pip[0], STDIN_FILENO) == -1)
			exit(1);
		close(pip[0]);
		close(pip[1]);
		if (execvp(*cmd, cmd) == -1)
			exit(1);
	}
	close(pip[0]);
	return 0;
}

int ft_popen(char **cmd, char *c)
{
	int pip[2];
	pid_t pid = 0;
	int status;
	int fd;

	if (pipe(pip) == -1)
		return -1;
	if (*c == 'r'){
		if (pipe_to_read(pid, pip, cmd) == -1){
			return -1;
		}
		return pip[0];
	}
	if (*c == 'w'){
		if (pipe_to_write(pid, pip, cmd) == -1){
			return -1;
		}
		return pip[1];
	}
	return -1;
}

int main(int argc, char **argv) {
	if (argc != 3)
		return -1;
	char **cmd = malloc(2 * sizeof(char *));
	cmd[0] = argv[1];
	cmd[1] = NULL;
	char *c = argv[2];
	int fd = ft_popen(cmd, c);
	if (fd < 0){
		return 1;
	}
	char buffer[1024];
	int bytes_read;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) 
    	write(1, buffer, bytes_read);    // 	write to stdout
	return 0;
}

// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 		return -1;
// 	char **cmd = malloc(2 * sizeof(char *));
// 	cmd[0] = argv[1];
// 	cmd[1] = NULL;
// 	char c = (char)argv[2];

// 	int fd = ft_popen(cmd, c);
// 	write(1, &fd, 20);
// 	return 0;
// }
