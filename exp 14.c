
#include <stdio.h>
#include <string.h>

struct Directory {
    char fname[10][20];
    int count;
};

int main() {
    struct Directory dir;
    dir.count = 0;
    int choice;
    char name[20];

    while (1) {
        printf("\n1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                int exists = 0;
                int i;
            
                for ( i = 0; i < dir.count; i++) {
                    if (strcmp(name, dir.fname[i]) == 0) exists = 1;
                }
                if (exists) printf("File already exists!\n");
                else {
                    strcpy(dir.fname[dir.count], name);
                    dir.count++;
                    printf("File created.\n");
                }
                break;

            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", name);
                int found = 0,j;
                for (i = 0; i < dir.count; i++) {
                    if (strcmp(name, dir.fname[i]) == 0) {
                        for (j = i; j < dir.count - 1; j++)
                            strcpy(dir.fname[j], dir.fname[j + 1]);
                        dir.count--;
                        found = 1;
                        printf("File deleted.\n");
                        break;
                    }
                }
                if (!found) printf("File not found.\n");
                break;

            case 3:
                printf("Enter file name to search: ");
                scanf("%s", name);
                int present = 0;
                for (i = 0; i < dir.count; i++) {
                    if (strcmp(name, dir.fname[i]) == 0) {
                        printf("File found.\n");
                        present = 1;
                        break;
                    }
                }
                if (!present) printf("File not found.\n");
                break;

            case 4:
                printf("Files:\n");
                for (i = 0; i < dir.count; i++)
                    printf("%s\n", dir.fname[i]);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

