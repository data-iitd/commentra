#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>

// Define a structure to represent a task with a name and time
struct task {
    char name[100]; // Name of the task
    int time;    // Time required to complete the task
};

int main()
{
    int n, q; // n: number of tasks, q: time quantum
    int elaps = 0; // Variable to keep track of elapsed time
    task *Q; // Queue to manage tasks in a FIFO manner

    // Read the number of tasks and the time quantum from input
    scanf("%d %d", &n, &q);

    // Read each task's name and time, and add it to the queue
    Q = (task *)malloc(n * sizeof(task));
    for(int i = 0; i < n; i++) {
        scanf("%s %d", Q[i].name, &Q[i].time); // Input task name and time
    }

    // Process tasks until the queue is empty
    while(n > 0) {
        task p = Q[0]; // Get the task at the front of the queue
        n--; // Decrease the number of tasks in the queue
        // Check if the task can be completed within the time quantum
        if(p.time <= q) {
            elaps += p.time; // Update elapsed time
            printf("%s %d\n", p.name, elaps); // Output task name and total elapsed time
        }
        else {
            // If the task cannot be completed, reduce its time and re-add it to the queue
            p.time -= q; // Decrease the remaining time of the task
            elaps += q; // Update elapsed time by the time quantum
            Q[n] = p; // Re-add the task to the queue for further processing
        }
    }
    return 0; // Exit the program
}
