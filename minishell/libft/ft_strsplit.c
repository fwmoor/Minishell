/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:34:20 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/26 09:25:10 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/*
** Word_len gets the length of the word. It also skips over 1 or multiple
** chars. It then sends back the length of the word to ft_strsplit
*/

static int	word_len(char const *str, char c)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (*str)
	{
		if (temp == 1 && *str == c)
			temp = 0;
		if (temp == 0 && *str != c)
		{
			temp = 1;
			i++;
		}
		str++;
	}
	return (i);
}

/*
** ft_strsplit first gets the length of the words and then mallocs enough
** space for it in the array. After the malloc, the while loop runs thourgh
** the const char and inserts char for char unless its a bad char
** at the end it returns the array made within ft_strsplit
*/

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**ret;

	len = word_len(s, c);
	if (!(ret = (char **)malloc((sizeof(char *)) * (len + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < len)
	{
		k = 0;
		if (!(ret[j] = ft_strnew(word_len(&s[i], c) + 1)))
			ret[j] = NULL;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			ret[j][k++] = s[i++];
		ret[j][k] = '\0';
	}
	ret[j] = NULL;
	return (ret);
}
