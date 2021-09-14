#include <stdio.h>
#include <unistd.h>
/* SHELL script with the output:
 * smasiner@Murats-MacBook-Pro sh ex1.sh
Hello from parent [PID - 11998]
Hello from child [PID - 11999]
Hello from parent [PID - 12000]
Hello from child [PID - 12001]
Hello from parent [PID - 12002]
Hello from child [PID - 12003]
Hello from parent [PID - 12004]
Hello from child [PID - 12005]
Hello from parent [PID - 12006]
Hello from child [PID - 12007]
Hello from parent [PID - 12008]
Hello from child [PID - 12009]
Hello from parent [PID - 12010]
Hello from child [PID - 12011]
Hello from parent [PID - 12012]
Hello from child [PID - 12013]
Hello from parent [PID - 12014]
Hello from child [PID - 12015]
Hello from parent [PID - 12016]
Hello from child [PID - 12017]
smasiner@Murats-MacBook-Pro week4 %

 No missed children. But it is just luck, as parent does not wait for child.

 */
int main() {
    int  x = fork();
    if(x<0){
        printf("Mistake");
    }
    else if (x == 0){
        printf("Hello from child [PID - %d]\n", getpid());
    }
    else{
        printf("Hello from parent [PID - %d]\n", getpid());
    }
    return 0;
}
