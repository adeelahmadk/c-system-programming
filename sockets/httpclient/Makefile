CC=gcc
CFLAGS= -g

all: tcpc

tcpc: httpclient.c
	$(CC) $(CFLAGS) -o tcpc httpclient.c

clean:
	rm -rf *.dSYM tcpc
