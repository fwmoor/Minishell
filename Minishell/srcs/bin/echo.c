/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:09:51 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/20 21:10:43 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			printer(char *str)
{
	int			i;
	int			i1;
	int			i2;
	char		c;

	i = 0;
	i1 = quote(str, '\'');
	i2 = quote(str, '"');
	if (i1 != -1 && i2 != -1)
		c = (i1 < i2) ? '\'' : '"';
	else if (i1 == -1 || i2 == -1)
		c = (i1 == -1) ? '"' : '\'';
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			ft_putchar(str[i++]);
	}
}

int				print_echo(char *print)
{
	int			err;
	char		*ret;
	char		*temp;

	err = 0;
	if (print[0] == '$')
	{
		temp = ft_strdup(print + 1);
		temp = ft_strcat(temp, "=");
		if ((ret = get_env(temp)) != NULL)
		{
			ft_putstr(ret);
			free(ret);
		}
		else
			err = 1;
		free(temp);
	}
	else
		ft_putstr(print);
	return (err);
}

int				exec_echo(char **print)
{
	int			i;
	int			tru;
	int			err;

	i = 1;
	err = 0;
	tru = (ft_strequ(print[i], "-n")) ? 1 : 0;
	i += tru;
	if (!print[1])
		ft_putchar('\n');
	while (print[i])
	{
		err = print_echo(print[i]);
		if (print[i][ft_strlen(print[i]) - 1] != '\n')
			tru = 0;
		i++;
		if (print[i])
			ft_putchar(' ');
		if (!tru && !print[i] && !err)
			ft_putchar('\n');
	}
	return (1);
}
