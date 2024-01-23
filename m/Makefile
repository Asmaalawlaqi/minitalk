NAME = server
NAME1 = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = client.c server.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(NAME1)

$(NAME): server.o
	$(CC) $(CFLAGS) server.o -o $(NAME)

$(NAME1): client.o
	$(CC) $(CFLAGS) client.o -o $(NAME1)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME1)

re: fclean all