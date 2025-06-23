#include <stdio.h>

int main() {
    if (remove("delete_me.txt") == 0)
        printf("File 'delete_me.txt' deleted successfully.\n");
    else
        perror("Error deleting file");

    return 0;
}

