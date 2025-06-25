#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat fileStat;

    if (stat("file.txt", &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    printf("Last modified time: %s", ctime(&fileStat.st_mtime));
    return 0;
}

