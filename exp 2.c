#include <stdio.h>

int main() {
    int n, bt[10], wt = 0, tat = 0, i;
    printf("No. of processes: ");
    scanf("%d", &n);
    printf("Burst times:\n");
    for(i = 0; i < n; i++) scanf("%d", &bt[i]);

    printf("P\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt, wt + bt[i]);
        tat += wt + bt[i];
        wt += bt[i];
    }
    printf("Avg WT: %.2f\n", (float)(wt - bt[n-1]) / n);
    printf("Avg TAT: %.2f\n", (float)tat / n);
    return 0;
}
