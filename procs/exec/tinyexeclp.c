/**
* Creating processes with exec*
*
* Reference: Jacob Sorber's YouTube Video
* https://youtu.be/kDxjcyHu_Qs?si=YIgXpGCd3XoSn4qS
*/

#include <stdio.h>
#include <sys/wait.h>   // defines wait
#include <sys/types.h>  // defines pid_t
#include <unistd.h>     // defines fork & getpid

int main() {
    pid_t cpid = fork();
    if (cpid == 0) {
        printf("%d> I am childish...\n", getpid());
        execlp("ls", "ls", "-alh", NULL);
        printf("after the execlp call.\n");
    }

    wait(NULL);
    printf("%d> I am older and parental to %d\n", getpid(), cpid);
    return 0;
}
