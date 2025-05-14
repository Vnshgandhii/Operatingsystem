#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    int alloc[n][m], max[n][m], avail[m];
    int finish[n], work[m];
    int count = 0;

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    for (int i = 0; i < n; i++)
        finish[i] = 0;

    int changed;
    do {
        changed = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (int j = 0; j < m; j++) {
                    int need = max[i][j] - alloc[i][j];
                    if (need > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    finish[i] = 1;
                    printf("Process %d can finish.\n", i + 1);
                    changed = 1;
                }
            }
        }
    } while (changed);

    int deadlock = 0;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock = 1;
            printf("Process %d is in deadlock.\n", i + 1);
        }
    }

    if (!deadlock) {
        printf("System is not in a deadlock state.\n");
    }

    return 0;
}
