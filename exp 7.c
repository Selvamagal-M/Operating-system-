
#include <stdio.h>

int main() {
    int n, i, j, time = 0, min, idx;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];
    for (i = 0; i < n; i++) {
        printf("P%d AT BT: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        done[i] = 0;
    }

    int completed = 0;
    while (completed < n) {
        min = 9999; idx = -1;
        for (i = 0; i < n; i++)
            if (!done[i] && at[i] <= time && bt[i] < min) {
                min = bt[i];
                idx = i;
            }

        if (idx == -1) { time++; continue; }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    float twt = 0, ttat = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
        twt += wt[i];
        ttat += tat[i];
    }

    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", twt/n, ttat/n);
    return 0;
}

