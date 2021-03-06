#include <string.h>
#include <stdlib.h>
#include <unistd.h>


// Due to enough memory on my virtual machine(I use it as I use mac os, and want to use vmstat from linux), the swap memory was not used when I runned this program. To force system use it, I needed to 
// fill the main memory with another program. In case of additional filling the memory with second program that fills the memory with 1gb per second, the swap memory
// was used after 20 seconds (when main memory was filled).

// ex3(You can also see it in file ex3Findings.txt):
//We can see that our process appeared in the top display. We also can see precise memory that process is using.
//While it does not cause any troubles when I runned it with filling 10MB per second, it was causing lags when I filled with 1GB per second. Probably, because at that moment
//the swap memory was used. 


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
