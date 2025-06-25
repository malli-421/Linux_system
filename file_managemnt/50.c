#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (mkdir("Documents", 0755) == -1) {
        perror("mkdir");
        return 1;
    }

    printf("Directory 'Documents' created successfully.\n");
    return 0;
}

