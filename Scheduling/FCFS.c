#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10];
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; 
    tat[0] = bt[0]; 

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i]; 
        wtavg += wt[i];
        tatavg += tat[i];
    }

    wtavg += wt[0]; 
    tatavg += tat[0]; 
    wtavg /= n;
    tatavg /= n;

    printf("Average Waiting Time = %.2f\n", wtavg);
    printf("Average Turnaround Time = %.2f\n", tatavg);

    return 0;
}
