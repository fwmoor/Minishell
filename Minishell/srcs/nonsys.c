/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonsys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/26 13:52:03 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exec_cd(char *arg, char **env)
{
	char	*temp;

	if (!(arg))
	{
		temp = get_env("HOME=", env);
		arg = ft_strdup(temp);
		free(temp);
	}
	chdir(arg);
	free(arg);
	return (1);
}
