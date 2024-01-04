/**
* Creating processes with exec*
*
* Reference: Jacob Sorber's YouTube Video
* https://youtu.be/kDxjcyHu_Qs?si=YIgXpGCd3XoSn4qS
*/

#include <stdio.h>
#include <sys/types.h>  // definition of pid_t
#include <unistd.h>     // defini of fork & getpid

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("%d> I can be childish...\n", getpid());
        execl("/usr/bin/ls", "ls", "-alh", NULL);
        printf("after the execlp call.\n");
    }

    printf("%d> I am older and parental to %d\n", getpid(), pid);
    return 0;
}
