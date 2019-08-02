/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/02 14:28:00 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtins(char **com, char **env)
{
	if (ft_strnequ(com[0], "exit", 4))
		return (-1);
	else if (ft_strnequ(com[0], "cd", 2))
		return (exec_cd(com[0], env));
	return (0);
}

int			exec_args(char **coms, char **env)
{
	int		i;
	(void)env;

	i = 0;
	while (coms[i] != NULL)
	{
		if (check_builtins(coms, env) == 1)
			return (1);
		else if (check_builtins(coms, env) == -1)
			return (0);
		else
			exec_sys(coms[i]); 
		i++;
	}
	return (1);
}
