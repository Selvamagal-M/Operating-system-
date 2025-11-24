#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[20], p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i] = p[j];   p[j] = temp;
            }
        }
    }

    printf("\nExecution Order: ");
    for(i = 0; i < n; i++)
        printf("P%d ", p[i]);

    return 0;
}

