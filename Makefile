# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 13:06:22 by anpollan          #+#    #+#              #
#    Updated: 2025/07/04 11:29:42 by anpollan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= ./libft/libft.a
SRCS 	= main.c \
		  parsing.c \
		  push_swap.c \
		  linked_list.c \
		  linked_list_2.c \
		  push_and_swap.c \
		  rotate.c \
		  memory_and_error.c \
		  sorting.c \
		  update_stack_details.c \
		  count_operations.c \
		  save_operations.c
OBJS	= $(SRCS:%.c=%.o)
HEADER	= push_swap.h
C_FLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c $(HEADER)
	cc $(C_FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME) compile_commands.json
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
