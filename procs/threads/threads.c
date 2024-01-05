#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * myturn( void *arg ) {
    while(1) {
        sleep(1);
        printf("My turn!\n");
    }

    return NULL;
}

void yourturn() {
    while(1) {
        sleep(2);
        printf("Your turn!\n");
    }
}

int main(int argc, char *argv[])
{
    // used to uniquely identify a thread
    pthread_t newthread;

    // start a new thread
    pthread_create(
        &newthread, // unique identity for thread
        NULL,
        myturn,     // function pointer to thread routine
        NULL);      // arg
    yourturn();

    return 0;
}
