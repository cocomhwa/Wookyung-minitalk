# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooshin <wooshin@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 02:30:22 by wooshin           #+#    #+#              #
#    Updated: 2022/12/14 04:58:56 by wooshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCS		= check_print.c \
			  ft_printf.c \
			  printer_1.c \
			  printer_2.c \
			  utils.c \
			  utils2.c

OBJS 		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcus $(NAME) $(OBJS)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re :
	make fclean
	make all

.PHONY: all fclean clean re

