/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:47 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/13 10:54:45 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>

# define C_DEF "\033[0m"
# define C_GREEN "\033[1;32m"
# define C_BLUE "\033[1;34m"
# define C_RED "\033[1;31m"
# define C_YELLOW "\033[1;33m"
# define C_CYAN "\033[1;36m"
# define C_MAGENTA "\033[1;35m"

char		*g_arr[4];
char		**g_env;

int			quote(char *str, char c);
int			exec_env(void);
int			exec_help(void);
int			tilda_cd(char *dirs);
int			check_cd(char *dir);
int			exec_cd(char *arg);
int			get_envind(char *key);
int			exec_echo(char **arg);
int			exec_sys(char **coms);
int			exec_setenv(char **arg);
int			exec_unsetenv(char **arg);
int			exec_args(char **commands);
char		**splitthingy(char *com);
int			setenv_var(char *key, char *val);
int			main(int ac, char **av, char **env);
char		quote_thing(char *str);
char		*get_env(char *str);
char		*remove_quotes(char *dirs);
void		get_dir_path();
void		zsh_level(void);
void		check_nl(char *str);
void		error_cd(char *dir);
void		pop_env(char **env);
void		dup_env(char **temp);
void		check_colour(char *str);
void		delfunc_quote(char *str2, char *temp);

#endif
