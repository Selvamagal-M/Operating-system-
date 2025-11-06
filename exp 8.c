#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes and Time Quantum: ");
    if (scanf("%d%d", &n, &tq) != 2 || n <= 0 || tq <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Using VLA is common in competitive programming, but safer to use malloc for production code.
    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    
    for (int i = 0; i < n; i++) {
        printf("P%d AT BT: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    
    int time = 0; // Current time
    int remain = n; // Number of processes remaining
    int i = 0; // Process index (to cycle through processes)
    int completed_cycle_without_work = 0; // Check to prevent an infinite loop if some processes haven't arrived yet
    
    // --- Round Robin Scheduling Logic ---
    while (remain > 0) {
        // 1. Check if the current process is ready (has remaining time AND has arrived)
        if (rt[i] > 0 && at[i] <= time) {
            
            // 2. Process is ready, execute it
            int run_time = (rt[i] > tq) ? tq : rt[i];
            
            time += run_time; // Advance time
            rt[i] -= run_time; // Decrease remaining time
            
            completed_cycle_without_work = 0; // Reset as work was done
            
            // 3. Check for completion
            if (rt[i] == 0) {
                ct[i] = time;
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];
                remain--;
            }
        } 
        // 4. Move to the next process cyclically (i+1)%n
        i = (i + 1) % n;

        // 5. If we have cycled through all processes (i is back to 0) AND no work was done
        // it means all remaining processes haven't arrived yet. We must advance time.
        if (i == 0) {
            if (completed_cycle_without_work < n) {
                // If the loop cycled through and didn't run, increment the counter
                completed_cycle_without_work++;
            } else {
                // If we've fully looped through N times and found no process to run (i.e., time is behind ATs),
                // find the next process arrival time and jump the clock.
                int next_arrival_time = -1;
                for (int j = 0; j < n; j++) {
                    if (rt[j] > 0) {
                        if (next_arrival_time == -1 || at[j] < next_arrival_time) {
                            next_arrival_time = at[j];
                        }
                    }
                }
                
                if (next_arrival_time > time) {
                    time = next_arrival_time; // Jump time to the arrival of the next ready process
                    completed_cycle_without_work = 0; // Reset after time jump
                }
            }
        }
    }
    
    // --- Output Results ---
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    float twt = 0, ttat = 0;
    for (int j = 0; j < n; j++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", j + 1, at[j], bt[j], ct[j], tat[j], wt[j]);
        twt += wt[j];
        ttat += tat[j];
    }
    printf("\nAvg WT = %.2f\nAvg TAT = %.2f\n", twt / n, ttat / n);
    return 0;
}
