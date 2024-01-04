/**
 * IPC via Named Pipes
 * - Create a named pipe with `mkfifo` command
 * - Start a process with output redirected to
 *   the named pipe
 * - run this program to read the output from the pipe
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char c;
    // open file descriptor:
    int fd = open("../mypipe", O_RDONLY);

    if(fd <= 0) {
        // print to stderr
        fprintf(stderr, "unable to open pipe!");
        return EXIT_FAILURE;
    }

    while(read(fd, &c, 1) > 0) {
        printf("%c", toupper(c));
    }
    close(fd);
    return EXIT_SUCCESS;
}
