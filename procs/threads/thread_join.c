#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * myturn( void *arg ) {
    for(int i = 0; i < 8; i++) {
        sleep(1);
        printf("My turn %d!\n", i);
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

    pthread_create(&newthread, NULL, myturn, NULL);
    yourturn();

    // wait for the thread to finish
    pthread_join(newthread, NULL);

    return 0;
}
