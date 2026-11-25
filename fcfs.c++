//operating system expriment no-04

// Operating System Experiment No. 04
// FCFS Scheduling Algorithm

#include <iostream>
using namespace std;

int main()
{
    int n, bt[20], wt[20], tat[20];
    int avwt = 0, avtat = 0;

    cout << "Total number of processes (Maximum 20): ";
    cin >> n;

    cout << "\nEnter Burst Time of each process:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = 0;

        for (int j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        avwt += wt[i];
        avtat += tat[i];

        cout << "P[" << i + 1 << "]\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)avwt / n << endl;
    cout << "Average Turnaround Time = " << (float)avtat / n << endl;

    return 0;
}