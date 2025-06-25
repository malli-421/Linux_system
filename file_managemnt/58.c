#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dp = opendir(".");
    if (!dp) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
    return 0;
}

