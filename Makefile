NAME=minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
UTILS = utils.c

$(NAME) : libft client server

all: $(NAME)


client: client.c libft/libft.a
	$(CC) $(CFLAGS) -o client $(UTILS) client.c libft/libft.a

server: server.c libft/libft.a
	$(CC) $(CFLAGS) -o server $(UTILS) server.c libft/libft.a

libft/libft.a:
	$(MAKE) bonus -C libft

bonus: all

clean:
	rm -f client server
	$(MAKE) -C libft clean

fclean: clean
	$(MAKE) -C libft fclean

re: fclean all
