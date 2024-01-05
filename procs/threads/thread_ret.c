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
    // used to uniquely identify a thread
    pthread_t newthread;
    // int v = 5;
    int *result;

    // start a new thread
    pthread_create(
        &newthread, // unique identity for thread
        NULL,
        myturn,     // function pointer to thread routine
        NULL        // arg
    );
    yourturn();

    // wait for the thread to finish
    pthread_join(
        newthread,          // unique ID
        (void *)&result     // pointer to the result pointer
    );

    printf("Thread's done: *result=%d\n", *result);

    return 0;
}
