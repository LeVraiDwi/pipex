/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:52:17 by tcosse            #+#    #+#             */
/*   Updated: 2021/08/24 14:52:18 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_cmd_nfound(t_path *path, int cmd)
{
	if (cmd == 1)
		printf("pipex: command not found: %s\n", path->cmdarg1[0]);
	else
		printf("pipex: command not found: %s\n", path->cmdarg2[0]);
}

int	ft_error(int c_error, t_path *path)
{
	if (c_error == 3)
		printf("pipex: erreur au parsing parsing\n");
	else if (c_error == 1 || c_error == 2)
		ft_error_cmd_nfound(path, c_error);
	else if (c_error == 4)
		printf("pipex: la fonction doit avoir 4 argument\n");
	else if (c_error == 5)
		perror("pipex");
	else if (c_error == 6)
		printf("pipex: aucun fichier ou dossier de ce type\n");
	else if (c_error == 7)
		printf("pipex: command not found: \"\"\n");
	else if (c_error == 8)
		printf("pipex: command not found: \"\"\n");
	else if (c_error == 9)
		printf("pipex: fichier identique\n");
	else if (c_error == 10)
		printf("pipex: impossible d'ouvrir le fichier\n");
	return (0);
}
