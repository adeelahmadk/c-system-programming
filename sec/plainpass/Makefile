CC=gcc
CFLAGS= -g

all: plainpass

plainpass: plainpass.c
	$(CC) $(CFLAGS) -o overrun plainpass.c

clean:
	rm -rf *.dSYM *.o plainpass
