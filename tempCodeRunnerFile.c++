#include<bits/stdc++.h>
using namespace std;
int  main(){
    int n, bt[20],wt[20],tat[20];

    cout<<"Enter total  number of processes: ";
    cin>>n;
    cout<<"Enter Process Burst Time: ";
    for(int i=0;i<n;i++){
        cout<<"P["<<i+1<<"]: ";
        cin>>bt[i];
    }
}
//first process has no waiting time
    //calculate waiting time
    for(int i=1;i<n;i++){
        wt[i]=0;
    
        for(int j=0;j<i;j++)
            wt[i]+=bt[j];
        
    }
    cout<<"Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    //calculate turnaround time
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"P["<<i+1<<"]\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    //calculate average waiting time and average turnaround time
    double avgWaitingTime = (double)avwt/n;
    double avgTurnaroundTime = (double)avtat/n;
    cout<<"Average Waiting Time: "<<avgWaitingTime<<endl;
    cout<<"Average Turnaround Time: "<<avgTurnaroundTime<<endl;
    return 0;