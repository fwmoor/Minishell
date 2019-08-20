/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 21:10:51 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/20 21:43:55 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		exec_help(void)
{
	check_colour(g_arr[0]);
	ft_putendl(" _____ _____ _____ _____ _____ _____ _____ __    __    ");
	ft_putendl("|     |     |   | |     |   __|  |  |   __|  |  |  |   ");
	ft_putendl("| | | |-   -| | | |-   -|__   |     |   __|  |__|  |__ ");
	ft_putendl("|_|_|_|_____|_|___|_____|_____|__|__|_____|_____|_____|");
	ft_putendl("\nGeneral:");
	ft_putendl("To run a program of function enter the name and hit enter\n");
	ft_putendl("Usage");
	ft_putendl("General syntax is as follows: [func][-flag][args]\n");
	ft_putendl("Functions:");
	ft_putendl("All normal functions work on this version of Minishell");
	ft_putendl("This version of Minishell also has a few builtins:");
	ft_putendl("cd, setenv, unsetenv, exit, echo and env\n");
	ft_putendl("Config File:");
	ft_putendl("The look and feel of Minishell can be customized with the");
	ft_putendl("use of the config file. To learn more about the config file");
	ft_putendl("visit my Github (https://www.github.com/fwmoor/minishell)");
	ft_putendl("and look at the README and basic config file\n");
	ft_putendl("Authors:");
	ft_putendl("Fred  - www.github.com/fwmoor");
	ft_putendl("Mike  - www.github.com/mikefmeyer");
	ft_putendl("Nolin - www.github.com/nreddystudent");
	return (1);
}
