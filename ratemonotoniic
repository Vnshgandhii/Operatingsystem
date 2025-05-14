#include <stdio.h>

struct Process {
    int id, bt, ct, tat, wt, period;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process ps[n];

    for (int i = 0; i < n; i++) {
        ps[i].id = i + 1;
        printf("Enter Burst Time and Period for Process %d: ", i + 1);
        scanf("%d %d", &ps[i].bt, &ps[i].period);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ps[i].period > ps[j].period) {
                struct Process temp = ps[i];
                ps[i] = ps[j];
                ps[j] = temp;
            }
        }
    }

    int currentTime = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;

    while (completed < n) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (ps[i].bt > 0) {
                done = 0;
                currentTime += ps[i].bt;
                ps[i].ct = currentTime;
                ps[i].tat = ps[i].ct;
                ps[i].wt = ps[i].tat - ps[i].bt;
                totalTAT += ps[i].tat;
                totalWT += ps[i].wt;
                completed++;
            }
        }
        if (done) {
            break;
        }
    }

    printf("\nProcess\tBT\tPeriod\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               ps[i].id, ps[i].bt, ps[i].period, ps[i].ct, ps[i].tat, ps[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    printf("Average Waiting Time: %.2f\n", totalWT / n);

    return 0;
}
