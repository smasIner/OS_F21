#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char *ptr;
    int size = 10 * 1024 * 1024;
    char value = '0';
    struct rusage used;
    for (int i = 0; i < 10; i++) {
        ptr = malloc(size);
        if(i == 0){
            getrusage(RUSAGE_SELF, &used);
            printf("Memory usage in MB (Before using memset)): %f \n", (double)used.ru_maxrss/1024/1024);
        }
        memset(ptr, value, size);
        getrusage(RUSAGE_SELF, &used);
        printf("Memory usage in MB: %f \n", (double)used.ru_maxrss/1024/1024);
        sleep(1); // wait for 1 second till next iteration
    }
    return 0;
}
