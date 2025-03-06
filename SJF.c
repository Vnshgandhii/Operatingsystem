#include<stdio.h>
#include<stdbool.h>

struct process
{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int start_time;
} ps[100];

int main()
{
    float totalTAT = 0, totalWT = 0;
    int n;
    int completed = 0;
    bool is_visited[100] = {false};
    int current_time = 0;
    int minimum = 9999999999;
    int min_index = -1;

    printf("Enter the number of process to enter : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\n Enter the arrival time of process [%d] : ", i + 1);
        scanf("%d", &ps[i].at);
    }

    for(int i = 0; i < n; i++)
    {
        printf("\n Enter the burst time of process [%d] : ", i + 1);
        scanf("%d", &ps[i].bt);
    }

    while(completed != n)
    {
        minimum = 2147483647;
        min_index = -1;

        for(int i = 0; i < n; i++)
        {
            if(ps[i].at <= current_time && !is_visited[i])
            {
                if(ps[i].bt < minimum)
                {
                    minimum = ps[i].bt;
                    min_index = i;
                }

                if(ps[i].bt == minimum)
                {
                    if(ps[i].at < ps[min_index].at)
                    {
                        minimum = ps[i].bt;
                        min_index = i;
                    }
                }
            }
        }

        if(min_index == -1)
        {
            current_time++;
        }
        else
        {
            ps[min_index].start_time = current_time;
            ps[min_index].ct = ps[min_index].start_time + ps[min_index].bt;
            ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
            totalTAT += ps[min_index].tat;
            ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;
            totalWT += ps[min_index].wt;
            is_visited[min_index] = true;
            completed++;
            current_time = ps[min_index].ct;
        }
    }

    printf("\n The average TAT is : %.2f ms", totalTAT / n);
    printf("\n The average WT is : %.2f ms\n\n\n", totalWT / n);

}
