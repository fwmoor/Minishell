/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:09:51 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 15:20:35 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		print_wo_quote(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (str[i] == '"')
	{
		i++;
		while (str[i] != '"')
			i++;
		ret = ft_strsub(str, 1, ft_strlen(str) - 2);
		ft_putstr(ret);
		ft_strdel(&ret);
	}
	else
		ft_putstr(str);
}

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
	free_her(print);
	return (1);
}
