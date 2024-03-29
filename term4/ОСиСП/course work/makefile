CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Wpointer-to-int-cast -Wunused-variable
.PHONY : clean

all : server

server: server.c server.h
	$(CC) $(CFLAGS) server.c -o server

clean:
	rm -f server
