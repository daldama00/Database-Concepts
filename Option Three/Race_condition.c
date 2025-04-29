#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char *filename = "temp.txt";
    struct stat st;

    if (stat(filename, &st) == 0) {
        printf("File exists, opening...\n");
        int fd = open(filename, O_RDONLY);
        char buffer[100];
        read(fd, buffer, sizeof(buffer) - 1);
        buffer[99] = '\0';
        printf("Contents: %s\n", buffer);
        close(fd);
    } else {
        printf("File not found.\n");
    }

    return 0;
}

