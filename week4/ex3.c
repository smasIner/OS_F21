#include <stdio.h>

#include <stdlib.h>

int main() {
    printf("Press CTRL + C to exit\n");
    char input[100];
    while (1) {
        printf("Enter the command: \n");
        scanf("%s",input);
        system(input);
    }
    return 0;
}

