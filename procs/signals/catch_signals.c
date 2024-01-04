#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int num) {
    write(STDOUT_FILENO, "I won't die\n", 13);  // signal safe printing
}

int main() {
    signal(SIGINT, handler);
    signal(SIGTERM, handler);   // only dies with SIGKILL
    while (1) {
        printf("waisting your cycles: %d\n", getpid());
        sleep(1);
    }
    return 0;
}
