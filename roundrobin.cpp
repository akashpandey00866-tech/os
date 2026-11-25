
#include <iostream>
using namespace std;

void findWaitingTime(int *bt, int *wt, int n, int quantum)
{
    int *rem_bt = new int[n];

    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;

    while (true)
    {
        bool done = true;

        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;

                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    delete[] rem_bt;
}

void findTurnAroundTime(int *bt, int *wt, int *tat, int n)
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTime(int *bt, int n, int quantum)
{
    int *wt = new int[n];
    int *tat = new int[n];

    int total_wt = 0, total_tat = 0;

    findWaitingTime(bt, wt, n, quantum);
    findTurnAroundTime(bt, wt, tat, n);

    cout << "\nPN\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];

        cout << "P" << i + 1 << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = "
         << (float)total_wt / n;

    cout << "\nAverage Turnaround Time = "
         << (float)total_tat / n;

    delete[] wt;
    delete[] tat;
}

int main()
{
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    int *bt = new int[n];

    cout << "Enter Burst Time of processes:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    findAvgTime(bt, n, quantum);

    delete[] bt;

    return 0;
}
