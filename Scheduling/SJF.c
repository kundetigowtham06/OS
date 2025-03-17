#include<stdio.h>
int main(){
	int n,bt[10],ct[10],tat[10],wt[10],p[10];
	printf("Enter number of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        p[i]=i;
        printf("Enter burst time for process %d:",i);
        scanf("%d",&bt[i]);
    }
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            if(bt[j]>bt[k]){
                int temp=bt[j];
                bt[j]=bt[k];
                bt[k]=temp;
                int t=p[j];
                p[j]=p[k];
                p[k]=t;
            }
        }
    }
    float wtavg,tatavg;
    wt[0] = 0; 
    tat[0] = bt[0]; 

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i]; 
        wtavg += wt[i];
        tatavg += tat[i];
    }

    wtavg += wt[0]; 
    tatavg += tat[0]; 
    wtavg /= n;
    tatavg /= n;

    printf("Average Waiting Time = %.2f\n", wtavg);
    printf("Average Turnaround Time = %.2f\n", tatavg);

    return 0;
}
