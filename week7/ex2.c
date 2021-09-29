#include <stdio.h>
#include <stdlib.h>

void printArray(int* ptr, int size){
    for (int i = 0; i < size; ++i) {
        printf("%d\n", ptr[i]);
    }
}
int main() {
    int N;
    printf("N = ");
    scanf("%d", &N);
    printf("\n");

    int* array = malloc(N * sizeof (int));
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }

    printArray(array, N);

    free(array);

    return 0;
}
