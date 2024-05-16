CC      = clang
CFLAGS  = -Wall -Werror -Wextra
RM      = rm -f
NAME    = so_long

SRCG    = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c
SRC     = map.c utils.c

OBJG    = $(SRCG:.c=.o)
OBJ     = $(SRC:.c=.o)

OBJS    = $(OBJG) $(OBJ)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
