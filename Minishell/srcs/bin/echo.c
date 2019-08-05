/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:09:51 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 17:01:29 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			exec_echo(char **print)
{
	int		i;

	i = 1;
	while (print[i])
	{
		ft_putstr(print[i]);
		if (print[++i] != NULL)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
