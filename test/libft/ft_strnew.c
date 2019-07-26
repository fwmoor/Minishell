/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:23:34 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 15:26:33 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, (int)'\0', size + 1);
	return (str);
}
