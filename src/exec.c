#include "pipex.h"

int	ft_write(int fd1, int fd2)
{
	int		l;
	char	buf[BUFFER_SIZE];

	l = read(fd1, buf, BUFFER_SIZE);
	if (l == -1)
		return (0);
	while (l == BUFFER_SIZE)
	{
		l = write(fd2, buf, BUFFER_SIZE);
		if (l == -1)
			return (0);
		l = read(fd1, buf, BUFFER_SIZE);
		if (l == -1)
			return (0);
	}
	if (l > 0)
	{
		l = write(fd2, buf, l);
		if (l == -1)
			return (0);
	}
	return (1);
}

int	ft_child1(t_path *path, int fd, int pipefd[])
{
	close(pipefd[0]);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		close(fd);
		perror(path->shell);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
	{
		close(fd);
		perror(path->shell);
		exit(EXIT_FAILURE);
	}
	if (path->cmdarg1)
	{
		close(fd);
		execve(path->cmd1, path->cmdarg1, path->envp);
		perror(path->shell);
		exit(EXIT_FAILURE);
	}
	else
		if (!ft_write(fd, pipefd[1]))
			exit(EXIT_FAILURE);
	close(fd);
	exit(EXIT_SUCCESS);
}

int	ft_cmd2_write(t_path *path, int fd, int pipefd[])
{
	(void)pipefd;
	if (path->cmdarg2)
	{
		close(fd);
		execve(path->cmd2, path->cmdarg2, path->envp);
		perror(path->shell);
		return (0);
	}
	else
		if (!ft_write(STDIN_FILENO, STDOUT_FILENO))
			return (0);
	return (1);
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
	if (!ft_cmd2_write(path, fd, pipefd))
		exit(EXIT_FAILURE);
	close(fd);
	exit(EXIT_SUCCESS);
}
