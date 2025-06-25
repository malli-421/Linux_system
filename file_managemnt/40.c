#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    struct stat st;
    char path[512];
    off_t max_size = 0;
    char largest_file[256] = "";

    while ((entry = readdir(dir)) != NULL) {
        snprintf(path, sizeof(path), "./%s", entry->d_name);
        if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
            if (st.st_size > max_size) {
                max_size = st.st_size;
                strncpy(largest_file, entry->d_name, sizeof(largest_file));
            }
        }
    }

    closedir(dir);

    if (max_size > 0)
        printf("Largest file: %s (%ld bytes)\n", largest_file, (long)max_size);
    else
        printf("No regular files found.\n");

    return 0;
}

