# Makefile spheniscidaecc

CC=gcc
CFLAGS = -g -Wall

spheniscidaecc: main.c
	$(CC) -g -o spheniscidaecc main.c tokenize.c


.PHONY: clean
clean:
	rm -f spheniscidaecc


.PHONY: test
test: spheniscidaecc
	./spheniscidaecc test.c
