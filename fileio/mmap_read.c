/**
 * Read a memory mapped file
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
    // flags Read & Write, 
    // mode Read & Write (if created)
    int fd = open(
        argv[1],
        O_RDONLY,
        S_IRUSR | S_IWUSR
    );

    if(fd <= 0) {
        fprintf(stderr, "unable to open file!\n");
        return 1;
    }

    // read file stats
    if(fstat(fd, &sb) == -1) {
        perror("couldn't get file size!\n");
        return 1;
    }
    printf("file size is %ld bytes\n", sb.st_size);

    // map file into memory:
    // start anywhere, entire file size,
    // protection: read,
    // flags: private mapping
    char *file_in_mem = mmap(
        NULL, 
        sb.st_size,
        PROT_READ,
        MAP_PRIVATE,
        fd,
        0
    );

    printf(">> printing file as array of characters:\n\n");

    srand(45);
    for(size_t i = 0; i < 5000; i++) {
        int index = rand() % sb.st_size;
        printf("%c", file_in_mem[index]);
    }
    printf("\n\n>> Finished random reading!\n");

    // unmap and close file
    munmap(file_in_mem, sb.st_size);
    close(fd);

    return EXIT_SUCCESS;
}
