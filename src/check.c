/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:52:02 by tcosse            #+#    #+#             */
/*   Updated: 2021/08/24 14:52:04 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_is_file(t_path *path, char *argv, int mod)
{
	if (!access(argv, mod))
		return (1);
	return (ft_error(5, path));
}
