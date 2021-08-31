#include <stdio.h>
int main(int argc, char *argv[]){
    int n;
    sscanf(argv[1], "$d", &n);
    printf("%d", n);
  return 0;
}
