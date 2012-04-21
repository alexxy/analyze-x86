CC=gcc
CFLAGS=-O2 -march=native -mtune=native

all:
	$(CC) $(CFLAGS) -I. -o analyze-x86 analyze-x86.c

clean:
	rm analyze-x86
