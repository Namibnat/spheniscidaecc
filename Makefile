# Makefile spheniscidaecc

CC=gcc

test: spheniscidaecc
	./spheniscidaecc test.c

spheniscidaecc: main.c
	$(CC) -g -o spheniscidaecc main.c tokenize.c

clean:
	rm spheniscidaecc
