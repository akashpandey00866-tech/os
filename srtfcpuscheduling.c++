#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];
    // Input process details
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "\n Enter Arrival Time for P" << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for P" << pid[i] << ": ";
        cin >> bt[i];
        // Initially, Remaining Time = Burst Time
        rt[i] = bt[i];
        ct[i] = 0;
        tat[i] = 0;
        wt[i] = 0;
    }
    int completed = 0;
    int currentTime = 0;
  // Continue until all processes are completed
    while (completed < n)
    {
        int shortest = -1;
        int minRemainingTime = 9999;
        // Find process with shortest remaining time
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= currentTime && rt[i] > 0)
            {
                if (rt[i] < minRemainingTime)
                {
                    minRemainingTime = rt[i];
                    shortest = i;
                }
            }
        }
        // If no process has arrived yet
        if (shortest == -1)
        {
            currentTime++;
        }
        else
        {
            // Execute the selected process for 1 unit of time
            rt[shortest]--;
            currentTime++;
            // Process completed
            if (rt[shortest] == 0)
            {
                completed++;
                // Completion Time
                ct[shortest] = currentTime;
                // Turnaround Time = Completion Time - Arrival Time
                tat[shortest] = ct[shortest] - at[shortest];
                // Waiting Time = Turnaround Time - Burst Time
                wt[shortest] = tat[shortest] - bt[shortest];
            }
        }
    }
    // Display results
    cout << "\n\n===== SRTF Scheduling =====\n";
    cout << left
         << setw(10) << "Process"
         << setw(12) << "Arrival"
         << setw(12) << "Burst"
         << setw(12) << "Completion"
         << setw(12) << "Turnaround"
         << setw(12) << "Waiting"
         << endl;
    float totalTAT = 0;
    float totalWT = 0;
    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(10) << ("P" + to_string(pid[i]))
             << setw(12) << at[i]
             << setw(12) << bt[i]
             << setw(12) << ct[i]
             << setw(12) << tat[i]
             << setw(12) << wt[i]
             << endl;
        totalTAT += tat[i];
        totalWT += wt[i];
    }
    cout << "\nAverage Turnaround Time = "
         << totalTAT / n;
    cout << "\nAverage Waiting Time = "
         << totalWT / n;
    return 0;
}
