NAME = server
NAME1 = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

$(NAME): $(OBJS_SERVER) $(PRINTF)/libftprintf.a
	@$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME) -L$(PRINTF) -lftprintf

$(NAME1): $(OBJS_CLIENT) $(PRINTF)/libftprintf.a
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME1) -L$(PRINTF) -lftprintf

$(PRINTF)/libftprintf.a:
	@$(MAKE) -C $(PRINTF)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(NAME1)
	@echo "Server And Client Are Ready!"

clean:
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(MAKE) -C $(PRINTF) clean

fclean: clean
	@rm -f $(NAME) $(NAME1)
	@$(MAKE) -C $(PRINTF) fclean
	@echo "Server and Client Have Been Cleaned Successfully"


re: fclean all
