# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 15:54:49 by lolit-go          #+#    #+#              #
#    Updated: 2024/09/07 16:14:02 by lolit-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = /usr/bin/gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}


all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	/usr/bin/ar -rcs $(NAME) $(OBJS)

clean:
	/usr/bin/rm -f ${OBJS}

fclean: clean
	/usr/bin/rm -f ${NAME}

re:

.PHONY: all .c.o bonus clean fclean re