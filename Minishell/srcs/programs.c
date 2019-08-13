/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/13 14:37:18 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtins(char *com)
{
	int		i;
	char	**coms;

	coms = splitthingy(com);
	i = 0;
	if (ft_strequ(coms[0], "exit"))
		i = -1;
	else if (ft_strequ(coms[0], "cd"))
		i = exec_cd(coms[1]);
	else if (ft_strequ(coms[0], "setenv"))
		i = exec_setenv(coms);
	else if (ft_strequ(coms[0], "unsetenv"))
		i = exec_unsetenv(coms);
	else if (ft_strequ(coms[0], "echo"))
		i = exec_echo(coms);
	else if (ft_strequ(coms[0], "env"))
		i = exec_env();
	else if (ft_strequ(coms[0], "help"))
		i = exec_help();
	free_her(coms);
	return (i);
}

int			exec_args(char **coms, char c)
{
	int		i;
	int		j;

	i = 0;
	while (coms[i])
	{
		j = check_builtins(coms[i]);
		if (j == -1)
		{
			ft_strdel(&coms[i]);
			return (0);
		}
		else if (j == 0)
			exec_sys(coms[i], c);
		i++;
	}
	free_her(coms);
	return (1);
}
