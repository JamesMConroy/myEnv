.POSIX:

CC=gcc
CFLAGS = -Wextra -Wall -std=c99 -g -pedantic -Werror -Wmissing-declarations\
	-Wimplicit-fallthrough

.PHONY: clean test

myenv: src/myenv.c src/main.c
	@echo Compiling $@
	@${CC} ${CFLAGS} src/main.c src/myenv.c -o myenv

test: test.o
	./test.o

test.o: src/myenv.c src/tests.c src/minunit.h
	${CC} ${CFLAGS} src/myenv.c src/tests.c -o test.o

clean:
	rm myenv *.o
