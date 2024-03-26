CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

SOURCES_SERVER = server.c utilities.c
SOURCES_CLIENT = client.c utilities.c

OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJECTS_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJECTS_SERVER)

$(CLIENT): $(OBJECTS_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJECTS_CLIENT)

$(NAME): all

clean:
	rm -f $(OBJECTS_SERVER) $(OBJECTS_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
