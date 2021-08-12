#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"

# include <stdlib.h>

typedef struct s_path
{
	int		pipefd[2];
	char	**mypath;
	char	**cmdarg;
}				t_path;

//path.c
int	ft_is_path(char *str);
int	ft_find_path(char **envp, t_path *path);
#endif
