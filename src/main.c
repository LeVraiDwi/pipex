#include "pipex.h"

void	ft_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

int	pipex(int fd1, int fd2, t_path *path)
{
	int	status;
	int	child1;
	int	child2;
	int	pipefd[2];

	status = 0;
	if (pipe(pipefd) < 0)
		return (ft_error(5, path));
	child1 = fork();
	if (child1 < 0)
		return (ft_error(5, path));
	else if (child1 == 0)
		ft_child1(path, fd1, pipefd);
	child2 = fork();
	if (child2 < 0)
		return (ft_error(5, path));
	else if (child2 == 0)
		ft_child2(path, child1, fd2, pipefd);
	ft_close(pipefd[0], pipefd[1]);
	if (waitpid(-1, &status, 0) < 0)
		exit(EXIT_FAILURE);
	if (waitpid(-1, &status, 0) < 0)
		exit(EXIT_FAILURE);
	ft_free_struct(path);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_path	path;
	int		fd1;
	int		fd2;

	if (argc != 5)
		return (ft_error(4, &path));
	if (*argv[4] == 0 && *argv[1] == 0)
		return (ft_error(6, &path));
	if (!ft_init_struct(envp, argv, &path))
		return (ft_free_struct(&path));
	if (!ft_open_file(&fd1, &fd2, &path, argv))
		return (ft_free_struct(&path));
	if (!pipex(fd1, fd2, &path))
		return (ft_free_struct(&path));
	ft_free_struct(&path);
	return (1);
}
