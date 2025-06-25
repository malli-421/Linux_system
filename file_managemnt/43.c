#include <stdio.h>
#include <unistd.h>

int main() {
    if (access("config.ini", W_OK) == 0)
        printf("File 'config.ini' is writable.\n");
    else
        perror("File 'config.ini' is not writable");

    return 0;
}

