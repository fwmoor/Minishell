/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:33:26 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 15:26:33 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)s + i);
	while (i)
	{
		i--;
		if (c == s[i])
			return ((char *)s + i);
	}
	return (NULL);
}
