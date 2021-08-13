#include "pipex.h"

int	ft_find_shell(t_path *path, char **env)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'S' && env[i][1] == 'H' && env[i][2] == 'E'
			&& env[i][3] == 'L' && env[i][4] == 'L' && env[i][5] == '=')
		{
			str = env[i];
			i = 0;
			while (str[i])
				i++;
			while (i >= 0 && str[i] != '/')
				i--;
			i++;
			path->shell = ft_strdup(str + i);
			if (!path->shell)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_error_cmd_nfound(t_path *path, int cmd)
{
	write(2, path->shell, ft_strlen(path->shell));
	write(2, ": command not found: ", 21);
	if (cmd == 1)
		write(2, path->cmdarg1[0], ft_strlen(path->cmdarg1[0]));
	else
		write(2, path->cmdarg2[0], ft_strlen(path->cmdarg2[0]));
	write (2, "\n", 1);
}

int	ft_error(int c_error, t_path *path)
{
	if (c_error == 3)
		write (2, "erreur:\nerreur au parsing parsing\n", 34);
	else if (c_error == 1 || c_error == 2)
		ft_error_cmd_nfound(path, c_error);
	else if (c_error == 4)
		write(2, "error:\nla fonction doit avoir 4 argument\n", 42);
	else if (c_error == 5)
		perror(path->shell);
	return (0);
}
