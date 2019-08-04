/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:23:06 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/04 10:39:42 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				exec_sys(char *com)
{
	int			i;

	i = system(com);
	ft_strdel(&com);
	return (i);
}

int				exec_env(char *com)
{
	int			i;

	i = 0;
	while (g_env[i])
		ft_putendl(g_env[i++]);
	ft_strdel(&com);
	return (1);
}
