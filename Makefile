# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/20 19:14:20 by kdahl             #+#    #+#              #
#    Updated: 2020/06/23 22:33:34 by kdahl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = /includes/ft_printf.h

FUNCTIONS = ft_printf.c \
				sources/flags_parser.c \
				sources/ft_print.c \
				sources/get_char.c \
				sources/get_digit.c \
				sources/get_flags.c \
				sources/get_hex.c \
				sources/get_percent.c \
				sources/get_pointer.c \
				sources/get_str.c \
				sources/get_unsigned.c \
				sources/get_width.c \
				libft/ft_isdigit.c \
				libft/ft_itoa.c \
				libft/ft_putchar_fd.c \
				libft/ft_strdup.c \
				libft/ft_strlen.c \
				libft/ft_toupper.c \
				libft/ft_bzero.c 
				
CC = gcc -g -O0 -Wall -Wextra -Werror

OBJECTS = ${FUNCTIONS:.c=.o}

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $< -o ${<:.c=.o} -I $(HEADER)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f *.o
	rm -f sources/$(OBJECTS)
	rm -f libft/$(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re