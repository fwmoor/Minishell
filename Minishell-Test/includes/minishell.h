/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:47 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/09 17:04:10 by fwmoor           ###   ########.fr       */
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

char		*e_nl;
char		*m_lines;
char		*c_con;
char		**g_env;
int			get_envind(char *key);
void		check_colour(char *str);
int			exec_env(void);
int			setenv_var(char *key, char *val);
void		check_nl(char *str);
void		error_cd(char *dir);
int			exec_unsetenv(char **arg);
int			check_cd(char *dir);
int			check_bin(char *arg);
void		pop_env(char **env);
int			exec_echo(char **arg);
int			exec_sys(char **coms);
int			main(int ac, char **av, char **env);
int			exec_args(char **commands);
int			exec_cd(char **arg);
int			exec_setenv(char **arg);
char		*get_env(char *str);
char		**remove_quotes(char *dirs);
void		get_dir_path();
void		free_her(char **dirs);

#endif
