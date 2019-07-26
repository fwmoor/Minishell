/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:26:34 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/10 15:32:20 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int				ft_middle_n(t_format *tf)
{
	int			i;
	char		*str;

	i = 0;
	str = ft_getstr_d(tf);
	str = (ft_strcmp(str, "0") == 0 && tf->t_form == 'd' &&
			tf->flags & 32 && tf->prec <= 0) ? ft_strdup("") : str;
	i += ft_print_sn(tf, str);
	free(str);
	return (i);
}

int				ft_middle_u(t_format *tf)
{
	int			i;
	int			base;
	char		*str;

	i = 0;
	base = 10;
	if (tf->t_form == 'o')
		base = 8;
	str = ft_getstr_u(tf, base);
	if (ft_strcmp(str, "0") == 0 && tf->flags & 16 && !(tf->flags & 32))
		tf->flags &= ~(16);
	str = (ft_strcmp(str, "0") == 0 && tf->t_form == 'o' &&
			tf->flags & 32 && tf->prec <= 0) ? ft_strdup("") : str;
	i += ft_print_un(tf, str);
	free(str);
	return (i);
}

int				ft_middle_x(t_format *tf)
{
	int			i;
	char		*str;

	i = 0;
	str = ft_getstr_u(tf, 16);
	if (tf->t_form == 'X')
		str = ft_str_upper(str);
	str = (ft_strcmp(str, "0") == 0 && (tf->t_form == 'x' ||
				tf->t_form == 'X') && tf->flags & 32 &&
			tf->prec <= 0) ? ft_strdup("") : str;
	if (tf->flags & 32)
		tf->flags &= ~(16);
	i += ft_print_ux(tf, str);
	free(str);
	return (i);
}

char			*ft_middle_c(t_format *tf)
{
	char	*str;
	char	arg;

	if (tf->t_form == 'c')
	{
		if (!(arg = (char)va_arg(*tf->ap, int)))
		{
			tf->len++;
			return (ft_strdup("^@"));
		}
		str = ft_strnew(2);
		str[0] = arg;
		return (str);
	}
	else if (tf->t_form == 'C')
	{
		str = ft_strnew(5);
		ft_appendwchar(va_arg(*tf->ap, wchar_t), str);
		return (str);
	}
	else
		return (ft_strdup("%"));
}

char			*ft_middle_s(t_format *tf)
{
	char		*str;
	int			*arr;
	int			*temp;
	long		len;

	if (tf->t_form == 's')
	{
		if (!(str = ft_strdup(va_arg(*tf->ap, char *))))
			return (ft_strdup("(null)"));
		return (str);
	}
	if (!(arr = va_arg(*tf->ap, wchar_t *)))
		return (ft_strdup("(null"));
	temp = arr;
	len = 0;
	while (*temp++)
		len++;
	str = ft_strnew((len + 1) * sizeof(wchar_t));
	while (*arr)
		str = ft_appendwchar(*arr++, str);
	return ((char *)str);
}
