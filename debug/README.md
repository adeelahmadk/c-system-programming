# Reverse Engineering, Debugging, Binary Inspection



## Inspection of Compiled Binaries

- Inspect all sections by using `objdump -s bufftest`.
- Display strings `readelf -x '.rodata' bufftest`
- Look at the symbol table by `readelf --symbols bufftest` or `objdump --syms bufftest`

## Core Dump Files

In most Linux distros the core dumps are handeled by some system service (e.g. apport for Ubuntu). This is set kernel configuration parameter `core_pattern`. This paramter sets the program to manage the dumps and/or the core dump file name and path. You can view it using `sysctl`:

```shell
sysctl kernel.core_pattern
```

If you want to debug a program with it's core dump, espacially having faced segmentation fault, then you have to update the core pattern:

```shell
sudo sysctl -w kernel.core_pattern=core.%p.%u
```

In above command, `%p` stands for the PID and `%u` stands for the UID.

## Example Programs

| Topic                      | Description                                                  |
| -------------------------- | ------------------------------------------------------------ |
| [Segment Fault](segfault/) | Debug & inspect a program allowing unbounded access to an array. |
|                            |                                                              |
