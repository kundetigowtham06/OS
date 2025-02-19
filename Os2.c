#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pid,pid1,pid2;
	pid=fork();
	if(pid==-1){
		printf("Error in creation of process");
		exit(1);
	}
	if(pid==0){
		pid1=getpid();
		printf("The parent process id is %d",pid1);
	}
	else{
		pid2=getpid();
		printf("\nThe child process id is %d",pid2);
	}
	return 0;
}
