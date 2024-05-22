CC=gcc
CFLAGS= -g

all: segfault segsafe

segfault: main.c
	$(CC) $(CFLAGS) -o segfault main.c

segsafe: safe-main.c
	$(CC) $(CFLAGS) -o segsafe safe-main.c

clean:
	rm -rf *.o *.dSYM segfault segsafe
