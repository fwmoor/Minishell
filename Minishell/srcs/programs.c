/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/02 09:22:47 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtins(char **com)
{
	if (ft_strnequ(com[0], "exit", 4))
		return (-1);
	return (0);
}

int			exec_args(char **coms, char **env)
{
	int		i;
	(void)env;

	i = 0;
	while (coms[i])
	{
		if (check_builtins(coms) == -1)
			return (0);
		i++;
	}
	return (1);
}
