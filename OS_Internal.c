#include<stdio.h>
#include<string.h>

#define maxF 10
#define maxB 100
typedef struct{
	char filename[20];
	int startblock;
	int length;
}File;
int main(){
	int i,j;
	int disk[maxB]={0};
	File files[maxF];
	int n=0;
	char s[20];
	printf("\nEnter number of Files: ");
	scanf("%d",&n);
	if(n>maxF){
		printf("Error:Exceeds the maximum Limit");
	}
	for( i=0;i<n;i++){
		printf("\nEnter File name: ");
		scanf("%s",files[i].filename);
		printf("\nEnter starting block: ");
		scanf("%d",&files[i].startblock);
		printf("\nEnter number of blocks required: ");
		scanf("%d",&files[i].length);
	}
	printf("\nEnter File name to be search: ");
	scanf("%s",s);
	for( i=0;i<n;i++){
		if(strcmp(s,files[i].filename)==0)
			break;
	}
	if(i==n){
		printf("\nFile not found");
	}
	else{
		printf("\nFileName\tStartBlock\tNo.of.Blocks\tBlocks Occupied\n");
		printf("\n%s\t\t%d\t\t%d\t\t",files[i].filename,files[i].startblock,files[i].length);
		for(j=0;j<files[i].length;j++){
			printf("%d ",files[i].startblock+j);
			
		}
	}
}
