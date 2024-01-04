/**
* Request memory with mmap
*
*/

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGESIZE 4096

int main() {
    // memory mapping in virtual address space
    uint8_t *first = mmap(NULL,         // map anywhere
                          4*PAGESIZE,
                          PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    uint8_t *second = mmap((void *)0xFEEDBEEF,
                           PAGESIZE,
                          PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    printf("First: %p\n", first);
    printf("Second: %p\n", second);

    return 0;
}
