# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 20:19:13 by mmoullec          #+#    #+#              #
#    Updated: 2016/03/24 00:49:56 by knzeng-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc -Wall -Werror -Wextra
SRC = ./srcs/*.c
HEAD = ./includes
SRC2 = *.o

$(NAME): all

all:
	@$(CC) -c $(SRC) -I$(HEAD)
	@$(CC) -o $(NAME) $(SRC2)

clean: $(NAME)
	@rm $(SRC2)

fclean: clean
	@rm $(NAME)

re: fclean
	@make all
