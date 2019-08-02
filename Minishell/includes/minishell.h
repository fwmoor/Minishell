/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:47 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/02 15:57:53 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <readline/history.h>
# include <readline/readline.h>

char		**g_env;
void		pop_env(char **env);
int			exec_echo(char *arg);
int			exec_sys(char *com);
int			main(int ac, char **av, char **env);
int			exec_args(char **commands);
int			exec_cd(char *arg);
int			exec_setenv(char *arg);
char		*get_env(char *str);
char		**remove_quotes(char *dirs);
void		get_dir_path();
void		free_her(char **dirs);

#endif
