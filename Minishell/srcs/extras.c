/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:50:29 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/12 13:46:40 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		delfunc_quote(char *str2, char *temp)
{
	ft_strdel(&str2);
	ft_strdel(&temp);
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
