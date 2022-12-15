# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 16:08:31 by clorcery          #+#    #+#              #
#    Updated: 2022/12/15 18:09:04 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ Colors ~~~~~~~ */
GREEN:="\033[1;32m"                                                                                  
YELLOW:="\033[1;33m"
EOC:="\033[0;0m"
# /* ~~~~~~~~~~~~~~~~~ */

SRCS = mandatory/main.c

OBJS = ${SRCS:.c=.o}

NAME = cub3D

LIBFT = ./libft/libft.a

MLX = ./minilibx/libmlx.a

FLAGS = -Wall -Werror -Wextra -g

FLAGSMLX = -L. -lXext -lX11 -lm

MLX = ./minilibx/libmlx.a

all: ${NAME}

.c.o:
	clang ${FLAGS} -c $< -o $@

${LIBFT}:
		make -C ./libft 

${MLX}:
		make -C ./minilibx

${NAME}: ${OBJS} ${LIBFT} ${MLX}
		clang ${FLAGS} ${OBJS} ${LIBFT} ${MLX} ${FLAGSMLX} -o ${NAME}
		@echo ${GREEN}"compilation complete"${EOC}

clean:
		make -C ./libft/ clean
		make -C ./minilibx clean
		rm -rf ${OBJS}
		@echo ${YELLOW}"clean ok"

fclean: clean
		make -C ${LIBFT} fclean
		rm -rf ${NAME}
		@echo "fclean ok"${EOC}

re: fclean all

.PHONY: all clean fclean re
