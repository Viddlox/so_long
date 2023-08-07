# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micheng <micheng@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 02:14:08 by micheng           #+#    #+#              #
#    Updated: 2023/08/07 15:15:21 by micheng          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
FLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address
MLX 		= -lmlx -framework OpenGL -framework AppKit
INCLUDES 	= -Iincludes -Ilibft
RM			= rm -rf
LIBFT		= -Llibft -lft

SRCS = $(wildcard srcs/*.c) $(wildcard gnl/*.c)
OBJ_DIR = obj
OBJ 	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
