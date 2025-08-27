# Linux System Programming

A collection of programs and brief notes on Linux system programming.

On some Debian/Ubuntu systems, POSIX man pages are not installed by default. You can install following packages for this purpose:

```shell
sudo apt install manpages-posix manpages-posix-dev
```

## Sections

| Topic | Description |
| ------- | ----------- |
| [Reverse Engineering](debug/README.md) | Tools & techniques used to debug, inspect, and audit binaries. |
| [Processes](procs/README.md) | fork & exec procs, use IPC, manage memory, threads. |
| [File I/O](fileio/README.md) | Perform async & memory-mapped file I/O |
| [Socket I/O](sockets/README.md) | Network programming with socket API |
| [Security](sec/README.md) | Identify weak & vulnerable code. Try to exploit it. |

