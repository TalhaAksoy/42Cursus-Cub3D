NAME		= Cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OUTFILE		= -o $(NAME)
OS := $(shell uname)
ifeq ($(OS), Darwin)
	MLXFLAGS = -framework OpenGL -framework AppKit
else
	MLXFLAGS = -lm -lXext -lX11
endif
MFLAGS		= -I./mlx ./mlx/libmlx.a -I./libft ./libft/libft.a -I./mathlib ./mathlib/mathlib.a
SRCS_FILE		= utils.c main.c get_next_line.c get_next_line_utils.c draw.c
OBJS_FILE		= $(SRCS_FILE:%.c=%.o)
OBJS_DIR		= ./obj/
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_FILE))

RM			= rm -rf
REMOVEME = -g

all:$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft
	make -C ./mlx
	make -C ./mathlib

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(REMOVEME) $(OUTFILE) $(MFLAGS) $(MLXFLAGS)

$(OBJS_DIR)%.o:%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@ $(REMOVEME)

clean:
	$(RM) $(OBJSDIR)
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

