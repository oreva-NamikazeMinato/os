#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

// Function to perform Round Robin scheduling
void roundRobin(struct Process processes[], int n, int quantum) {
    int time = 0; // Current time

    // Continue scheduling until all processes are done
    while (1) {
        int done = 1; // Flag to check if all processes are done

        // Traverse the processes
        for (int i = 0; i < n; i++) {
            // If the process still has remaining time
            if (processes[i].remaining_time > 0) {
                done = 0; // At least one process is not done

                // Execute the process for the quantum or the remaining time, whichever is smaller
                int execute_time = (processes[i].remaining_time > quantum) ? quantum : processes[i].remaining_time;
                processes[i].remaining_time -= execute_time;
                time += execute_time;

                printf("Time %d: Process %d executed for %d units. Remaining time: %d\n", time, processes[i].id, execute_time, processes[i].remaining_time);
            }
        }

        // If all processes are done, break from the loop
        if (done == 1) {
            break;
        }
    }
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n]; // Array of processes

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int quantum; // Time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Perform Round Robin scheduling
    roundRobin(processes, n, quantum);

    return 0;
}
