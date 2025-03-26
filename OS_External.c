#include <stdio.h>

int main() {
    int available[3], work[3], max[5][3], allocation[5][3], need[5][3], safe[5], totalres[3];
    char finish[5];
    int i, j, k, totalloc = 0, state, value = 0;

    // Input total instances of each resource
    printf("Enter Instances of each Resource:\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &totalres[i]);
    }

    // Input maximum resources for each process
    printf("Enter Maximum resources for each processes:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter process %d Resource %d: ", i, j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    // Input number of resources allocated to each process
    printf("Enter number of resources allocated to each Process:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter the resource of R%d allocated to process %d: ", j + 1, i);
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculate 'need' matrix
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Mark all processes as 'unfinished'
    for (i = 0; i < 5; i++) {
        finish[i] = 'f';
    }

    // Calculate available resources
    for (i = 0; i < 3; i++) {
        totalloc = 0;
        for (j = 0; j < 5; j++) {
            totalloc += allocation[j][i];
        }
        available[i] = totalres[i] - totalloc;
        work[i] = available[i];
    }

    // Display matrices
    printf("\nAllocated Resources:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Resources:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nNeeded Resources:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources:\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    // Banker's Algorithm
    while (value < 5) {
        state = 0; // Assume no process can proceed

        for (i = 0; i < 5; i++) {
            if (finish[i] == 'f') {
                // Check if need can be satisfied with available resources
                for (j = 0; j < 3; j++) {
                    if (need[i][j] > work[j]) {
                        state = 0;
                        break;
                    }
                    state = 1;
                }

                if (state == 1) {
                    // Allocate resources
                    for (j = 0; j < 3; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 't'; // Mark process as finished
                    safe[value++] = i; // Add process to safe sequence
                }
            }
        }

        if (state == 0) {
            break; // No process can proceed
        }
    }

    // Display Safe State Sequence
    if (value == 5) {
        printf("\nSafe States are:\n");
        for (i = 0; i < 5; i++) {
            printf("P%d ", safe[i]);
        }
        printf("\n");
    } else {
        printf("\nSystem is not in a safe state.\n");
    }

    return 0;
}
