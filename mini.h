/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:05:42 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/19 19:00:27 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include <stdio.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h> 
# include <unistd.h>
# include <errno.h>
# include <curses.h>
# include <term.h>
# include <termcap.h>
# include <signal.h>

# define PATH "PATH="
# define RED1	1
# define RED2	2
# define RED3	3

typedef struct s_minilist
{
	int					index;
	char				**cmd;
	int					type;
	char				**file_name;
	char				*value;
	int					fd[2];

	struct s_minilist	*next;
	struct s_minilist	*prev;
}				t_minilist;

typedef struct s_data
{
	t_minilist	*lst;
	bool		f;
	int			flag;
	int			pipo;
	int			pipi;
	int			pid;
	int			parent;
	int			ne;
	int			last;
	char		**env;
	char		*old_pwd;
	int			res;
}				t_data;

int			search_123(char **env, char *cmd);
char		*open_red(char **str, int c, int *i, t_minilist *minilist);
void		pars_line(char **env);
char		*quotation_marks(char *str, t_data *data);
char		*search_env(char *str, int j, int *i, t_data *data);
int			ifkey(char c);
t_minilist	*list_create(t_minilist **minilist, char *str, char **env);
t_minilist	*standart_cmd(char *str, int type, char **env);
t_minilist	*ft_lstnew1(char *str, int type, char **env);
void		ft_lstadd_back1(t_minilist **lst, t_minilist *new);
char		*redirect_pars(char *str, int c, t_minilist *minilist);
char		**pars_command(char *str, char **env);
void		pipe_mini(t_data *data);
char		*duo_right_redirect(char *str, int i, int c, int *fd);
char		**ft_cd(t_data *data, char **env);
char		*find_file_name(char *str, int i);
char		*left_redirect2(char *str, int i, int c, int *fd);
void		ft_env(char **env);
char		**ft_export(t_minilist *list, t_data *data);
char		**copy_mas(char **env);
int			count_str_env(char **env);
char		*change_env(char *str, int *i, char **env);
void		sort_env(char **env);
void		export_printf(char **env);
void		sign_d(void);
int			correct_check(char *str);
char		**ft_unset(t_minilist *list, char **env);
int			search_rovno(char *cmd);
void		free_string1(char **u);
void		sigin_c(int sig);
void		ft_echo(t_minilist *lst);
char		*ft_strjoin1(char *s1, char *s2);
int			preparser(char *str);
void		commands(t_data *data, t_minilist *lst);
int			commands2(t_data *data, t_minilist *minilist);
int			ft_check(char *tmp);
int			ft_pwd(void);
void		data_init(t_data *data);
char		**change_(char **env, t_minilist *lst);
void		execve_red(t_minilist *list);
int			gnl_light(char **str);
char		**ft_export_help(t_minilist *list,
				t_data *data, int a, char **env3);
char		*pars_help(char *str, int i, char **env);
char		*dollar(char *str, int *i, t_data *data);
char		*quotation_marks1(char *str, int *i, int m);
char		*slesh(char *str, int *i);
char		*quotation_marks2(char *str, int *i, t_data *data, int m);
void		ft_error(char *er);
int			error1(const int errnum);
void		ft_free_str_arr(char ***arr);
void		path_search_ultra_extra(char **program, char *tmp);
void		ft_free(char **str);
void		ft_free_data(t_minilist *lst);
int			*ft_dup(void);
void		ft_dup1(int *fd);
char		*ft_strchr1(const char *s, int c);
int			ft_lstsize1(t_minilist *lst);
void		pipe_help(t_data *data);
void		free_1(char *str1, char *str2);
char		*gl_hf(char *str, int j, int *i);
void		free_dont_cor(t_minilist *list, int i);

#endif
