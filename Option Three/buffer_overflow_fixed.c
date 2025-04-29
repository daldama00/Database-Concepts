#include <stdio.h>
#include <string.h>

void secure(char *input) {
    char buffer[10];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[9] = '\0'; // Ensure null-termination
    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    secure(argv[1]);
    return 0;
}

