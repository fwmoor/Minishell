/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:19:03 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 15:32:20 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int				ft_middle_p(t_format *tf)
{
	int			i;
	char		*str;

	i = 0;
	str = ft_getstr_p(tf);
	i += ft_print_up(tf, str);
	free(str);
	return (i);
}

char			*ft_appendwchar(wchar_t wc, char *str)
{
	const char *ret = str;

	str += ft_strlen(str);
	if (wc <= 0x7F)
		*str = (unsigned char)wc;
	else if (wc <= 0x7FF)
	{
		*str++ = 0xC0 | (wc >> 6 & 0x1F);
		*str++ = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0xFFFF)
	{
		*str++ = 0xE0 | (wc >> 12 & 0xF);
		*str++ = 0x80 | (wc >> 6 & 0x3F);
		*str++ = 0x80 | (wc & 0x3F);
	}
	else if (wc <= 0x10FFFF)
	{
		*str++ = 0xF0 | (wc >> 18 & 0x7);
		*str++ = 0x80 | (wc >> 12 & 0x3F);
		*str++ = 0x80 | (wc >> 6 & 0x3F);
		*str++ = 0x80 | (wc & 0x3F);
	}
	return ((char *)ret);
}
