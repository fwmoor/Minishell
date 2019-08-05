/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:35:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 15:29:24 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_cd(char *dir)
{
	if (!dir)
		return (2);
	else if ((dir[0] == '/' && ft_strlen(dir) == 1) || (dir[0] == '~' &&
	ft_strlen(dir) == 1))
		return (2);
	else if (dir[0] == '-' && dir[1] == '-' && ft_strlen(dir) == 2)
		return (2);
	else if (dir[0] == '-' && ft_strlen(dir) == 1)
		return (1);
	return (0);
}

int			check_bin(char *arg)
{
	if (ft_strnequ(arg, "env", 3))
		return (1);
	if (ft_strnequ(arg, "cd", 2))
		return (1);
	if (ft_strnequ(arg, "echo", 4))
		return (1);
	if (ft_strnequ(arg, "setenv", 6))
		return (1);
	if (ft_strnequ(arg, "unsetenv", 8))
		return (1);
	if (ft_strnequ(arg, "exit", 4))
		return (-1);
	return (0);
}
