#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define BUF 10 // size of the buffer
#define true 1

int count = 4; // num of elements in buffer
int pSleep = 0; // boolean that represents the condition, at the beginning no-one is asleep
int cSleep = 0; // boolean that represents the condition, at the beginning no-one is asleep

/**
 * Represents the work of the producer while it is not asleep
 * @return
 */
void* producer(){
    if (count >= BUF) {
        pSleep = 1; // true, cast producer to sleep
        pthread_exit(NULL); // exit the thread
    }
    else {
        count++; // put item to the stack
        if(count == 1){
            cSleep = 0; // wake the consumer
        }
    }
    return NULL;
}
/**
 * Represents the work of the producer while it is not asleep
 * @return
 */
void* consumer(){
    if (count <= 0) {
        cSleep = 1; // true, cast consumer to sleep
        pthread_exit(NULL); // exit the thread
    }
    else {
        count--; // take item from the stack
    }
    return NULL;
}
int main() {
    pthread_t pId;
    pthread_t cId;
    clock_t begin = clock();
    while (true){
        if(pSleep != 1){
            pthread_create(&pId,NULL,producer,NULL);
        }
        if (cSleep != 1) {
            pthread_create(&cId, NULL, consumer, NULL);
        }
        if(cSleep == 1 && pSleep == 1){
            clock_t end = clock();
            // The process takes up to 1 minute
            printf("Both processes are asleep, problem occurred in approximate time %f(s)",
                   (double) ((end - begin)/ CLOCKS_PER_SEC));
            printf("\n The result is for Buffer of %d elements", BUF);
            break;
        }
    }
    return 0;
}
