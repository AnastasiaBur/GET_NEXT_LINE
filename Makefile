# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsanford <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 13:44:40 by jsanford          #+#    #+#              #
#    Updated: 2019/01/09 17:56:02 by jsanford         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = success
SRC = main.c \
      get_next_line.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): 
	gcc -o $(NAME) $(FLAGS) $(SRC) -I ./libft -I. -L ./libft -lft
clean:
	rm -f *.exe *.out
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
