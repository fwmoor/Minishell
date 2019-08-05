/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:23:06 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/05 17:07:25 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				exec_sys(char *com)
{
	int			i;

	i = system(com);
	//system needs to be execve
	ft_strdel(&com);
	return (i);
}
