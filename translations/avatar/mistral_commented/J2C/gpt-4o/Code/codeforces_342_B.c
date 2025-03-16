#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 1000
#define MAX_ACTIONS 10000

typedef struct {
    int arrival;
    int departure;
} Thread;

int main() {
    int m, s, f;
    scanf("%d %*d %d %d", &m, &s, &f); // Read the number of methods, start position, and finish position

    Thread threads[MAX_THREADS]; // Array to store thread information
    int maxT = -1; // Initialize maximum thread ID

    // Read the remaining lines of input and store the thread IDs and their arrival and departure times
    for (int i = 0; i < m; i++) {
        int k, arrival, departure;
        scanf("%d %d %d", &k, &arrival, &departure);
        threads[k].arrival = arrival; // Store arrival time
        threads[k].departure = departure; // Store departure time
        if (k > maxT) {
            maxT = k; // Update the maximum thread ID
        }
    }

    char actions[MAX_ACTIONS]; // Array to store the output actions
    int actionIndex = 0; // Index for actions array
    char M = (s < f) ? 'R' : 'L'; // Determine the direction of the simulation
    int d = (s < f) ? 1 : -1; // Determine the direction of the simulation as 1 for right and -1 for left
    int cur = s; // Initialize the current position

    // Simulate the execution of threads and generate the output
    for (int t = 1; t <= maxT; t++) {
        if (threads[t].arrival != 0 || threads[t].departure != 0) { // Check if there is a thread with the given ID
            int a = threads[t].arrival; // Get the arrival time of the thread
            int b = threads[t].departure; // Get the departure time of the thread

            if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) { // Check if the current position is within the execution time of the thread
                actions[actionIndex++] = 'X'; // Append an 'X' to the output
            } else {
                actions[actionIndex++] = M; // Append the direction character to the output
                cur += d; // Move the current position in the direction of the simulation
            }

            if (cur == f) { // Break the loop if the finish position is reached
                break;
            }
        } else {
            actions[actionIndex++] = M; // Append the direction character to the output if there is no thread at the current position
            cur += d; // Move the current position in the direction of the simulation
        }
    }

    // Continue moving to the finish position if not reached
    while (cur != f) {
        actions[actionIndex++] = M;
        cur += d;
    }

    actions[actionIndex] = '\0'; // Null-terminate the actions string
    printf("%s\n", actions); // Print the output to the console

    return 0;
}
