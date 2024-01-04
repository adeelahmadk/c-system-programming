/**
 * Shared memory between parent and child processes
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // defines close
#include <sys/mman.h>   // defines mmap
#include <sys/wait.h>

#define PAGESIZE 4096

int v = 5; // global var

int main(int argc, char *argv[])
{
    // map file into memory:
    // start anywhere, 4k page size,
    // protection: read & write,
    // flags: shared & anonymous mapping
    uint8_t *shared_mem = mmap(
        NULL,
        PAGESIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_ANONYMOUS,
        -1, 0
    );

    if(fork() == 0) {
        *shared_mem = 45;
        v = 80;
    } else {
        wait(NULL);
    }

    printf("Not Shared: %d\n", v);
    printf("Shared: %d\n", *shared_mem);

    // unmap and close file
    munmap(shared_mem, PAGESIZE);


    return EXIT_SUCCESS;
}
