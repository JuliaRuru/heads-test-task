CC=gcc
FLAGS=-Werror -Wall -Wextra -std=c11

default: all

all: clean test go

test: test.c
	$(CC) test.c $(FLAGS) -o test

clean:
	rm -rf test
	
go:
	./test
