# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolim <dolim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 10:34:31 by brbixby           #+#    #+#              #
#    Updated: 2018/08/12 17:06:51 by dolim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME = libft.a
LSRC = libft.c
LHEADER = libft.h

NAME = colle-2
SRC = colle_3.c colle_2.c
HEADER = colle_3.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) -I=$(LHEADER) $(LSRC)
	ar rc $(LNAME) libft.o
	ranlib $(LNAME)
	gcc $(FLAGS) -I=$(HEADER) -o $(NAME) $(SRC) $(LNAME)
	gcc $(FLAGS) -o colle-00 ./rush/colle_00.c ./rush/ft_putchar.c ./rush/ft_atoi.c ./rush/main.c
	gcc $(FLAGS) -o colle-01 ./rush/colle_01.c ./rush/ft_putchar.c ./rush/ft_atoi.c ./rush/main.c
	gcc $(FLAGS) -o colle-02 ./rush/colle_02.c ./rush/ft_putchar.c ./rush/ft_atoi.c ./rush/main.c
	gcc $(FLAGS) -o colle-03 ./rush/colle_03.c ./rush/ft_putchar.c ./rush/ft_atoi.c ./rush/main.c
	gcc $(FLAGS) -o colle-04 ./rush/colle_04.c ./rush/ft_putchar.c ./rush/ft_atoi.c ./rush/main.c

clean:
	/bin/rm -f libft.o

fclean: clean
	/bin/rm -f $(NAME) $(LNAME) colle-00 colle-01 colle-02 colle-03 colle-04

re: fclean all
