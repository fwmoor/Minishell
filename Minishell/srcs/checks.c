/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:35:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 15:13:54 by fremoor          ###   ########.fr       */
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

int				check_bin(char *arg)
{
	if (ft_strequ(arg, "env"))
		return (1);
	if (ft_strnequ(arg, "cd", 2))
		return (1);
	if (ft_strnequ(arg, "echo", 4))
		return (1);
	if (ft_strequ(arg, "setenv"))
		return (1);
	if (ft_strequ(arg, "unsetenv"))
		return (1);
	if (ft_strequ(arg, "exit"))
		return (-1);
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
