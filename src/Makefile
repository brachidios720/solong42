# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:02:22 by rcarbonn          #+#    #+#              #
#    Updated: 2024/05/28 18:07:06 by rcarbonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = clang
CFLAGS  = -Wall -Werror -Wextra -g3
RM      = rm -f
NAME    = so_long

SRCG    = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
	
SRC     = map.c \
		 utils.c \
		 init_map.c \
		 so_long.c \
		 player.c \
		 parsing_maps.c \
		 utils2.c

MLX_LIB	= ../mlx/libmlx.a

MLX_FLAG =	-lX11 -lXext

MLX_EX =	$(MLX_LIB) $(MLX_FLAG)

OBJG    = $(SRCG:.c=.o)
OBJ     = $(SRC:.c=.o)

OBJS    = $(OBJG) $(OBJ) 

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_EX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(LINK)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
