#include <stdio.h>
#include <string.h>

void vulnerable(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    vulnerable(argv[1]);
    return 0;
}

