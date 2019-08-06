/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 19:27:42 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtins(char *com)
{
	int		i;
	char	**coms;

	i = 0;
	coms = remove_quotes(com);
	if (ft_strequ(coms[0], "exit"))
		i = -1;
	else if (ft_strequ(coms[0], "cd"))
		i = exec_cd(coms);
	else if (ft_strequ(coms[0], "setenv"))
		i = exec_setenv(coms);
	else if (ft_strequ(coms[0], "unsetenv"))
		i = exec_unsetenv(coms);
	else if (ft_strequ(coms[0], "echo"))
		i = exec_echo(coms);
	else if (ft_strequ(coms[0], "env"))
		i = exec_env();
	free_her(coms);
	return (i);
}

int			exec_args(char **coms)
{
	int		i;

	i = 0;
	while (coms[i])
	{
		if (check_builtins(coms[i]) == 1)
			ft_strdel(&coms[i]);
		else if (check_builtins(coms[i]) == -1)
		{
			ft_strdel(&coms[i]);
			return (0);
		}
		else
			exec_sys(coms[i]);
		i++;
	}
	return (1);
}
