/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:40:27 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/20 10:41:17 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_start(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != (s2[i]))
			return (0);
	return (1);
}