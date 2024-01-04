/**
 * Read a file with file I/O
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // defines open
#include <unistd.h>     // defines close
#include <sys/mman.h>   // defines mmap
#include <sys/stat.h>   // defines fstat

void print_usage(char *name) {
    fprintf(stderr, "usage: %s <file-name>\n", name);
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    struct stat sb;
    // open file descriptor:
    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL) {
        fprintf(stderr, "unable to open file!\n");
        return 1;
    }

    // read file stats
    if(stat(argv[1], &sb) == -1) {
        perror("couldn't get file size!\n");
        return 1;
    }

    printf("file size is %ld bytes\n", sb.st_size);
    printf(">> printing file as array of characters:\n\n");

    srand(45);
    for(size_t i = 0; i < 5000; i++) {
        int index = rand() % sb.st_size;
        fseek(fp, index, SEEK_SET);
        printf("%c", fgetc(fp));
    }
    printf("\n\n>> Finished random reading!\n");

    // close file
    fclose(fp);

    return EXIT_SUCCESS;
}
