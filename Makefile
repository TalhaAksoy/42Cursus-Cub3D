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
OBJS_FILE		= $(SRCS_FILE:.c=.o)
OBJS_DIR		= ./obj/
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_FILE))

RM			= rm -rf
REMOVEME = -g

all:$(MFLAGS) $(NAME)

ifeq ($(OS), Darwin)
$(MFLAGS):
	test -f ./mlx || wget https://projects.intra.42.fr/uploads/document/document/12900/minilibx_opengl.tgz
	tar -xf minilibx_opengl.tgz
	$(RM) minilibx_opengl.tgz
	mv ./minilibx_opengl ./mlx
	make -C ./libft
	make -C ./mlx
	make -C ./mathlib
else
$(MFLAGS):
	test -f ./mlx || wget https://projects.intra.42.fr/uploads/document/document/12154/minilibx-linux.tgz
	tar -xf minilibx-linux.tgz
	$(RM) minilibx-linux.tgz
	mv ./minilibx-linux ./mlx
	make -C ./libft
	make -C ./mlx
	make -C ./mathlib
endif

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(REMOVEME) $(OUTFILE) $(MFLAGS) $(MLXFLAGS)

$(OBJS_DIR)%.o:%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@ $(REMOVEME)

clean:
	$(RM) $(OBJS_DIR)
	$(RM) ./libft/*.o

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)
	$(RM) ./mlx
	make fclean -C ./mathlib

re: fclean all

M = "Auto Commit (I'm lazy for write commit :D)"

git:
	git add .
	git status
	git commit -m $(M)
	git push

.PHONY: all clean fclean re

