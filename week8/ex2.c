#include <string.h>
#include <stdlib.h>
#include <unistd.h>


// Due to enough memory on my virtual machine, the swap memory was not used when I runned this program. To force system use it, I needed to 
// fill the main memory with another program. In case of additional filling the memory with second program that fills the memory with 1gb per second, the swap memory
// was used after 20 seconds (when memory was filled).
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
