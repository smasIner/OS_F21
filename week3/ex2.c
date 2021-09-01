#include <stdio.h>
/**
 * It sorts the array of integers inplace in descending order. Uses pointer to the array to sort it inside 
 * the function
 * @param arr   Array to be sorted
 * @param n     Number of elements in the array
 */
void bubbleSortInplace(int arr[], int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the number of element in the array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    bubbleSortInplace(arr, n);
    printf("The sorted array(in descending order): \n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
