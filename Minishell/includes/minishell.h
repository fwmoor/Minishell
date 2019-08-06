/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:47 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 14:31:11 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>

# define C_DEFAULT "\033[0m"
# define C_GREEN "\033[1;32m"
# define C_BLUE "\033[1;34m"

char		**g_env;
int			get_envind(char *key);
int			exec_env(void);
int			setenv_var(char *key, char *val);
void		error_cd(char *dir);
int			exec_unsetenv(char **arg);
int			check_cd(char *dir);
int			check_bin(char *arg);
void		pop_env(char **env);
int			exec_echo(char **arg);
int			exec_sys(char *com);
int			main(int ac, char **av, char **env);
int			exec_args(char **commands);
int			exec_cd(char **arg);
int			exec_setenv(char **arg);
char		*get_env(char *str);
char		**remove_quotes(char *dirs);
void		get_dir_path();
void		free_her(char **dirs);

#endif
