#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("Message.txt", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    char command[1024];

    while (fgets(command, sizeof(command), file)) {
        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        printf("Executing: %s\n", command);
        system(command);
    }

    fclose(file);
    return 0;
}

