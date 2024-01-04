/**
 * Edit a memory mapped file synchronously
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      // defines toupper
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
        "sample2.txt",
        O_RDWR,
        S_IRUSR | S_IWUSR
    );

    if(fd <= 0) {
        fprintf(stderr, "unable to open file!\n");
        return EXIT_FAILURE;
    }

    // read file stats
    if(fstat(fd, &sb) == -1) {
        perror("couldn't get file size\n");
        return EXIT_FAILURE;
    }
    printf("file size is %ld bytes\n", sb.st_size);

    // map file into memory:
    // start anywhere, entire file size,
    // protection: read & write,
    // flags: shared mapping
    char *file_in_mem = mmap(
        NULL,
        sb.st_size,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fd, 0
    );

    printf(">> printing file as array of characters:\n\n");
    for(size_t i = 0; i < sb.st_size; i++) {
        if(i % 2 == 0) {
            // update mapping
            file_in_mem[i] = toupper(file_in_mem[i]);
        }
        printf("%c", file_in_mem[i]);
    }
    printf("\n");

    // unmap and close file
    munmap(file_in_mem, sb.st_size);
    close(fd);

    return EXIT_SUCCESS;
}
