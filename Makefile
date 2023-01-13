# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:04:37 by wooshin           #+#    #+#              #
#    Updated: 2023/01/14 00:21:14 by wooshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C		= client
NAME_S		= server
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCS_C		= client.c \
			  utils.c
SRCS_S		= server.c
PRINTF_PATH	= ./library/ft_printf

OBJS_C 		= $(SRCS_C:.c=.o)
OBJS_S 		= $(SRCS_S:.c=.o)

all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJS_C)
	$(MAKE) -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) \
		-L$(PRINTF_PATH) -lftprintf \
		$(OBJS_C) -o $(NAME_C)

$(NAME_S) : $(OBJS_S)
	$(MAKE) -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) \
		-L$(PRINTF_PATH) -lftprintf \
		$(OBJS_S) -o $(NAME_S)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS_C) $(OBJS_S)
	$(MAKE) -C $(PRINTF_PATH) clean
fclean : clean
	$(RM) $(NAME_C) $(NAME_S)
	$(MAKE) -C $(PRINTF_PATH) fclean
re :
	make fclean
	make all

.PHONY: all fclean clean re
