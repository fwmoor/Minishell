/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/31 12:34:41 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exec_args(char **av, char **env)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "exit") == 0)
		{
			free(av[i]);
			return (0);
		}
		else if (ft_strncmp(av[i], "cd ", 3) == 0)
		{
			exec_cd(av[i], env);
			i++;
		}
		else if (ft_strncmp(av[i], "echo ", 5) == 0)
		{
			exec_echo((av[i]));
			i++;
		}
		else
		{
			free(av[i]);
			system(av[i++]);
			free(av[i]);
		}
	}
	return (1);
}
