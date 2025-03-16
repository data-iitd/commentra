#include <iostream>
#include <queue>

using namespace std;

// Define a custom struct for tasks
struct task {
    // Name of the task
    string name;
    // Time taken by the task
    int time;
};

int main()
{
    int n, q; // Number of tasks and queries
    int elaps = 0; // Elapsed time
    queue<task> Q; // Queue to store tasks

    // Read number of tasks and queries from standard input
    cin >> n >> q;

    // Read tasks details and add them to the queue
    for(int i = 0; i < n; i++) {
        task tmp; // Create a new task
        cin >> tmp.name >> tmp.time; // Read task name and time from standard input
        Q.push(tmp); // Add the task to the queue
    }

    // Process tasks in the queue until it is empty
    while(!Q.empty()) {
        task p = Q.front(); Q.pop(); // Get the task at the front of the queue

        // Check if the current task can be completed within the given query time
        if(p.time <= q) {
            elaps += p.time; // Add the time taken by the task to the elapsed time
            cout << p.name << " " << elaps << endl; // Print the name and elapsed time of the task
        }
        else { // If the current task cannot be completed within the given query time
            // Subtract the query time from the time taken by the task
            p.time -= q;
            // Add the task back to the queue with updated time
            Q.push(p);
        }
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}
