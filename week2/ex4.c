#include <stdio.h>
void changeTwoNumbers(int *first, int *second){
    *first = -*first - *second;
    *second = -*first - *second;
    *first = -*first - *second;
}
int main(){
    printf("Enter Two integers to swap: \n");
    int first, second;
    scanf("%d %d",&first,&second);
    changeTwoNumbers(&first, &second);
    return 0;
}
