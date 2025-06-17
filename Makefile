# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 13:06:22 by anpollan          #+#    #+#              #
#    Updated: 2025/06/11 13:21:27 by anpollan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
#FIXME: Remove test rule
TEST		= p_test
#FIXME: Remove test rule
LIBFT		= ./libft/libft.a
SRCS 		= main.c \
			  parsing.c \
			  push_swap.c \
			  linked_list.c \
			  linked_list_2.c \
			  printing.c \
			  push_and_swap.c \
			  rotate.c
OBJS		= $(SRCS:%.c=%.o)
HEADER		= push_swap.h
C_FLAGS		= -Wall -Wextra -Werror -g

#FIXME: REMOVE THE CLEAN FROM ALL
all: $(NAME) clean
#FIXME: REMOVE THE CLEAN FROM ALL

#FIXME: Remove test rule
test:
	rm -rf $(TEST)
	make $(TEST)

$(TEST): $(LIBFT)
	cc *.c -g $(LIBFT) -o $(TEST)
#FIXME: Remove test rule

$(NAME): $(OBJS) $(LIBFT)
	cc $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c $(HEADER)
	cc $(C_FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

#FIXME: Remove test rule
fclean: clean
	rm -rf $(NAME) compile_commands.json $(TEST)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
