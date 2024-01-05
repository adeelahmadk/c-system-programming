# POSIX Threads

POSIX standard provide `pthread` library to run and manage parallel threads of execution.

If `pthread` is not installed in your system then use following:

```shell
sudo apt install libpthread-stubs0-dev manpages-posix manpages-posix-dev
```

While reading man pages, remember that the man page entry in Ubuntu and variants is named `pthreads`. Therefore, use following command:

```shell
man pthreads
```

## pthread API

### `pthread_t`

This type uniquely identifies a thread.

> IEEE Std 1003.1-2001/Cor 2-2004, item XBD/TC2/D6/26 is applied, adding pthread_t to the list of types that are not required to be arithmetic types, thus allowing pthread_t to be defined as a structure.
> [Stackoverflow Answer](https://stackoverflow.com/a/33285994/5892622)


