# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarques <amarques@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 15:47:16 by amarques          #+#    #+#              #
#    Updated: 2022/04/07 11:54:26 by amarques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Sources

SRC_FILES	= ft_printf.c ft_printf_utils.c ft_printf_utils2.c

#Binaries

OBJS		= $(SRC_FILES:.c=.o)

#Variables

NAME		= libftprintf.a
CC 			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

#Rules

# %.o:		%.c
# 			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
