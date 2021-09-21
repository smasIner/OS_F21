#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct threadInfo{
    pthread_t id;
    int threadNumberCreated;
    char* stringToPronounceTemplate;
};

void *job(void *argc){
    struct threadInfo temp = *((struct threadInfo*) argc);
    temp.id = pthread_self();
    printf("%s", temp.stringToPronounceTemplate);
    printf("%d", temp.threadNumberCreated);
    printf(", It has the id: %ld \n", (long )temp.id);
    return NULL;
}
int main(){
    int N;
    printf("N = ");
    scanf("%d", &N);
    printf("\n");
    struct threadInfo *tInfo = calloc(N, sizeof (struct threadInfo));
    for (int i = 0; i < N; i++){
        tInfo[i].threadNumberCreated = i;
        tInfo[i].stringToPronounceTemplate = "Hello from thread number: ";
        pthread_create(&tInfo[i].id, NULL, job, &tInfo[i]);
        printf("Thread number %d has been created\n", i);
    }
	pthread_exit(NULL);
    return 0;
}
