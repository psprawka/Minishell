# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 23:21:55 by psprawka          #+#    #+#              #
#    Updated: 2019/09/10 21:31:11 by psprawka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
FLAGS	= -g -Wall -Wextra -Werror
#FLAGS	+=  -fsanitize=address

HEADERS		= includes/
SRCS_DIR	= srcs/
COMMAND		= command/
ENV			= enviroment/
SHELLL		= shelll/

SRCS = $(SRCS_DIR)main.c \
		$(SRCS_DIR)input.c \
		$(SRCS_DIR)tools.c \
		$(SRCS_DIR)$(COMMAND)command_execute.c \
		$(SRCS_DIR)$(COMMAND)command_search.c \
		$(SRCS_DIR)$(COMMAND)handle_commands.c \
		$(SRCS_DIR)$(ENV)env_setup.c \
		$(SRCS_DIR)$(SHELLL)shell_setup.c


OBJS	= $(SRCS:.c=.o)
LIBFT 	= libft/libft.a

BUILD_PRINT = @echo "\r\033[K\033[0;38;5;206m[MINISHELL] \033[38;5;80mBuilding $<"
DONE = @echo "\033[K\033[1;38;5;44mMINISHELL\033[K\033[1;38;5;200m ready to use!\x1B[0m"
CLEAN_O		= @echo "\033[38;5;246mObject files removed! [MINISHELL]\x1B[0m"
CLEAN_A		= @echo "\033[38;5;246mExecutable removed! [MINISHELL]\x1B[0m"

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HEADERS)
		@gcc $(FLAGS) -I $(HEADERS) $(OBJS) $(LIBFT) -lncurses -o $(NAME)
		$(DONE)

$(LIBFT):
	@make -C libft
	@echo ""

%.o: %.c
	$(BUILD_PRINT)
	@gcc -g $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)
	$(CLEAN_O)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	$(CLEAN_A)

re: fclean all