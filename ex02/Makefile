# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 23:26:33 by sdell-er          #+#    #+#              #
#    Updated: 2024/11/24 23:49:55 by sdell-er         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://mathworld.wolfram.com/JacobsthalNumber.html
# https://github.com/nerraou/Ford-Johnson-algorithm?tab=readme-ov-file
# ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

NAME = PmergeMe
SRC = main.cpp \
		PmergeMe.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -o $(NAME) $(FLAGS)
	@echo "\e[0;93m[$(NAME)] compiled!\e[0m"

clean:
	@echo > /dev/null

fclean:
	@rm -f $(NAME)
	@echo "\e[0;91m[$(NAME)] deleted!\e[0m"

re: fclean all

.PHONY: all clean fclean re
