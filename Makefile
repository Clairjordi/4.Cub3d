# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorcery <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 16:08:31 by clorcery          #+#    #+#              #
#    Updated: 2022/12/17 19:18:09 by clorcery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ Colors ~~~~~~~ */
GREEN:="\033[1;32m"                                                                                  
YELLOW:="\033[1;33m"
EOC:="\033[0;0m"
# /* ~~~~~~~~~~~~~~~~~ */

SRCS = mandatory/main.c \
	   mandatory/check.c \
	   mandatory/utils.c \
	   mandatory/init.c \
	   mandatory/map.c \
	   mandatory/exit.c \
	   mandatory/recup_map.c \
	   mandatory/recup_identifier.c \
	   mandatory/recup_identifier_bis.c

OBJS = ${SRCS:.c=.o}

NAME = cub3D

LIBFT = ./libft/libft.a

MLX = ./minilibx/libmlx.a

FLAGS = -Wall -Werror -Wextra -g

FLAGSMLX = -L. -lXext -lX11 -lm

MLX = ./minilibx/libmlx.a

all: ${NAME}

.c.o:
	@clang ${FLAGS} -c $< -o $@

${LIBFT}:
		@make -C ./libft --no-print-directory

${MLX}:
		@make -C ./minilibx --no-print-directory -s

${NAME}: ${OBJS} ${LIBFT} ${MLX}
		@clang ${FLAGS} ${OBJS} ${LIBFT} ${MLX} ${FLAGSMLX} -o ${NAME}
		@echo ${GREEN}"compilation complete"${EOC}

clean:
		@make -C ./libft clean --no-print-directory
		@make -C ./minilibx clean --no-print-directory -s
		@rm -rf ${OBJS}
		@echo ${YELLOW}"clean ok"

fclean: clean
		@rm -rf ${LIBFT} 
		@rm -rf ${NAME}
		@echo "fclean ok"${EOC}

re: fclean all

.PHONY: all clean fclean re
