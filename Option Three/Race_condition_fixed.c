#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char *filename = "temp.txt";

    // Open only if file exists and isn't replaced during the check
    int fd = open(filename, O_RDONLY | O_NOFOLLOW);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[100];
    read(fd, buffer, sizeof(buffer) - 1);
    buffer[99] = '\0';
    printf("Contents: %s\n", buffer);
    close(fd);

    return 0;
}

