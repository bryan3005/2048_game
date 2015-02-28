# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 11:03:59 by mbryan            #+#    #+#              #
#    Updated: 2015/02/28 20:14:25 by ncolliau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

OBJ_NAMES = main.o move_left.o move_right.o move_down.o move_up.o print_map.o \
			check_win_loss.o

OBJ = $(addprefix srcs/,$(OBJ_NAMES))

PATH_INCLUDES = includes/

INCLUDES_NAME = game_2048.h

LIB = -lncurses

INCLUDES = $(addprefix $(PATH_INCLUDES),$(INCLUDES_NAME))

FLAGS = -Wall -Wextra -Werror

.PHONY: make, all, $(NAME), libft/libft.a, clean, fclean, re, norme

all : $(NAME)

$(NAME) : $(OBJ)
			gcc $(FLAGS) -I $(PATH_INCLUDES) -o $(NAME) $(OBJ) $(LIB)

$(OBJ): %.o: %.c $(INCLUDES)
			gcc $(FLAGS) -I $(PATH_INCLUDES) -c $< -o $@

clean :
			@rm -f $(OBJ)
			@echo "clean done"

fclean : clean
			rm -f $(NAME)

re : fclean all
