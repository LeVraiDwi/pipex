#include "pipex.h"

int	ft_is_exec(t_path *path, char **cmd, char *argv)
{
	int		i;
	char	*pathcmd;

	i = 0;
	while (path->mypath[i])
	{
		pathcmd = ft_strjoin(path->mypath[i], argv);
		if (!pathcmd)
			return (0);
		if (!access(pathcmd, X_OK | F_OK))
		{
			*cmd = pathcmd;
			return (1);
		}
		free(pathcmd);
		i++;
	}
	return (0);
}
