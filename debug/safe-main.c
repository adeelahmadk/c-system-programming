#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 10

int list[LIST_SIZE] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

int get_value(int i) {
    if (i >= LIST_SIZE) {
        printf("index out of bound!\n");
        return -1;
    }
    return list[i];
}

int main(int argc, char *argv[])
{
    int d, index;
    
    printf("enter an index: ");
    scanf("%d", &d);
    printf("\nlet\'s take peek at index: %d\n", d);

    if ((index = get_value(d)) < 0) {
        printf("** bad index entered! **\n");
        return EXIT_FAILURE;
    }
    printf("peeking: %d\n", list[index]);

    return EXIT_SUCCESS;
}
