#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_path	path;

	i = 0;
	if (argc != 5)
		return (ft_error(4, &path));
	if (!ft_init_struct(envp, argv, &path))
		return (ft_free_struct(&path));
	while (path.mypath[i])
	{
		printf("%s\n", path.mypath[i]);
		i++;
	}
	printf("%s\n", path.cmd1);
	printf("%s\n", path.cmd2);
	ft_free_struct(&path);
	return (1);
}
