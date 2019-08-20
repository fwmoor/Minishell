/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:35:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/20 15:07:17 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				check_cd(char *dir)
{
	if (!dir)
		return (1);
	else if (dir[0] == '-' && dir[1] == '-' && ft_strlen(dir) == 2)
		return (1);
	else if (dir[0] == '-' && ft_strlen(dir) == 1)
		return (2);
	else if (dir[0] == '~')
		return (3);
	return (0);
}

void			check_colour(char *str)
{
	if (ft_strequ(str, "Blue"))
		ft_putstr(C_BLUE);
	else if (ft_strequ(str, "Green"))
		ft_putstr(C_GREEN);
	else if (ft_strequ(str, "Red"))
		ft_putstr(C_RED);
	else if (ft_strequ(str, "Yellow"))
		ft_putstr(C_YELLOW);
	else if (ft_strequ(str, "Cyan"))
		ft_putstr(C_CYAN);
	else if (ft_strequ(str, "Magenta"))
		ft_putstr(C_MAGENTA);
	else
		ft_putstr(C_DEF);
}

void			check_nl(char *str)
{
	if (ft_strequ(str, "True"))
		ft_putchar('\n');
}

char			check_quote(char *str)
{
	if ((ft_strchr(str, '"')) != NULL)
		return ('"');
	if ((ft_strchr(str, '\'')) != NULL)
		return ('\'');
	return ('\0');
}

int				error_cd(char *dir)
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
	return (1);
}
