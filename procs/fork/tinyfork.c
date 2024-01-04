/**
* Creating processes with fork
*
* Reference: Jacob Sorber's YouTube Video
* https://www.youtube.com/watch?v=ss1-REMJ9GA
*/

#include <stdio.h>
#include <sys/types.h>  // definition of pid_t
#include <unistd.h>     // defini of fork & getpid

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("%d> I can be childish...\n", getpid());
        return 0;
    }

    printf("%d> I am older and responsible for %d\n", getpid(), pid);
    return 0;
}
