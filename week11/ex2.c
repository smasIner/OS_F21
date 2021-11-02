#include <stdio.h>
#include <dirent.h>
int main() {
    DIR *ds;
    struct dirent *dir;
    ds = opendir("/");
    while ((dir = readdir(ds)) != NULL) {
        printf("%s\n", dir->d_name);
    }
    closedir(ds);
    return 0;
}
