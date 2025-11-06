#include <stdio.h>

int main() {
    int n, bt[10], p[10], wt = 0, tat = 0, i, j, temp;
    printf("No. of processes: "); scanf("%d", &n);
    for(i = 0; i < n; i++) { printf("P%d BT: ", i+1); scanf("%d", &bt[i]); p[i] = i+1; }

    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(bt[j] < bt[i]) { temp = bt[i]; bt[i] = bt[j]; bt[j] = temp; temp = p[i]; p[i] = p[j]; p[j] = temp; }

    printf("P\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt, wt + bt[i]);
        tat += wt + bt[i];
        wt += bt[i];
    }

    printf("Avg WT: %.2f\nAvg TAT: %.2f\n", (float)(wt - bt[n-1]) / n, (float)tat / n);
    return 0;
}
