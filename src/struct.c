#include "pipex.h"

int	ft_init_struct(char **envp, char **argv, t_path *path)
{
	path->cmdarg1 = 0;
	path->cmdarg2 = 0;
	path->mypath = 0;
	path->cmd1 = 0;
	path->cmd2 = 0;
	path->envp = envp;
	if (!ft_find_path(envp, path))
		return (ft_error(3, path));
	if (!ft_make_cmd(path, argv))
		return (0);
	if (path->cmdarg1 != 0)
		if (!ft_is_exec(path, &path->cmd1, path->cmdarg1[0]))
			return (ft_error(1, path));
	if (path->cmdarg2 != 0)
		if (!ft_is_exec(path, &path->cmd2, path->cmdarg2[0]))
			return (ft_error(2, path));
	return (1);
}

void	ft_free_lst(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

int	ft_free_struct(t_path *path)
{
	if (path->mypath)
		ft_free_lst(path->mypath);
	if (path->cmdarg1)
		ft_free_lst(path->cmdarg1);
	if (path->cmdarg2)
		ft_free_lst(path->cmdarg2);
	if (path->cmd1)
		free(path->cmd1);
	if (path->cmd2)
		free(path->cmd2);
	return (0);
}
