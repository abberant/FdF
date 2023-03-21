# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 18:06:06 by aanouari          #+#    #+#              #
#    Updated: 2023/03/21 17:05:51 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf


SRCS =		$(wildcard *.c) $(wildcard ./libft/*.c)


NO_COLOR    =	\033[0m
GREEN		=	\033[0;1;92m
RED			=	\033[0;1;91m
BLUE		=	\33[0;1;94m


OBJ = $(SRCS:.c=.o)

CC = cc


MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit


CFLAGS = -Wall -Wextra -Werror -Imlx


RM = rm -rf


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RED)\r LOADING...⌛️$(NO_COLOR)"


all:		$(NAME)


$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(MLX) -o $(NAME)
	@printf "$(GREEN)\r SUCCESSFULLY COMPILED!!\n$(NO_COLOR)"


clean:
				@$(RM) $(OBJ)
				@printf "$(BLUE)\r Done Cleaning!!\n$(NO_COLOR)"


fclean:			clean
				@$(RM) $(NAME)


re:				fclean all