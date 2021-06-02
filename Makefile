.POSIX:

CC=gcc
LIBS = -lm
#CFLAGS = -Wextra -Wall -std=c99 -g -pedantic -Werror -Wmissing-declarations

.PHONY: clean test

myenv: src/myenv.c
	@echo Compiling $@
	@${CC} ${CFLAGS} src/myenv.c -o myenv

test: tests.out
	./test.out

tests.out: test/*.c src/*.c src/*.h
	@echo compiling tests
	@${CC} ${CFLAGS} src/*.c test/vendor/unity.c test/*.c -o tests.out ${LIBS}
clean:
	rm myenv
