/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:50:29 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/13 12:57:03 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		delfunc_quote(char *str2, char *temp)
{
	ft_strdel(&str2);
	ft_strdel(&temp);
}

int			quote(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char		quote_thing(char *str)
{
	char	c;

	if (ft_strchr(str, '"') != NULL)
		c = '"';
	else if (ft_strchr(str, '\'') != NULL)
		c = '\'';
	else
		c = ' ';
	return (c);
}

char		**splitthingy(char *com)
{
	int		i;
	char	*temp;
	char	**args;

	i = 0;
	args = ft_strsplit(com, ' ');
	while (args[i])
	{
		temp = remove_quotes(args[i]);
		free(args[i]);
		args[i++] = temp;
	}
	return (args);
}

char		which_quote(char *str)
{
	int		i;
	int		i1;
	char	c;

	i = quote(str, '\'');
	i1 = quote(str, '"');
	c = '\0';
	if (i != -1 && i1 != -1)
		c = (i < i1) ? '\'' : '"';
	else if (i == -1 || i1 == -1)
		c = (i == -1) ? '"' : '\'';
	return (c);
}
