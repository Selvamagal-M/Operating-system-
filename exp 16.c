#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int choice, search_id;

    while (1) {
        printf("\n1.Add 2.View 3.Search 4.Exit: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fp = fopen("emp.dat", "ab");
            printf("Enter ID Name Salary: ");
            scanf("%d %s %f", &e.id, e.name, &e.salary);
            fwrite(&e, sizeof(e), 1, fp);
            fclose(fp);
            break;

        case 2:
            fp = fopen("emp.dat", "rb");
            while (fread(&e, sizeof(e), 1, fp))
                printf("%d %s %.2f\n", e.id, e.name, e.salary);
            fclose(fp);
            break;

        case 3:
            fp = fopen("emp.dat", "rb");
            printf("Enter ID to search: ");
            scanf("%d", &search_id);
            while (fread(&e, sizeof(e), 1, fp)) {
                if (e.id == search_id) {
                    printf("Found: %d %s %.2f\n", e.id, e.name, e.salary);
                    break;
                }
            }
            fclose(fp);
            break;

        case 4:
            exit(0);
        }
    }
}
