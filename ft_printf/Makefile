NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

INC_DIR = include

MANDATORY = ft_printf_string.c ft_printf_pointers.c ft_printf_hex.c \
            ft_printf_function.c ft_printf_decimals.c ft_printf_char.c ft_printf.c \

OBJ_FILES_MANDATORY = $(MANDATORY:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES_MANDATORY)
	@$(AR) $@ $^

clean:
	@rm -f $(OBJ_FILES_MANDATORY)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
