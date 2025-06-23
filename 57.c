#include <stdio.h>

int main() {
    if (rename("file.txt", "Backup/file.txt") == 0)
        printf("File moved to Backup/ directory.\n");
    else
        perror("rename");

    return 0;
}

