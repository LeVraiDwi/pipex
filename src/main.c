#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_path	path;

	i = 0;
	(void)argc;
	(void)argv;
	if (!ft_find_path(envp, &path))
		return (0);
	while (path.mypath[i])
	{
		printf("%s\n", path.mypath[i]);
		i++;	
	}
	return (1);
}
