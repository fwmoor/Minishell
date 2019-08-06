/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:29:36 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/06 15:37:52 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_builtins(char **dirs)
{
	int		i;

	i = 0;
	if (ft_strequ(dirs[0], "exit"))
		i = -1;
	else if (ft_strequ(dirs[0], "cd"))
		i = exec_cd(dirs);
	else if (ft_strequ(dirs[0], "setenv"))
		i = exec_setenv(dirs);
	else if (ft_strequ(dirs[0], "unsetenv"))
		i = exec_unsetenv(dirs);
	else if (ft_strequ(dirs[0], "echo"))
		i = exec_echo(dirs);
	else if (ft_strequ(dirs[0], "env"))
		i = exec_env();
	free_her(dirs);
	return (i);
}

int			exec_args(char **coms)
{
	int		i;
	char	**args;

	i = 0;
	while (coms[i])
	{
		if (check_bin(coms[i]) == 1)
		{
			args = remove_quotes(coms[i]);
			ft_strdel(&coms[i]);
			check_builtins(args);
			i++;
		}
		else if (check_bin(coms[i]) == -1)
		{
			ft_strdel(&coms[i]);
			return (0);
		}
		else
		{
			exec_sys(coms[i]);
			i++;
		}
	}
	return (1);
}
