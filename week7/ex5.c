#include <stdlib.h>
#include <stdio.h>
int main() {
    char** s = malloc(sizeof(char*)); // fix by allocating needed memory
    char foo[] = "Hello World"; // no fix
    *s = foo; // no fix
    printf("s is %s\n", *s); // add asterisks before s for correct output (Hello world)
    s[0] = foo; // no fix
    printf("s[0] is %s\n", s[0]); // no fix
    return 0; // no fix
}
