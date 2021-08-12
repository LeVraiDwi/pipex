#include "pipex.h"

int	ft_is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
			&& str[3] == 'H' && str[4] == '=')
		return (1);
	return (0);
}

int	ft_format_path(t_path *path)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path->mypath[i])
	{
		tmp = path->mypath[i];
		path->mypath[i] = ft_strjoin(tmp, "/");
		if (!path->mypath)
			return (0);
		i++;
		free(tmp);
	}
	return (1);
}

int	ft_find_path(char **envp, t_path *path)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_is_path(envp[i]))
		{
			path->mypath = ft_split((envp[i]) + 5, ':');
			if (!path->mypath)
				return (0);
			if (!ft_format_path(path))
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}
