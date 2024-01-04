/**
 * Map a file in memory
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // defines open
#include <unistd.h>     // defines close
#include <sys/mman.h>   // defines mmap
#include <sys/stat.h>   // defines fstat

int main(int argc, char *argv[])
{
    struct stat sb;

    // open file descriptor:
    // flags Read & Write, 
    // mode Read & Write (if created)
    int fd = open(
        "file.txt",
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
    for(size_t i = 0; i < sb.st_size; i++) {
        printf("%c", file_in_mem[i]);
    }
    printf("\n");

    // unmap and close file
    munmap(file_in_mem, sb.st_size);
    close(fd);

    return EXIT_SUCCESS;
}
