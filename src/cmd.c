#include "pipex.h"

int	ft_make_cmd(t_path *path, char **argv)
{
	if (argv[2] && *argv[2])
	{
		path->cmdarg1 = ft_split(argv[2], ' ');
		if (!path->cmdarg1)
			return (ft_error(3, path));
	}
	else
		path->cmdarg1 = 0;
	if (argv[3] && *argv[3])
	{
		path->cmdarg2 = ft_split(argv[3], ' ');
		if (!path->cmdarg2)
			return (ft_error(3, path));
	}
	else
		path->cmdarg2 = 0;
	return (1);
}