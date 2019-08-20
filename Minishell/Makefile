NAME = minishell

LIBFT_PATH = ./libft/
SRC_PATH = ./srcs/

INCS = ./includes/minishell.h

SRCS =	./srcs/main.c ./srcs/programs.c ./srcs/utils.c ./srcs/system.c \
	./srcs/checks.c ./srcs/bin/cd.c ./srcs/bin/unsetenv.c ./srcs/bin/echo.c \
	./srcs/bin/setenv.c ./srcs/extras.c ./srcs/bin/help.c

FLAGS = -Wall -Werror -Wextra

INC =  -I $(INCS) -I $(LIBFT_PATH)libft.h

SRCO = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(SRCO)
	@make -C $(LIBFT_PATH)
	@gcc -lreadline $(FLAGS) -o $(NAME) $(SRCS) $(LIBFT_PATH)libftprintf.a
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re
