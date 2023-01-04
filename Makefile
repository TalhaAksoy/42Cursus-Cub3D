NAME		= Cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror 
MFLAGS		= -I./mlx ./mlx/libmlx.a -I./libft ./libft/libft.a
SRCS		= $(wildcard ./*.c)
OBJS		= $(SRCS:%.c=%.o)
RM			= rm -rf

all:$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(MFLAGS) $(SRCS) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) ./libft/*.o
	$(RM)  ./*.o

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

