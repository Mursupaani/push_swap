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

NAME		= push_swap.out
SRCS 		= main.c \
			  push_swap.c
OBJS		= $(SRCS:%.c=%.o)
HEADER		= push_swap.h
CC_FLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CC_FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	cc $(C_FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) compile_commands.json

re: fclean all

.PHONY: all clean fclean re
