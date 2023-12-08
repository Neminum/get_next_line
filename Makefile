# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:06:36 by tsurma            #+#    #+#              #
#    Updated: 2023/11/27 15:10:13 by tsurma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=n
NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar -cvq $(NAME) $^

fclean :
	-rm $(OBJ) $(NAME)

clean :
	-rm $(OBJ)

re : fclean all

.PHONY : clean fclean re all
