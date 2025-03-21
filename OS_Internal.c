#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100
#define MAX_FILES 10

typedef struct {
    char fileName[20];
    int startBlock;
    int length;
} File;

int main() {
    int disk[MAX_BLOCKS] = {0};
    File files[MAX_FILES];
    int numFiles = 0;

    printf("Enter the number of files (max %d): ", MAX_FILES);
    scanf("%d", &numFiles);

    if (numFiles > MAX_FILES) {
        printf("Error: Number of files exceeds maximum limit of %d.\n", MAX_FILES);
        return 1;
    }

    for (int i = 0; i < numFiles; i++) {
        printf("\nEnter file name: ");
        scanf("%s", files[i].fileName);

        printf("Enter starting block of the file (0 to %d): ", MAX_BLOCKS - 1);
        scanf("%d", &files[i].startBlock);

        printf("Enter number of blocks required: ");
        scanf("%d", &files[i].length);

        if (files[i].startBlock < 0 || files[i].length <= 0 || 
            files[i].startBlock + files[i].length > MAX_BLOCKS) {
            printf("Error: Invalid input for file '%s'.\n", files[i].fileName);
            i--; // Retry this file
            continue;
        }

        int isFree = 1;
        for (int j = files[i].startBlock; j < files[i].startBlock + files[i].length; j++) {
            if (disk[j] == 1) {
                isFree = 0;
                break;
            }
        }

        if (isFree) {
            for (int j = files[i].startBlock; j < files[i].startBlock + files[i].length; j++) {
                disk[j] = 1;
            }
            printf("File '%s' allocated successfully.\n", files[i].fileName);
        } else {
            printf("Error: Not enough contiguous blocks available for file '%s'.\n", files[i].fileName);
            i--; // Retry this file
        }
    }

    printf("\nFile Allocation Table:\n");
    printf("File Name\tStart Block\tLength\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%s\t\t%d\t\t%d\n", files[i].fileName, files[i].startBlock, files[i].length);
    }

    return 0;
}
