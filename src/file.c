/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:52:31 by tcosse            #+#    #+#             */
/*   Updated: 2021/08/24 15:00:42 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strisstr(char *s, char *str)
{
	int	i;

	i = 0;
	if (!s || !str)
		return (0);
	if (!*s && !*str)
		return (1);
	if (ft_strlen(s) != ft_strlen(str))
		return (0);
	while (s[i] && str[i])
	{
		if (s[i] != str[i])
			return (0);
		i++;
	}
	if (s[i] != str[i])
		return (0);
	return (1);
}

int	ft_open_file(int *fd1, int *fd2, t_path *path, char **argv)
{
	if (ft_strisstr(argv[1], argv[4]))
		return (ft_error(9, path));
	if (!ft_is_file(path, argv[1], F_OK | R_OK))
		return (ft_error(10, path));
	*fd1 = open(argv[1], O_RDONLY);
	if (!*fd1)
		return (ft_error(10, path));
	if (!access(argv[4], F_OK))
		if (!ft_is_file(path, argv[4], F_OK | R_OK | W_OK))
			return (ft_error(10, path));
	*fd2 = open(argv[4], O_CREAT | O_TRUNC | O_RDWR,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (!*fd2)
		return (ft_error(10, path));
	return (1);
}
