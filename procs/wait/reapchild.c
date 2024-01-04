/**
* Reaping child processes
*
* Reference:
* Understanding zombie processes by Jacob Sorber
* https://youtu.be/xJ8KenZw2ag?si=_JS7Y11tpK_mYSYV
*/

#include <stdio.h>
#include <sys/types.h>  // defines pid_t
#include <sys/wait.h>   // defines wait
#include <unistd.h>     // defines fork & getpid

int main() {
    pid_t cpid = fork();
    if (cpid == 0) {
        printf("%d> I can be childish...\n", getpid());
        sleep(5);
        return 0;
    }
    
    wait(NULL);     // child has been reaped! x}
    printf("The responsible parent %d won't die before reaping %d\n", getpid(), cpid);
    return 0;
}
