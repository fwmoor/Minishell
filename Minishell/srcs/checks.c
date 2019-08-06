/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:35:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 19:28:40 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				check_cd(char *dir)
{
	if (!dir)
		return (1);
	else if (dir[0] == '~' && ft_strlen(dir) == 1)
		return (1);
	else if (dir[0] == '-' && dir[1] == '-' && ft_strlen(dir) == 2)
		return (1);
	else if (dir[0] == '-' && ft_strlen(dir) == 1)
		return (2);
	else if (dir[0] == '/' && ft_strlen(dir) == 1)
		return (3);
	return (0);
}

void			error_cd(char *dir)
{
	int			i;

	i = 0;
	ft_putstr("cd: no such file or directory: ");
	while (dir[i])
	{
		if (dir[i] == '\n')
		{
			ft_putchar('\\');
			ft_putchar('n');
		}
		else
			ft_putchar(dir[i]);
		i++;
	}
	ft_putchar('\n');
}
