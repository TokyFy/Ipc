CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: libft client server

client: client.c libft/libft.a
	$(CC) $(CFLAGS) -o client client.c libft/libft.a

server: server.c libft/libft.a
	$(CC) $(CFLAGS) -o server server.c libft/libft.a

libft/libft.a:
	$(MAKE) -C libft

clean:
	rm -f client server
	$(MAKE) -C libft clean

fclean: clean
	$(MAKE) -C libft fclean

re: fclean all
