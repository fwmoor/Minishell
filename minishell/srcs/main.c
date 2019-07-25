#include "../includes/minishell.h"

int coms(char **commands)
{
	int i = 0;
	while (commands[i])
		system(commands[i++]);
	return (i);
}

int main()
{
	char *line;
	char **commands;
	system("clear");
	while (1)
	{
		ft_printf("\033[32;1m$>\033[0m ");
		get_next_line(0, &line);
		commands = ft_strsplit(line, ' ');
		coms(commands);
	}
}
