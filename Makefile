# Makefile spheniscidaecc

CC=gcc

test: spheniscidaecc
	./spheniscidaecc test.c

spheniscidaecc: main.c
	$(CC) -o spheniscidaecc main.c

clean:
	rm spheniscidaecc
