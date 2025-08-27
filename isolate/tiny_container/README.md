# Basic Container Runtime in Go

This is program is a learning exercise following in the footsteps of the talk *[Containers from scratch](https://youtu.be/8fi7uSYlOdc)* at GOTO Con Amsterdam 2018 by Liz Rice.

The program uses a `rootfs` to `chroot` into. For this you'll need a Linux `rootfs` extracted in `/tmp/cgtest` as a perquisite. For example using an [Ubuntu Base image](https://cdimage.ubuntu.com/ubuntu-base/releases/) we can prepare `rootfs` as:

```shell
sudo mkdir -p /tmp/cgtest/ubuntu-fs
sudo tar xzvf ubuntu-base-24.04.3-base-amd64.tar.gz -C /tmp/cgtest/ubuntu-fs
```

Run the program with root privileges:

```shell
sudo go run main.go run /bin/bash
```

or, if your golang binary is in a non-standard path:

```shell
sudo /path/to/go run main.go run /bin/bash
```
