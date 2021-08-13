#include "pipex.h"

int	ft_child1(t_path *path, int fd, int pipefd[])
{
	close(pipefd[0]);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
	{
		close(fd);
		perror(path->shell);
		exit(EXIT_FAILURE);
	}
	close(fd);
	execve(path->cmd1, path->cmdarg1, path->envp);
	perror(path->shell);
	exit(EXIT_FAILURE);
}

int	ft_child2(t_path *path, int child, int fd, int pipefd[])
{
	int	status;

	status = 0;
	waitpid(child, &status, 0);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
	{
		close(fd);
		perror(path->shell);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		close(fd);
		perror(path->shell);
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	close(fd);
	execve(path->cmd2, path->cmdarg2, path->envp);
	perror(path->shell);
	exit(EXIT_FAILURE);
}
