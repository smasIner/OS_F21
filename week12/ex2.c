#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
    char* path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int rdr = open(path, O_RDONLY); // https://linux.die.net/man/3/open , RDONLY, as we do not modify the file
    struct input_event key;
    printf("ctrl + c to exit!\n");
    while(1) {
        read(rdr, &key, sizeof(struct input_event));
        // That if statement to exclude errors that can occur
        // Read that from : https://www.kernel.org/doc/html/v4.17/input/event-codes.html#event-types ,
        if(key.type != EV_SYN) {
            if (key.value == 1) {
                printf("PRESSED 0x%.4x (%d)\n", key.code, key.code);
            }
            if (key.value == 0) {
                // To avoid repeatedly printing released
                if (key.code != 0) {
                    printf("RELEASED 0x%.4x (%d)\n", key.code, key.code);
                }
            }
            fflush(stdout);
        }
    }
    return 0;
}
