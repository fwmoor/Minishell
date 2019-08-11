/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:09:51 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/11 08:00:30 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			exec_help(void)
{
	ft_printf(C_GREEN"\n\nMINISHELL - HELP\n\n");
	ft_printf("BASICS:\nAll normal commands work on our minishell.\n");
	ft_printf("Bins we've added are cd, echo, setenv, unsetenv and env.\n");
	ft_printf("\n\nCONFIG:\n");
	ft_printf("Our config file supports custom colours for minishell,\n");
	ft_printf("path visiblity and multiple line displays.\n");
	ft_printf("Add a folder called 'config' with a file called config in it.");
	ft_printf("\nAdd the following to change the look and feel:\n");
	ft_printf("COLOUR=x - Replace x with and normal colour name\n");
	ft_printf("PATH=x - Replace x with 'True' if you want to display the path");
	ft_printf(".\nENDLN=x - Replace x with 'True' if you want the program to");
	ft_printf("end on a new line.\n");
	ft_printf("MULTILINE=x - Replace x with 'True' if you want your prompt");
	ft_printf("to be split into two lines.\n"C_DEF);
	return (1);	
}

int			exec_echo(char **print)
{
	int		i;
	int		tru;

	i = 1;
	tru = (ft_strequ(print[i], "-n")) ? 1 : 0;
	i += tru;
	if (!print[1])
	{
		ft_putchar('\n');
		return (1);
	}
	while (print[i])
	{
		ft_putstr(print[i]);
		if (print[i][ft_strlen(print[i]) - 1] != '\n')
			tru = 0;
		i++;
		if (print[i])
			ft_putchar(' ');
		if (!tru && !print[i])
			ft_putchar('\n');
	}
	return (1);
}
