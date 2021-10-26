#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *d = opendir("/Users/smasiner/Downloads/Shell/OS_F21/week10/tmp");
    struct dirent *dnt;
    while ((dnt = readdir(d)) != NULL) {
        if (strcmp(dnt->d_name, ".") == 0 || strcmp(dnt->d_name, "..") == 0) {
            continue;
        }
        char path[200];
        strcpy(path, "/Users/smasiner/Downloads/Shell/OS_F21/week10/tmp/");
        strcat(path, dnt->d_name);
        struct stat fileStat;
        if (stat(path, &fileStat) == -1) {
            printf("Cannot get stat from file\n");
            exit(1);
        }
        if (fileStat.st_nlink >= 2) {
            char s[200];
            sprintf(s, "find /Users/smasiner/Downloads/Shell/OS_F21/week10/tmp -inum %llu", dnt->d_ino);
            FILE *fp = popen(s, "r"); // https://stackoverflow.com/questions/5919622/how-to-store-the-system-command-output-in-a-variable
            char buffer[200];
            printf("%s - ", dnt->d_name);
            while (fgets(buffer, 199, fp) != NULL)
            {
                printf("%s ", buffer);
            }
            printf("\n");
        }
    }
    return(0);
}
