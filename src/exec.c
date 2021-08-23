#include "pipex.h"

int	ft_error_pipe(t_path *path, int fd)
{
	close(fd);
	perror(path->shell);
	ft_free_struct(path);
	exit(EXIT_FAILURE);
}

int	ft_child1(t_path *path, int fd, int pipefd[])
{
	close(pipefd[0]);
	if (dup2(fd, STDIN_FILENO) < 0)
		exit(ft_error_pipe(path, fd));
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		exit(ft_error_pipe(path, fd));
	close(fd);
	execve(path->cmd1, path->cmdarg1, path->envp);
	perror(path->shell);
	ft_free_struct(path);
	exit(EXIT_FAILURE);
}

int	ft_child2(t_path *path, int child, int fd, int pipefd[])
{
	int	status;

	status = 0;
	waitpid(child, &status, 0);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		exit(ft_error_pipe(path, fd));
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit(ft_error_pipe(path, fd));
	close(fd);
	close(pipefd[1]);
	execve(path->cmd2, path->cmdarg2, path->envp);
	ft_free_struct(path);
	perror(path->shell);
	exit(EXIT_FAILURE);
}
