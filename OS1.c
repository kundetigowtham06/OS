#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
    char buff[100];
    DIR *dir;
    struct dirent *dptr;  
    printf("Enter directory name: ");
    scanf("%s", buff);  
    dir = opendir(buff);
    if(dir == NULL){
        printf("Directory not found or could not be opened\n");
        return 1;  
    }

    printf("Contents of Directory: %s\n", buff);

    int found = 0;
    while((dptr = readdir(dir)) != NULL){


            printf("%s\n", dptr->d_name);
            found = 1;
        
    }

    if (!found) {
        printf("Directory is empty.\n");
    }

    closedir(dir);
    return 0;
}
