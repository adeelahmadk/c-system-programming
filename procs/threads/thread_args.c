#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * myturn( void *arg ) {
    int *iptr = (int *)arg;
    for(int i = 0; i < 8; i++) {
        sleep(1);
        printf("My turn %d, %d!\n", i, *iptr);
        (*iptr)++;
    }

    return NULL;
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
    int v = 5;

    pthread_create(&newthread, NULL, myturn, &v);
    yourturn();

    // wait for the thread to finish
    pthread_join(newthread, NULL);

    printf("Thread's done: v=%d\n", v);

    return 0;
}
