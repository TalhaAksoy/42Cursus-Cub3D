NAME		= mapcontrol.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= color_check.c map_control_utils.c read_map_utils.c read_map.c valid_map.c
OBJS		= $(SRCS:.c=.o)
OBJ_DIR		= ./obj/
OBJS_FILE	= $(addprefix $(OBJ_DIR), $(OBJS))
RM			= rm -rf

all:$(NAME)

$(NAME): $(OBJS_FILE)
	ar rcs $(NAME) $(OBJS_FILE)


$(OBJ_DIR)%.o : %.c
	mkdir -p ./obj/
	$(CC) $(CFLAGS) -c $^ -o $@ -g

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

