# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 11:03:59 by mbryan            #+#    #+#              #
#    Updated: 2015/02/28 10:35:30 by mbryan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

OBJ_NAMES = main.o get_next_line.o

OBJ = $(addprefix srcs/,$(OBJ_NAMES))

PATH_INCLUDES = includes/

INCLUDES_NAME = get_next_line.h libft.h 2048.h

LIB = -lncurses

INCLUDES = $(addprefix $(PATH_INCLUDES),$(INCLUDES_NAME))

FLAGS = -Wall -Wextra -Werror

.PHONY: make, all, $(NAME), libft/libft.a, clean, fclean, re, norme

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
			gcc $(FLAGS) -I $(PATH_INCLUDES) -o $(NAME) $(OBJ) libft/libft.a $(LIB)

$(OBJ): %.o: %.c $(INCLUDES)
			gcc $(FLAGS) -I $(PATH_INCLUDES) -c $< -o $@ 

libft/libft.a :
			make -C libft/

clean :
			@rm -f $(OBJ)
			@echo "clean done"

fclean : clean
			rm -f $(NAME)
			make -C libft/ fclean

re : fclean all
