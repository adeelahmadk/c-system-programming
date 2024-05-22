#include <stdio.h>
#include <string.h>

# define BUFFERSIZE 10

char buffer[BUFFERSIZE] = "message";
char password[BUFFERSIZE] = "Passw0rd";

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage: %s <password> <string_to_print>\n", argv[0]);
        return -1;
    }
    strcpy(buffer, argv[2]);
    if (strcmp(argv[1], password) == 0) {
        printf("Correct!\n%s", buffer);
    } else {
        printf("Incorrect. :(\n");
    }
    return 0;
}
