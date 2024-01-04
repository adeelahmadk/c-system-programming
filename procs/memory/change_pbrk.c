/**
* Request memory with brk & sbrk
*
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    void *first = sbrk(0);      // location of the program break
    void *second = sbrk(4096);  // move program break by 4k
    void *third = sbrk(0);      // check new location of the program break

    printf("First: %p\n", first);
    printf("Second: %p\n", second);
    printf("Third: %p\n", third);

    return 0;
}
