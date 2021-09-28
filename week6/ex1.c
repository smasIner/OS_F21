#include <stdio.h>
struct process{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};
void inputData(struct process processes[], int numberOfProcesses){
    for (int i = 0; i < numberOfProcesses; ++i) {
        int tempA, tempB;
        printf("################\n");
        printf("Process %d: \n", i + 1);
        printf("Enter the Arrival Time: ");
        scanf("%d", &tempA);
        printf("\n");
        printf("Enter the Burst Time: ");
        scanf("%d", &tempB);
        processes[i].arrivalTime = tempA;
        processes[i].burstTime = tempB;
    }
}

void sortTimesArrival(struct process processes[], int numberOfProcesses){
    for (int i = 0; i < numberOfProcesses - 1; ++i) {
        for (int j = 0; j < numberOfProcesses - 1; ++j) {
            if(processes[j].arrivalTime > processes[j+1].arrivalTime){
                struct process temp;
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

void sortTimesBurst(struct process processes[], int numberOfProcesses){
    for (int i = 0; i < numberOfProcesses - 1; ++i) {
        for (int j = 0; j < numberOfProcesses - 1; ++j) {
            if(processes[j].burstTime > processes[j+1].burstTime){
                struct process temp;
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

void setId(struct process processes[], int numberOfProcesses){
    for (int i = 0; i < numberOfProcesses; ++i) {
        processes[i].id = i + 1;
    }
}

int computeWaiting(struct process processes[], int n){
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if(i > 1 && processes[i-1].waitingTime == 0 && processes[i-2].waitingTime == 0){
            k = i-1;
        }
        int wt = processes[k].arrivalTime;
        for (int j = k; j < i; ++j) {
            wt += processes[j].burstTime;
        }
        wt -= processes[i].arrivalTime;
        if(wt<0){
            wt = 0;
        }
        processes[i].waitingTime = wt;
    }
}
int computeCompletionTime(struct process processes[], int numberOfProcesses){
    for (int i = 0; i < numberOfProcesses; ++i) {
        processes[i].completionTime = processes[i].turnaroundTime + processes[i].arrivalTime;
    }
}
int computeTurnaroundTime(struct process processes[], int numberOfProcesses){
    for (int i = 0; i < numberOfProcesses; ++i) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}
void outputAverages(struct process processes[], int numberOfProcesses){
    printf("//////////////////\n");
    double avgTAT = 0;
    double avgWT = 0;
    for (int i = 0; i < numberOfProcesses; ++i) {
        avgTAT = processes[i].turnaroundTime;
        avgWT = processes[i].waitingTime;
    }
    avgTAT = avgTAT/numberOfProcesses;
    avgWT = avgWT/numberOfProcesses;
    printf("Average Waiting time: %f\n", avgWT);
    printf("Average Turnaround time: %f\n", avgTAT);
    printf("/////////////////\n\n");

}
void outputData(struct process processes[], int numberOfProcesses){
    printf("***********************\n");
    printf("***********************\n");
    for (int i = 0; i < numberOfProcesses; ++i) {
        printf("***********************\n");
        printf("Process: %d\n", processes[i].id);
        printf("Arrival time: %d\n", processes[i].arrivalTime);
        printf("Burst time: %d\n", processes[i].burstTime);
        printf("Waiting time: %d\n", processes[i].waitingTime);
        printf("Turnaround time: %d\n", processes[i].turnaroundTime);
        printf("Completion time: %d\n", processes[i].completionTime);
        printf("\n");
    }
}
int main() {
    // int quantum = 3; // read from the user
    int numberOfProcesses;

    printf("N = ");
    scanf("%d", &numberOfProcesses);
    printf("\n");

    struct process processes[numberOfProcesses];

    inputData(processes, numberOfProcesses);

    sortTimesArrival(processes, numberOfProcesses);
    setId(processes,numberOfProcesses);

    computeWaiting(processes, numberOfProcesses);
    computeTurnaroundTime(processes, numberOfProcesses);
    computeCompletionTime(processes, numberOfProcesses);

    outputData(processes, numberOfProcesses);
    outputAverages(processes, numberOfProcesses);

    return 0;
}
