/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 08:56:13 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exec_cd(char *arg, char **env)
{
	char	*ret;
	char	*home;

	if (ft_strchr(arg, ' ') == NULL)
	{
		home = get_env("HOME=", env);
		ret = ft_strdup(home);
		free(home);
	}
	else
		ret = ft_strdup(ft_strchr(arg, ' ') + 1);
	chdir(ret);
	free(ret);
	free(arg);
	return (1);
}
