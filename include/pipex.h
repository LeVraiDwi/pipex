/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosse <tcosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:53:13 by tcosse            #+#    #+#             */
/*   Updated: 2021/08/24 14:53:15 by tcosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"
# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define BUFFER_SIZE 30
# define STR_ERR "pipex"

typedef struct s_path
{
	int		pipefd[2];
	char	**envp;
	char	**mypath;
	char	**cmdarg1;
	char	**cmdarg2;
	char	*cmd1;
	char	*cmd2;
	char	*shell;
}				t_path;

//main.c
int		pipex(int fd1, int fd2, t_path *path);
void	ft_clode(int fd1, int fd2);
//path.c
int		ft_is_path(char *str);
int		ft_find_path(char **envp, t_path *path);
//struct.c
int		ft_init_struct(char **envp, char **argv, t_path *path);
int		ft_free_struct(t_path *path);
void	ft_free_lst(char **lst);
//check.c
int		ft_is_exec(t_path *path, char **cmd, char *argv);
int		ft_is_file(t_path *path, char *argv, int mod);
//error.c
int		ft_error(int c_error, t_path *path);
int		ft_find_shell(t_path *path, char **env);
void	ft_error_cmd_nfound(t_path *path, int cmd);
//file.c
int		ft_open_file(int *fd1, int *fd2, t_path *path, char **argv);
//execv.c
int		ft_child1(t_path *path, int fd, int pipefd[]);
int		ft_child2(t_path *path, int child, int fd, int pipefd[]);
int		ft_write(int fd1, int fd2);
int		ft_cmd2_write(t_path *path, int fd, int pipefd[]);
int		ft_error_pipe(t_path *path, int fd);
//cmd.c
int		ft_make_cmd(t_path *path, char **argv);
#endif
