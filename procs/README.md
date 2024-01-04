# UNIX Processes

## System Calls

### fork


### exec

If we want to spawn a process that executes another program then we need to use `exec*` system calls.

| Call | Description |
| ---- | ----------- |
| `execl` | `exec` with a `NULL` terminated **list** of parameters |
| `execlp` | `exec` with **list** of parameters and path search |
| `execle` | `exec` with **list** of parameters, path search and environment variable |
| `execv` | `exec` with **vector** of parameters |
| `execvp` | `exec` with **vector** of parameters and path search |
| `execvpe` | `exec` with **vector** of parameters, path search and environment variable |

### wait

These system calls (`wait`, `waitpid`, `waitid`) are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed. A state change is considered to be: the child terminated; the child was stopped by a signal; or the child was resumed by a signal. In the case of a terminated child, performing a wait allows the system to release the resources associated with the child; if a wait is not performed, then the terminated child remains in a "zombie" state.

| Call | Signature | Description |
| ---- | --------- | ----------- |
| `wait` | `pid_t wait(int *wstatus);` | Suspends execution of the calling thread until one of its children terminates. |
| `waitpid` | `pid_t waitpid(pid_t pid, int *wstatus, int options);` | Suspends execution of the calling thread until a child specified by `pid` argument has changed state. |
| `waitid` | `int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);` |  |

## Example Programs

| Example | Description | Reference |
| ------- | ----------- | --------- |
| [tinyfork](fork/tinyfork.c) | New processes using fork system call | [Creating new processes with fork()](https://www.youtube.com/watch?v=ss1-REMJ9GA) |
| [tinyexecl](exec/tinyexecl.c) | Execute a program with parameter list | [Making forked clones more useful with exec()](https://www.youtube.com/watch?v=kDxjcyHu_Qs) |
| [tinyexeclp](exec/tinyexeclp.c) | Execute a program with parameter list and path search | [Making forked clones more useful with exec()](https://www.youtube.com/watch?v=kDxjcyHu_Qs) |
| [spawn_zombie](wait/spawn_zombie.c) | Spawn a zombie processes | [Understanding Zombie Processes](https://www.youtube.com/watch?v=xJ8KenZw2ag) |
| [reapchild](wait/reapchild.c) | Avoid zombie processes by using wait system call | [Understanding Zombie Processes](https://www.youtube.com/watch?v=xJ8KenZw2ag) |
| [signalchild](wait/signalchild.c) | Catching signals in child processes | wait(2) man page example |
|  |  |  |

## References

1. [Jacob Sorbo's YouTube Playlist](https://www.youtube.com/playlist?list=PL9IEJIKnBJjFNNfpY6fHjVzAwtgRYjhPw)
2. 
