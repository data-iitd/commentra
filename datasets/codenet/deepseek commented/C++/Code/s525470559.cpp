#include <iostream>  // Include the iostream library for input and output operations.
#include <queue>     // Include the queue library for using the queue data structure.

using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'.

struct task {       // Define a struct named 'task' to hold the name and time for each task.
    string name;     // The name of the task.
    int time;        // The time required to complete the task.
};

int main()          // The main function is where the program execution begins.
{
    int n, q;        // Declare variables for the number of tasks, the time quantum, and the elapsed time.
    int elaps = 0;   // Initialize the elapsed time to 0.
    queue<task> Q;   // Declare a queue of tasks.

    cin >> n >> q;   // Read the number of tasks and the time quantum from the standard input.

    for(int i = 0; i < n; i++) { // Loop to read each task's name and time.
        task tmp;                // Create a temporary task object.
        cin >> tmp.name >> tmp.time; // Read the task's name and time from the standard input.
        Q.push(tmp);             // Push the task into the queue.
    }

    while(!Q.empty()) { // Process each task in the queue until it is empty.
        task p = Q.front(); Q.pop(); // Get the front task from the queue and remove it from the queue.
        if(p.time <= q) { // Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += p.time; // Update the elapsed time by adding the task's remaining time.
            cout << p.name << " " << elaps << endl; // Print the task's name and the current elapsed time.
        }
        else { // If the task's remaining time is greater than the time quantum.
            p.time -= q; // Reduce the task's remaining time by the time quantum.
            elaps += q;  // Update the elapsed time by adding the time quantum.
            Q.push(p);   // Push the task back into the queue with the remaining time.
        }
    }
    return 0; // Return 0 to indicate successful execution of the program.
}
