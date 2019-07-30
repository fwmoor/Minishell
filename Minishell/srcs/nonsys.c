/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonsys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:32 by fremoor           #+#    #+#             */
/*   Updated: 2019/07/30 08:00:54 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exec_cd(char *arg, char **env)
{
	if (!(arg))
		arg = ft_strdup(get_env("HOME=", env));
	chdir(arg);
	free(arg);
	return (1);
}
