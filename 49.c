#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main() {
    char dirname[64];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    strftime(dirname, sizeof(dirname), "%Y-%m-%d-%H-%M-%S", tm_info);

    if (mkdir(dirname, 0755) == -1) {
        perror("mkdir");
        return 1;
    }

    printf("Directory '%s' created successfully.\n", dirname);
    return 0;
}

