/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:28:12 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/11 09:39:09 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int				ft_print_sn(t_format *tf, char *str)
{
	long		len;
	long		max;
	int			i;

	i = 0;
	len = ft_strlen(str);
	if (*str != '-' && (tf->flags & 4 || tf->flags & 2) && ++i)
		tf->len > 0 ? tf->len-- : tf->len;
	if (*str == '-')
		tf->prec++;
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	if (!(tf->flags & 8) & !(tf->flags & 1))
		while (tf->len-- > max)
		{
			ft_putchar(' ');
			i++;
		}
	if (*str != '-' && (tf->flags & 4))
		ft_putchar('+');
	else if (*str != '-' && (tf->flags & 2))
		ft_putchar(' ');
	return (i + ft_after(tf, len, str));
}

int				ft_print_un(t_format *tf, char *str)
{
	int		i;
	long	len;
	long	max;

	i = 0;
	len = ft_strlen(str);
	if (tf->flags & 16 && (tf->t_form == 'o' || tf->t_form == 'O'))
		tf->len > 0 ? tf->len-- && i++ : i++;
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	if (!(tf->flags & 8) & !(tf->flags & 1))
		while (tf->len-- > max)
		{
			ft_putchar(' ');
			i++;
		}
	if (tf->flags & 16 && tf->t_form == 'o')
		ft_putchar('0');
	return (i + ft_after(tf, len, str));
}

int				ft_print_ux(t_format *tf, char *str)
{
	int		i;
	long	len;
	long	max;

	i = 0;
	len = ft_strlen(str);
	if (tf->flags & 16 && ft_strcmp(str, "0") != 0)
	{
		tf->len-- > 0 ? tf->len-- && i++ : i++;
		i++;
	}
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	if (!(tf->flags & 8) & !(tf->flags & 1))
		while (tf->len-- > max)
		{
			ft_putchar(' ');
			i++;
		}
	if (tf->flags & 16 && tf->t_form == 'x' && ft_strcmp(str, "0") != 0)
		ft_putstr("0x");
	else if (tf->flags & 16 && tf->t_form == 'X' && ft_strcmp(str, "0") != 0)
		ft_putstr("0X");
	return (i + ft_after(tf, len, str));
}

int				ft_print_up(t_format *tf, char *str)
{
	int		i;
	long	len;
	long	max;

	i = 0;
	len = ft_strlen(str);
	tf->len -= 2;
	max = (tf->prec > len && (tf->prec != 0)) ? tf->prec : len;
	if (!(tf->flags & 8) & !(tf->flags & 1))
		while (tf->len-- > max)
		{
			ft_putchar(' ');
			i++;
		}
	ft_putstr("0x");
	i += 2;
	return (i + ft_after(tf, len, str));
}

int				ft_print_sc(t_format *tf, char *str)
{
	int		i;
	int		len;
	int		min;

	i = 0;
	len = ft_strlen(str);
	if (tf->prec < 0 || tf->t_form == 'c' || tf->t_form == '%')
		tf->prec = len;
	min = (len > tf->prec && (tf->flags & 32)) ? tf->prec : len;
	if (!(tf->flags & 8))
		while (tf->len-- > min)
		{
			ft_putchar(' ');
			i++;
		}
	write(1, str, min);
	i += (tf->t_form == 'c' && len == 2) ? min - 1 : min;
	if (tf->flags & 8)
		while (tf->len-- > min)
		{
			ft_putchar(' ');
			i++;
		}
	free(str);
	return (i);
}
