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
	char	**cmdarg1;
	char	**cmdarg2;
	char	*cmd1;
	char	*cmd2;
	char	*shell;
}				t_path;

//path.c
int		ft_is_path(char *str);
int		ft_find_path(char **envp, t_path *path);
//struct.c
int		ft_init_struct(char **envp, char **argv, t_path *path);
int		ft_free_struct(t_path *path);
void	ft_free_lst(char **lst);
//check.c
int	ft_is_exec(t_path *path, char **cmd, char *argv);
//error.c
int		ft_error(int c_error, t_path *path);
int		ft_find_shell(t_path *path,char **env);
#endif
