
 #include <stdio.h>
#include <limits.h>


typedef struct {
    int id, arrival, burst, remaining, completion, turnaround, waiting;
} Process;

// Function to sort processes based on arrival time
void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}


void sjf_preemptive(Process p[], int n, float *avgTAT, float *avgWT) {
    int completed = 0, time = 0, minIdx, totalTAT = 0, totalWT = 0;
    int isCompleted[n];
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
        p[i].remaining = p[i].burst;
    }
    
    while (completed < n) {
        minIdx = -1;
        int minBurst = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && p[i].arrival <= time && p[i].remaining < minBurst && p[i].remaining > 0) {
                minBurst = p[i].remaining;
                minIdx = i;
            }
        }
        if (minIdx == -1) { time++; continue; }
        
        p[minIdx].remaining--;
        time++;
        if (p[minIdx].remaining == 0) {
            p[minIdx].completion = time;
            p[minIdx].turnaround = p[minIdx].completion - p[minIdx].arrival;
            p[minIdx].waiting = p[minIdx].turnaround - p[minIdx].burst;
            isCompleted[minIdx] = 1;
            totalTAT += p[minIdx].turnaround;
            totalWT += p[minIdx].waiting;
            completed++;
        }
    }
    *avgTAT = (float)totalTAT / n;
    *avgWT = (float)totalWT / n;
}


void display(Process p[], int n, float avgTAT, float avgWT) {
    printf("\nPID Arrival Burst Completion Turnaround Waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%3d %7d %6d %10d %10d %8d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }
    printf("\nAverage Turnaround Time: %.2f", avgTAT);
    printf("\nAverage Waiting Time: %.2f\n", avgWT);
}

int main() {
    int n;
    float avgTAT, avgWT;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process p[n];
    
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P[%d]: ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
    }
    
    printf("\nShortest Job First (Preemptive) Scheduling\n");
    sjf_preemptive(p, n, &avgTAT, &avgWT);
    display(p, n, avgTAT, avgWT);
    
    return 0;
}
