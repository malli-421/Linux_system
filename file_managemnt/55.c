#include <stdio.h>

int main() {
    if (rename("old_name.txt", "new_name.txt") == 0)
        printf("File renamed successfully.\n");
    else
        perror("rename");

    return 0;
}

