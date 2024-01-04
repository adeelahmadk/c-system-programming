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
    pthread_t newthread;

    pthread_create(&newthread, NULL, myturn, NULL);
    yourturn();

    return 0;
}
