#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void delete_dir(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    char full_path[1024];
    struct stat st;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (lstat(full_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                delete_dir(full_path);
            } else {
                if (remove(full_path) != 0)
                    perror("remove file");
            }
        }
    }

    closedir(dir);

    if (rmdir(path) != 0)
        perror("rmdir");
}

int main() {
    const char *dir_path = "Temp";
    delete_dir(dir_path);
    printf("Directory '%s' deleted recursively.\n", dir_path);
    return 0;
}

