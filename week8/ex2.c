#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// "si" and "so" (amount of memory Swapped In and Out) numbers change only when MB is near the 1000
// when "so" become to grow, the pc freezes for several seconds.

int main() {
    char *ptr;
    int size = 10 * 1024 * 1024;
    for (int i = 0; i < 10; i++) {
        ptr = malloc(size);
        memset(ptr, '0', size);
        sleep(1); // wait for 1 second till next iteration
    }
    return 0;

}
