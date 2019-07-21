#include "../includes/minishell.h"

int main(){
	char *line;
	system("@cls||clear");
	while (1)
	{
		ft_printf("\033[32;1m$>\033[0m ");
		get_next_line(0, &line);
		if (ft_strcmp(line, "exit") != 0)
			ft_printf("%s\n", line);
		else
			exit (1);
	}
}
