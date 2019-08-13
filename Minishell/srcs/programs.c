/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/13 12:57:22 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtins(char **coms)
{
	if (ft_strequ(coms[0], "exit"))
		return (-1);
	else if (ft_strequ(coms[0], "cd"))
		return (exec_cd(coms[1]));
	else if (ft_strequ(coms[0], "setenv"))
		return (exec_setenv(coms));
	else if (ft_strequ(coms[0], "unsetenv"))
		return (exec_unsetenv(coms));
	else if (ft_strequ(coms[0], "echo"))
		return (exec_echo(coms));
	else if (ft_strequ(coms[0], "env"))
		return (exec_env());
	else if (ft_strequ(coms[0], "help"))
		return (exec_help());
	else
		return (0);
}

int			exec_args(char **coms)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	while (coms[i])
	{
		args = splitthingy(coms[i]);
		j = check_builtins(args);
		if (j == -1)
		{
			free_her(args);
			ft_strdel(&coms[i]);
			return (0);
		}
		else if (j == 0)
			exec_sys(args);
		free_her(args);
		i++;
	}
	free_her(coms);
	return (1);
}
