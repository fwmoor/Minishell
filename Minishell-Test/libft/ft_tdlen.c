/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:07:45 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/12 12:08:41 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_tdlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
