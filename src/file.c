#include "pipex.h"

int	ft_open_file(int *fd1, int *fd2, t_path *path, char **argv)
{
	if (!ft_is_file(path, argv[1], F_OK | R_OK))
		return (0);
	*fd1 = open(argv[1], O_RDONLY);
	if (!*fd1)
		return (0);
	*fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
	if (!*fd2)
		return (0);
	return (1);
}
