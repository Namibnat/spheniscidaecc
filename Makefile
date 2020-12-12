# Makefile spheniscidaecc

CC=gcc

test: spheniscidaecc
	./spheniscidaecc test.c

spheniscidaecc: main.c
	$(CC) -o spheniscidaecc main.c tokenize.c

clean:
	rm spheniscidaecc
