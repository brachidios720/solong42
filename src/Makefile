# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:02:22 by rcarbonn          #+#    #+#              #
#    Updated: 2024/05/29 19:22:15 by rcarbonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = clang
CFLAGS  = -Wall -Werror -Wextra -g3
RM      = rm -f
NAME    = so_long

SRCG    = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c 
	
SRCP	= ../printf/src/ft_printf.c \
			../printf/src/ft_putchar.c \
			../printf/src/ft_putnbr.c \
			../printf/src/ft_putptr.c \
			../printf/src/ft_putstr.c \
			../printf/src/utils.c
			
SRC     = map.c \
		 utils.c \
		 init_map.c \
		 so_long.c \
		 player.c \
		 parsing_maps.c \
		 utils2.c \
		 parsing_map2.c

MLX_LIB	= ../mlx/libmlx.a

MLX_FLAG =	-lX11 -lXext

MLX_EX =	$(MLX_LIB) $(MLX_FLAG)

OBJP	= $(SRCP:.c=.o)
OBJG    = $(SRCG:.c=.o)
OBJ     = $(SRC:.c=.o)

OBJS    = $(OBJG) $(OBJ) $(OBJP) 

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
