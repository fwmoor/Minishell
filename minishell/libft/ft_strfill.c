/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:35:45 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 15:32:20 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char				*ft_getstr_d(t_format *tf)
{
	char			*str;

	if (tf->p_len & 4 || tf->t_form == 'D')
		str = ft_itoa((long)va_arg(*tf->ap, long));
	else if (tf->p_len & 64)
		str = ft_itoa((char)va_arg(*tf->ap, intmax_t));
	else if (tf->p_len & 2)
		str = ft_itoa((short)va_arg(*tf->ap, intmax_t));
	else if (tf->p_len & 8)
		str = ft_itoa(va_arg(*tf->ap, long long));
	else if (tf->p_len & 16)
		str = ft_itoa(va_arg(*tf->ap, intmax_t));
	else if (tf->p_len & 32)
		str = ft_itoa(va_arg(*tf->ap, size_t));
	else
		str = ft_itoa(va_arg(*tf->ap, int));
	return (str);
}

char				*ft_getstr_u(t_format *tf, int base)
{
	char			*str;

	if (tf->p_len & 4 || tf->t_form == 'O' || tf->t_form == 'U')
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned long), base);
	else if (tf->p_len & 2 && !(tf->p_len & 64))
		str = ft_itoa_base_u((unsigned short)va_arg(*tf->ap, unsigned), base);
	else if (tf->p_len & 64)
		str = ft_itoa_base_u((unsigned char)va_arg(*tf->ap, unsigned), base);
	else if (tf->p_len & 8)
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned long long), base);
	else if (tf->p_len & 16)
		str = ft_itoa_base_u(va_arg(*tf->ap, uintmax_t), base);
	else if (tf->p_len & 32)
		str = ft_itoa_base_u(va_arg(*tf->ap, size_t), base);
	else
		str = ft_itoa_base_u(va_arg(*tf->ap, unsigned int), base);
	return (str);
}

char				*ft_getstr_p(t_format *tf)
{
	char			*str;
	long			add;
	unsigned char	*ptr;

	ptr = va_arg(*tf->ap, void *);
	add = (long)ptr;
	str = ft_itoa_base_u(add, 16);
	return (str);
}

int					ft_getstr_all(t_format *tf)
{
	int				i;
	char			*str;

	i = 0;
	if (tf->t_form == 's' || tf->t_form == 'c' || tf->t_form == '%' ||
			tf->t_form == 'C' || tf->t_form == 'S')
	{
		if (tf->t_form == 's' || tf->t_form == 'S')
			str = ft_middle_s(tf);
		else
			str = ft_middle_c(tf);
		i += ft_print_sc(tf, str);
	}
	else if (tf->t_form == 'd' || tf->t_form == 'i' || tf->t_form == 'D')
		i = ft_middle_n(tf);
	else if (tf->t_form == 'o' || tf->t_form == 'u' || tf->t_form == 'U' ||
			tf->t_form == 'O')
		i = ft_middle_u(tf);
	else if (tf->t_form == 'x' || tf->t_form == 'X')
		i = ft_middle_x(tf);
	else if (tf->t_form == 'p')
		i = ft_middle_p(tf);
	return (i);
}
