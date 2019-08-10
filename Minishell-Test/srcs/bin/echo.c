/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:09:51 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/10 09:36:34 by fwmoor           ###   ########.fr       */
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
	check_nl(con_arr[4]);
	return (1);
}
