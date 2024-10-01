# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 15:13:01 by lolit-go          #+#    #+#              #
#    Updated: 2024/09/25 19:21:43 by lolit-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = /usr/bin/gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	get_next_line.c \
		get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	/usr/bin/ar -rcs $(NAME) $(OBJS)

clean:
	/usr/bin/rm -f ${OBJS}

fclean: clean
	/usr/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re