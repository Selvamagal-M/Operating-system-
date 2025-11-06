
#include <stdio.h>

void allocate(char* name, int strategy) {
    int blocks[5] = {100, 500, 200, 300, 600};
    int pro[4] = {212, 417, 112, 426}, alloc[4] = {-1, -1, -1, -1};
     
     int i,j;
    for (i = 0; i < 4; i++) {
        int idx = -1;
        for ( j = 0; j < 5; j++) {
            if (blocks[j] >= pro[i]) {
                if (strategy == 0) { idx = j; break; }
                if (strategy == 1 && (idx == -1 || blocks[j] < blocks[idx])) idx = j;
                if (strategy == 2 && (idx == -1 || blocks[j] > blocks[idx])) idx = j;
            }
        }
        if (idx != -1) { alloc[i] = idx; blocks[idx] -= pro[i]; }
    }

    printf("\n%s Fit:\n", name);
    for (int i = 0; i < 4; i++)
        printf("Process %d -> %s\n", i + 1, alloc[i] != -1 ? "Allocated" : "Not Allocated");
}

int main() {
    allocate("First", 0);
    allocate("Best", 1);
    allocate("Worst", 2);
    return 0;
}

