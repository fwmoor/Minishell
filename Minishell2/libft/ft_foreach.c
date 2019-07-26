/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:52:38 by fremoor           #+#    #+#             */
/*   Updated: 2019/05/22 14:55:24 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int len, void (*f)(int))
{
	int i;

	i = 0;
	while (i < len)
	{
		f(tab[i]);
		i++;
	}
}