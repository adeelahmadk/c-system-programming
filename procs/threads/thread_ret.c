#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * myturn( void *arg ) {
    int *iptr = (int *)malloc(sizeof(int));
    *iptr = 5;
    for(int i = 0; i < 8; i++) {
        sleep(1);
        printf("My turn %d, %d!\n", i, *iptr);
        (*iptr)++;
    }

    return iptr;
}

void yourturn() {
    for(int i = 0; i < 3; i++) {
        sleep(2);
        printf("Your turn %d!\n", i);
    }
}

int main(int argc, char *argv[])
{
    pthread_t newthread;
    // int v = 5;
    int *result;

    pthread_create(&newthread, NULL, myturn, NULL);
    yourturn();

    // wait for the thread to finish
    pthread_join(newthread, (void *)&result);

    printf("Thread's done: *result=%d\n", *result);

    return 0;
}
