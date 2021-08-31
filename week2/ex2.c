#include <string.h>
#include <stdio.h>
int main(){
  char stringInitial [1000];
  scanf("%s", stringInitial);
  char tempHolder[1000];
    for (int i = strlen(stringInitial) - 1; i >=0 ; --i) {
        tempHolder[strlen(stringInitial) - i - 1] = stringInitial[i];
    }
  printf("%s", tempHolder);
  return 0;
}
