#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
  int integer;
  float fl;
  double dbl;
  integer = INT_MAX;
  fl = FLT_MAX;
  dbl = DBL_MAX;
  printf("%d\n %f\n %lf\n", integer, fl, dbl );
  return 0;
}

