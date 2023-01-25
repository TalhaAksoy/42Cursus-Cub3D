NAME			= Cub3D
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -O3
OUTFILE			= -o $(NAME)
OS 				:= $(shell uname)

ifeq ($(OS), Darwin)
	MLXFLAGS	= -framework OpenGL -framework AppKit
else
	MLXFLAGS 	= -lm -lXext -lX11
endif

INC_LIBS		= -I./mathlib $(LIB_MATH) -I./libft $(LIB_FT)  -I./mlx $(LIB_MLX)
LIB_MLX			= ./mlx/libmlx.a
LIB_MATH		= ./mathlib/mathlib.a
LIB_FT			= ./libft/libft.a
SRCS_FILE		= color_check.c draw.c draw_others.c draw_walls.c get_next_line.c get_next_line_utils.c init.c keys.c main.c map_control_utils.c move.c read_map.c read_map_utils.c utils2.c utils.c valid_map.c
OBJS_FILE		= $(SRCS_FILE:.c=.o)
OBJS_DIR		= ./obj/
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_FILE))

RM				= rm -rf

all: $(NAME)

$(NAME): $(LIB_MATH) $(LIB_MLX) $(LIB_FT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(OUTFILE) $(LIB_MATH) $(LIB_MLX) $(LIB_FT) $(MLXFLAGS)

$(LIB_MATH) :
	make -C ./mathlib

$(LIB_MLX) :
ifeq ($(OS), Darwin)
	curl https://projects.intra.42.fr/uploads/document/document/12900/minilibx_opengl.tgz -o mlx.tgz
	tar -xf mlx.tgz
	$(RM) mlx.tgz
	mv ./minilibx_opengl_20191021 ./mlx
	make -C ./mlx
else
	curl https://projects.intra.42.fr/uploads/document/document/12154/minilibx-linux.tgz -o mlx.tgz
	tar -xf mlx.tgz
	$(RM) mlx.tgz
	mv ./minilibx-linux ./mlx
	make -C ./mlx
endif

$(LIB_FT) :
	make -C ./libft

$(OBJS_DIR)%.o:%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS_DIR)
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)
	$(RM) ./mlx
	make fclean -C ./mathlib

re: fclean all

M = "Auto Commit (I'm lazy for write commit :D)"

git: fclean
	git add .
	git status
	git commit -m $(M)
	git push

.PHONY: all clean fclean re

