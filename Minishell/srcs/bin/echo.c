/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:09:51 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 15:36:04 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			exec_echo(char **print)
{
	int		i;
	int		tru;

	i = 1;
	tru = (ft_strequ(print[i], "-n")) ? 1 : 0;
	i += tru;
	if (!print[1])
	{
		ft_putchar('\n');
		return (1);
	}
	while (print[i])
	{
		ft_putstr(print[i]);
		i++;
		if (print[i])
			ft_putchar(' ');
		if (!tru && !print[i])
			ft_putchar('\n');
	}
	return (1);
}
