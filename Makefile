.POSIX:

CC=gcc
LIBS = -lm
CFLAGS = -Wextra -Wall -std=c99 -g -pedantic -Werror -Wmissing-declarations \
	-Wimplicit-fallthrough

.PHONY: clean test

myenv: src/myenv.c src/main.c
	@echo Compiling $@
	@${CC} ${CFLAGS} src/main.c src/myenv.c -o myenv

clean:
	rm myenv
