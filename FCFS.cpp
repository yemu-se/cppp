

#include <iostream>
using namespace std;

struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int waiting;    // Waiting Time
    int turnaround; // Turnaround Time
};

// Simple queue implementation using array
struct Queue {
    Process data[100]; // Max 100 processes
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(Process p) {
        data[++rear] = p;
    }

    Process dequeue() {
        return data[front++];
    }
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of processes.\n";
        return 1;
    }

    Process processes[100];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << processes[i].pid << ": ";
        cin >> processes[i].arrival >> processes[i].burst;

        if (processes[i].arrival < 0 || processes[i].burst <= 0) {
            cout << "Invalid input. Arrival >= 0, Burst > 0.\n";
            return 1;
        }
    }

    // Sort by arrival time (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival > processes[j + 1].arrival) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    Queue q;
    int currentTime = 0;
    int index = 0;
    double totalWT = 0, totalTAT = 0;

    // FCFS simulation
    while (index < n || !q.isEmpty()) {
        // Add processes that have arrived
        while (index < n && processes[index].arrival <= currentTime) {
            q.enqueue(processes[index]);
            index++;
        }

        if (!q.isEmpty()) {
            Process p = q.dequeue();

            if (currentTime < p.arrival) {
                currentTime = p.arrival; // CPU idle until process arrives
            }

            p.waiting = currentTime - p.arrival;
            currentTime += p.burst;
            p.turnaround = p.waiting + p.burst;

            // Save updated values
            for (int i = 0; i < n; i++) {
                if (processes[i].pid == p.pid) {
                    processes[i] = p;
                    break;
                }
            }
        } else {
            currentTime++; // No process in queue, move time forward
        }
    }

    // Output results
    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t"
             << processes[i].arrival << "\t"
             << processes[i].burst << "\t"
             << processes[i].waiting << "\t"
             << processes[i].turnaround << "\n";
        totalWT += processes[i].waiting;
        totalTAT += processes[i].turnaround;
    }

    cout << "\nAverage Waiting Time: " << (totalWT / n);
    cout << "\nAverage Turnaround Time: " << (totalTAT / n) << "\n";

    return 0;
}
