#include "pipex.h"

int	ft_is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
			&& str[3] == 'H' && str[4] == '=' && str[5] == '=')
		return (1);
	return (0);
}

int	ft_find_path(char **envp, t_path *path)
{
	int		i;
	char	*str;

	i = 0;
	while (envp[i])
	{
		if (ft_is_path(envp[i]))
		{
			str = ft_strdup(envp[i]);
			printf("%s\n",str);
			//path->mypath = ft_split((envp[i]) + 6, ':');
			if (!path->mypath)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}
