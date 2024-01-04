/**
* Reaping child processes
*
* Reference:
* Understanding zombie processes by Jacob Sorber
* https://youtu.be/xJ8KenZw2ag?si=_JS7Y11tpK_mYSYV
*/

#include <stdio.h>
#include <sys/types.h>  // defines pid_t
#include <unistd.h>     // defines fork & getpid

int main() {
    pid_t cpid = fork();
    if (cpid == 0) {
        printf("%d> I can be childish...\n", getpid());
        return 0;
    }

    printf("%d> I am an irresponsible adult leaving %d behind...\n", getpid(), cpid);
    sleep(5);

    return 0;
}
