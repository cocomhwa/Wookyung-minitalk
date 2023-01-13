# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooshin <wooshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:04:37 by wooshin           #+#    #+#              #
#    Updated: 2023/01/14 01:10:08 by wooshin          ###   ########.fr        #
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
SRCS_BC		= client_bonus.c \
			  utils_bonus.c
SRCS_BS		= server_bonus.c

PRINTF_PATH	= ./library/ft_printf

OBJS_C 		= $(SRCS_C:.c=.o)
OBJS_S 		= $(SRCS_S:.c=.o)
OBJS_BC 	= $(SRCS_BC:.c=.o)
OBJS_BS 	= $(SRCS_BS:.c=.o)

all : $(NAME_C) $(NAME_S)

bonus : $(NAME_C) $(NAME_S)

ifeq ($(filter bonus, $(MAKECMDGOALS)), bonus)
$(NAME_C) : $(OBJS_BC)
	$(MAKE) -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) \
		-L$(PRINTF_PATH) -lftprintf \
		$(OBJS_BC) -o $(NAME_C)
$(NAME_S) : $(OBJS_BS)
	$(MAKE) -C $(PRINTF_PATH)
	$(CC) $(CFLAGS) \
		-L$(PRINTF_PATH) -lftprintf \
		$(OBJS_BS) -o $(NAME_S)
else
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
endif

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS_C) $(OBJS_S) $(OBJS_BC) $(OBJS_BS)
	$(MAKE) -C $(PRINTF_PATH) clean
fclean : clean
	$(RM) $(NAME_C) $(NAME_S)
	$(MAKE) -C $(PRINTF_PATH) fclean
re :
	make fclean
	make all

.PHONY: all fclean clean re bonus
