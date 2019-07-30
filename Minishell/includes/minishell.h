/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:47 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 20:10:48 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <readline/history.h>
# include <readline/readline.h>

int			exec_echo(char *arg);
int			main(int ac, char **av, char **env);
int			exec_args(char **commands, char **env);
int			exec_cd(char *arg, char **env);
char		*get_env(char *str, char **env);
char		*get_dir_path(char **env);
void		free_her(char **dirs);

#endif
