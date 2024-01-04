#include <sys/socket.h>
#include <sys/sendfile.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);

    if (s == -1) {
        printf("Error opening socket!\n");
        return 1;
    }
    
    struct sockaddr_in addr = {
        AF_INET,
        0x901f,
        0
    };
    if (bind(s, &addr, sizeof(addr)) == -1) {
        printf("Error binding socket!\n");
        return 1;
    }

    listen(s, 10);

    int client_fd = accept(s, 0, 0);

    char buffer[256] = {0};
    recv(client_fd, buffer, 255, 0);

    // GET /index.html ....
    char* f = buffer + 5;
    *strchr(f, ' ') = 0;
    int opened_fd = open(f, O_RDONLY);
    sendfile(client_fd, opened_fd, 0, 256);
    close(opened_fd);
    close(client_fd);
    close(s);
}
