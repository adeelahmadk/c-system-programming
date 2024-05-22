CC=gcc
CFLAGS= -g

all: bintest overrun

bintest: bintest.c
	$(CC) $(CFLAGS) -o bintest bintest.c

overrun: bufferoverrun.c
	$(CC) $(CFLAGS) -o overrun bufferoverrun.c

clean:
	rm -rf *.dSYM *.o bufftest overrun
