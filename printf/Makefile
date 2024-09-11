# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolit-go <lolit-go@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 15:54:49 by lolit-go          #+#    #+#              #
#    Updated: 2024/09/12 00:38:16 by lolit-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = /usr/bin/gcc
CFLAGS = -Wall -Werror -Wextra

MAIN = ft_printf.c

MAIN_OBJ = ${MAIN:.c=.o}

FUNC_SRCS = ft_putchar.c \
			ft_putstr.c \
			ft_itoa.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strdup.c \
			ft_mem_addr.c \
			ft_uitoa.c

FUNC_OBJS = ${FUNC_SRCS:.c=.o}

FUNC_DIR = utils

FUNC_OBJS_PATHS = $(addprefix $(FUNC_DIR)/, $(FUNC_OBJS))


all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(MAIN_OBJ) $(FUNC_OBJS_PATHS)
	/usr/bin/ar -rcs $(NAME) $(MAIN_OBJ) $(FUNC_OBJS_PATHS)

clean:
	/usr/bin/rm -f ${MAIN_OBJ} $(FUNC_OBJS_PATHS)

fclean: clean
	/usr/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re