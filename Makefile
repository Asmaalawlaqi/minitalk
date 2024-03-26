SERVER = server
CLIENT = client
CFLAGS = -Wall -Werror -Wextra
CC = cc
PRINTF = ft_printf
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers

all: $(SERVER) $(CLIENT)

$(SERVER): server.c $(PRINTF)/libftprintf.a
	@$(CC) $(CFLAGS) -o $(SERVER) server.c -L$(PRINTF) -lftprintf
	@echo "Server is Ready!"

$(CLIENT): client.c $(PRINTF)/libftprintf.a
	@$(CC) $(CFLAGS) -o $(CLIENT) client.c -L$(PRINTF) -lftprintf
	@echo "Client is Ready!"

$(PRINTF)/libftprintf.a:
	@make -s -C $(PRINTF)

clean:
	@make -s -C $(PRINTF) clean

fclean: clean
	@make -s -C $(PRINTF) fclean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all
