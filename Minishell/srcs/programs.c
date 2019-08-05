/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 09:29:18 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtins(char **com)
{
	if (ft_strnequ(com[0], "exit", 4))
		return (-1);
	else if (ft_strnequ(com[0], "cd", 2))
		return (exec_cd(com[0]));
	else if (ft_strnequ(com[0], "setenv", 6))
		return (exec_setenv(com[0]));
	else if (ft_strnequ(com[0], "env", 3))
		return (exec_env(com[0]));
	return (0);
}

int			exec_args(char **coms)
{
	int		i;

	i = 0;
	while (coms[i] != NULL)
	{
		if (check_builtins(coms) == 1)
			return (1);
		else if (check_builtins(coms) == -1)
			return (0);
		else
			exec_sys(coms[i]); 
		i++;
	}
	return (1);
}
