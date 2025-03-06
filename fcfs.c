#include <stdio.h>
#define MAX 100
int arr[MAX];

int at[MAX];
int bt[MAX];
int ct[MAX];
int tat[MAX];
int wt[MAX];



int cnt = 0;
int main(){


    int n;
    printf("\nEnter the no of processes: ");
    scanf("%d",&n);



    for(int i=0; i<n; i++){

        int arrT,burT;

        printf("\nEnter the at and bt of %d th Process: ",i+1);
        scanf("%d%d",&arrT,&burT);

        at[cnt] = arrT;
        bt[cnt] = burT;

        cnt++;

    }

    //compute the CT
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += bt[i];
        ct[i] = sum;

    }


    //compute the TAT

    for(int i=0; i<n; i++){
        tat[i] = ct[i]-at[i];
        sum += tat[i];
    }

    float avgTat = sum / (float)n;
    printf("\nAvg Tata: %f",avgTat);



    for(int i=0; i<n; i++){
        wt[i] = tat[i]-bt[i];
        sum += wt[i];

    }


    float avgWt = sum / (float)n;
    printf("\nAvg Wt: %f",avgWt);





    // Output the TAT and WT

    printf("\nTAT: ");
    for(int i=0; i<n; i++)
        printf("%d ",tat[i]);

    printf("\nWT: ");
    for(int i=0; i<n; i++)
        printf("%d ",wt[i]);




    return 0;

}
