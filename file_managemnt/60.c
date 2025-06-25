#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (mkdir("../Pictures", 0755) == 0)
        printf("Directory '../Pictures' created successfully.\n");
    else
        perror("mkdir");

    return 0;
}

