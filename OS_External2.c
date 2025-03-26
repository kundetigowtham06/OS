#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int isSafe(int processes[], int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int need[][MAX_RESOURCES], int n, int m) {
    int finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];

    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = processes[i];
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is in an unsafe state!\n");
            return 0;
        }
    }

    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;
}

int main() {
    int processes[MAX_PROCESSES] = {0, 1, 2, 3, 4};
    int available[MAX_RESOURCES] = {3, 3, 2};

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int need[MAX_PROCESSES][MAX_RESOURCES];
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    isSafe(processes, available, max, allocation, need, MAX_PROCESSES, MAX_RESOURCES);

    return 0;
}
