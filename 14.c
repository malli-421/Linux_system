#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void delete_files ( const char *dirname)
{
        struct dirent *entry;
        DIR *dir = opendir(dirname);
        if ( dir == NULL )
        {
                perror("failed to open");
                return;
        }

        char filepath[1024];

        while (( entry = readdir(dir)) != NULL )
        {
                if ( strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0 )
                        continue;
                snprintf(filepath,sizeof(filepath),"%s/%s",dirname,entry->d_name);
                if ( remove(filepath) != 0 )
                        perror("failed to delete");
                else
                        printf("delete file successfully\n");
        }
        closedir(dir);
}
int main ()
{
        delete_files("TEST");
}
