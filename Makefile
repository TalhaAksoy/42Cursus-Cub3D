NAME		= Cub3D
CC			= gcc
CFLAGS		= -g #-Wall -Wextra -Werror -g
MFLAGS		= -I./mlx ./mlx/libmlx.a -I./libft ./libft/libft.a -I./mathlib ./mathlib/mathlib.a
SRCS		= $(wildcard ./*.c)
OBJS		= $(SRCS:%.c=%.o)
RM			= rm -rf

all:$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft
	make -C ./mlx
	make -C ./mathlib

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(MFLAGS) $(SRCS) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) ./libft/*.o
	$(RM)  ./*.o

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)
	$(RM) ./mlx/*.o
	$(RM) ./mlx/*.a
	make fclean -C ./mathlib

re: fclean all

M = "Auto Commit (I'm lazy for write commit :D)"

git:
	git add .
	git status
	git commit -m $(M)
	git push

.PHONY: all clean fclean re

