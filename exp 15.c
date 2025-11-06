#include <stdio.h>
#include <string.h>

struct File {
    char name[20];
};

struct Directory {
    char name[20];
    struct File files[10];
    int fileCount;
};

int main() {
    struct Directory dirs[5];
    int dirCount = 0;
    int choice;
    char dname[20], fname[20];

    while (1) {
        printf("\n1. Create Directory\n2. Create File\n3. List\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter directory name: ");
            scanf("%s", dirs[dirCount].name);
            dirs[dirCount].fileCount = 0;
            dirCount++;
            break;
        case 2:
            printf("Enter directory name: ");
            scanf("%s", dname);
            int i;
            for ( i = 0; i < dirCount; i++) {
                if (strcmp(dname, dirs[i].name) == 0) {
                    printf("Enter file name: ");
                    scanf("%s", dirs[i].files[dirs[i].fileCount].name);
                    dirs[i].fileCount++;
                    break;
                }
            }
            break;
        case 3:
            for (i = 0; i < dirCount; i++) {
                printf("\nDirectory: %s\n", dirs[i].name);
                int j;
                for ( j = 0; j < dirs[i].fileCount; j++) {
                    printf("  File: %s\n", dirs[i].files[j].name);
                }
            }
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}
