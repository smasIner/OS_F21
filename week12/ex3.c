#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void prepareArr(int* multitouch){
    for (int i = 0; i < 6; ++i) {
        multitouch[i] = -1;
    }
}
int addKey(int* multitouch, int key){
    int found = 0;
    for (int i = 0; i < 6; ++i) {
        if(multitouch[i] == -1){
            found = 1;
            multitouch[i] = key;
            break;
        }
    }
    if (found == 0){
        printf("More than 6 keys pressed at a time, exiting");
        exit(-1);
    }
}
int releaseKey(int* multitouch, int key){
    for (int i = 0; i < 6; ++i) {
        if(multitouch[i] == key){
            multitouch[i] = -1;
        }
    }
}
void checkCAP(int* multitouch){
    int found = 0;
    for (int i = 0; i < 6; ++i) {
        if (multitouch[i] == 46 || multitouch[i] == 30 || multitouch[i] == 25) {
            found++;
        }
    }
    if(found == 3){
        printf("Get some cappuccino!\n");
    }
}
void checkPE(int* multitouch){
    int found = 0;
    for (int i = 0; i < 6; ++i) {
        if (multitouch[i] == 18 || multitouch[i] == 25) {
            found++;
        }
    }
    if(found == 2){
        printf("I passed the Exam!\n");
    }
}
void checkDEATH(int* multitouch){
    int found = 0;
    for (int i = 0; i < 6; ++i) {
        if (multitouch[i] == 33 || multitouch[i] == 46 || multitouch[i] == 37) {
            found++;
        }
    }
    if(found == 3){
        printf("I have got 0 for last lab, because "
               "I forgot to upload the week 11 lab to moodle, but I did the lab at github.\n");
    }
}
int checkCombo(int* multitouch){
    checkCAP(multitouch);
    checkPE(multitouch);
    checkDEATH(multitouch);
}
int main() {
    int multitouch[6]; // as we can wave maximum 6 touch combination
    prepareArr(multitouch);
    char* path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int rdr = open(path, O_RDONLY);
    struct input_event key;
    printf("ctrl + c to exit!\n");
    printf("Available shortcuts are: \n P + E \n C + A + P \n F + C +  K \n");
    while(1) {
        read(rdr, &key, sizeof(struct input_event));
        if(key.type != EV_SYN) {
            if (key.value == 1) {
                addKey(multitouch, key.code);
            }
            if (key.value == 0) {
                if (key.code != 0) {
                    releaseKey(multitouch, key.code);
                }
            }
            checkCombo(multitouch);
            fflush(stdout);
        }
    }
    return 0;
}
