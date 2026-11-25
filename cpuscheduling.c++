#include <iostream>
#include <iomanip>
using namespace std;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        cout << "\nProcess P" << p[i].pid << endl;

        cout << "Enter Arrival Time: ";
        cin >> p[i].arrivalTime;

        cout << "Enter Burst Time: ";
        cin >> p[i].burstTime;

        cout << "Enter Priority: ";
        cin >> p[i].priority;

        p[i].remainingTime = p[i].burstTime;
        p[i].completionTime = 0;
        p[i].turnaroundTime = 0;
        p[i].waitingTime = 0;
    }

    int completed = 0;
    int currentTime = 0;

    // Preemptive Priority Scheduling
    while (completed < n)
    {
        int selected = -1;
        int highestPriority = 9999;

        // Find highest priority process
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrivalTime <= currentTime &&
                p[i].remainingTime > 0)
            {
                // Smaller number = higher priority
                if (p[i].priority < highestPriority)
                {
                    highestPriority = p[i].priority;
                    selected = i;
                }
            }
        }

        // No process has arrived
        if (selected == -1)
        {
            currentTime++;
            continue;
        }

        // Execute for 1 unit
        p[selected].remainingTime--;
        currentTime++;

        // Process completed
        if (p[selected].remainingTime == 0)
        {
            p[selected].completionTime = currentTime;

            p[selected].turnaroundTime =
                p[selected].completionTime - p[selected].arrivalTime;

            p[selected].waitingTime =
                p[selected].turnaroundTime - p[selected].burstTime;

            completed++;
        }
    }

    // Calculate averages
    double totalTAT = 0;
    double totalWT = 0;

    for (int i = 0; i < n; i++)
    {
        totalTAT += p[i].turnaroundTime;
        totalWT += p[i].waitingTime;
    }

    double avgTAT = totalTAT / n;
    double avgWT = totalWT / n;

    // Display result
    cout << "\n\n========== PROCESS TABLE ==========\n";

    cout << left
         << setw(8) << "PID"
         << setw(8) << "AT"
         << setw(8) << "BT"
         << setw(10) << "Priority"
         << setw(8) << "CT"
         << setw(8) << "TAT"
         << setw(8) << "WT"
         << endl;

    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(8) << ("P" + to_string(p[i].pid))
             << setw(8) << p[i].arrivalTime
             << setw(8) << p[i].burstTime
             << setw(10) << p[i].priority
             << setw(8) << p[i].completionTime
             << setw(8) << p[i].turnaroundTime
             << setw(8) << p[i].waitingTime
             << endl;
    }

    cout << "\nAverage Turnaround Time = "
         << fixed << setprecision(2) << avgTAT;

    cout << "\nAverage Waiting Time = "
         << fixed << setprecision(2) << avgWT << endl;

    return 0;
}