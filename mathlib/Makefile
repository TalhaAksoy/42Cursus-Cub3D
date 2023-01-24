NAME		= mathlib.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= ft_abs.c ft_fabs.c ft_pow.c ft_sqrt.c
OBJS		= $(SRCS:.c=.o)
OBJ_DIR		= ./obj/
OBJS_FILE	= $(addprefix $(OBJ_DIR), $(OBJS))
RM			= rm -rf

all:$(NAME)

$(NAME): $(OBJS_FILE)
	ar rcs $(NAME) $(OBJS_FILE)


$(OBJ_DIR)%.o : %.c
	mkdir -p ./obj/
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

