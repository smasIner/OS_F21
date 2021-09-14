#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID of the main process: %d", getpid());
    for (int i = 0; i < 3; ++i) {
        fork();
        sleep(5);
    }
    return 0;
}
