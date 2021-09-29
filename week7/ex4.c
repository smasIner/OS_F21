#include <stdlib.h>
#include <stdio.h>
#include <libc.h>

void* reallocate(void *ptr, int initial, int new){
    if(ptr == NULL){
        return malloc(new);
    }
    else if(new == 0){
        free(ptr);
        return NULL;
    }
    else{
        void *temp = malloc(new);
        memcpy(temp, ptr, initial);
        ptr = temp;
        free(temp);
        return ptr;
    }
}
int main(){
    printf("Enter original array size:");
    int n1 = 0;
    scanf("%d",&n1);

    int* a1 = malloc(n1 * sizeof(int));
    int i;
    for(i=0; i<n1; i++){
        a1[i] = 100;
        printf("%d ", a1[i] );
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d",&n2);

    a1 = reallocate(a1, n1 * sizeof (int), n2 * sizeof (int));

    if(n2 > n1){
        for (int j = n1; j < n2; ++j) {
            a1[i] = 0;
        }
    }
    for(i=0; i<n2;i++){
        printf("%d ", a1[i]);
    }
    printf("\n");

    return 0;
}
