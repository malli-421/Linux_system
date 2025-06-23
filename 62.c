#include <stdio.h>

int main() {
    FILE *file = fopen("message.txt", "a");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fprintf(file, "Goodbye!\n");
    fclose(file);

    printf("Appended 'Goodbye!' to message.txt\n");
    return 0;
}

