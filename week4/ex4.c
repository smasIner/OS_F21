#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int backgroundProcess = fork();
    printf("%d ",backgroundProcess);
    if(backgroundProcess == 0){
        char commandInput[100];
        char* argv[100] = {};
        char* wordPointer;
        printf("Enter the command: \n");
        gets(commandInput);
        wordPointer = strtok(commandInput, " ");
        int i = 0;
        while (wordPointer != NULL) {
            argv[i] = wordPointer;
            wordPointer = strtok(NULL, " ");
            i++;
        }
        execvp(argv[0], argv);
    }
    return 0;
}
