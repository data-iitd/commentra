#include <bits/stdc++.h>
using namespace std;

int main ( ) {
    int n, b;
    cin >> n >> b;
    // Read the number of tasks (n) and the buffer size (b) from the input.

    queue < pair < int, int > > remaining;
    bool running = false;
    int finish_time = 0;
    // Initialize a queue to store tasks waiting to be processed, a boolean flag to check if a task is running, and a variable to keep track of the finish time.

    map < int, int > result;
    // Initialize a dictionary to store the finish time of each task.

    for ( int i = 0 ; i < n ; i++ ) {
        int time, duration;
        cin >> time >> duration;
        Task task ( time, duration, i );
        result [ i ] = 0;
        if ( task.time > finish_time && remaining.empty ( ) ) {
            running = true;
            finish_time = task.time + task.duration;
            result [ i ] = finish_time;
        }
        else {
            if ( task.time >= finish_time &&!remaining.empty ( ) ) {
                finish_time, result = run_task ( remaining, finish_time );
            }
            if ( remaining.size ( ) < b ) {
                remaining.push ( task );
            }
            else {
                result [ i ] = -1;
            }
        }
    }
    // Read each task, create a Task object, and process it according to the specified rules:
    // - If the task's start time is greater than the current finish time and the queue is empty, start the task.
    // - If the task's start time is greater than or equal to the current finish time and the queue is not empty, finish the current task and start the new one.
    // - If the buffer is full, mark the task as unable to run.

    while (!remaining.empty ( ) ) {
        finish_time, result = run_task ( remaining, finish_time );
    }
    // Continue processing tasks in the queue until it is empty.

    for ( auto key : result ) {
        cout << result [ key ] << endl;
    }
    // Print the finish time of each task stored in the result dictionary.

    return 0;
}

int run_task ( queue < pair < int, int > > & remaining, int & finish_time ) {
    pair < int, int > task_to_run = remaining.front ( );
    remaining.pop ( );
    finish_time = max ( finish_time, task_to_run.first ) + task_to_run.second;
    result [ task_to_run.second ] = finish_time;
    return finish_time, result;
}
// Define the run_task function to process a task from the queue and update the finish time.

class Task {
public:
    int time, duration, index;
    Task ( int time, int duration, int index ) {
        this->time = time;
        this->duration = duration;
        this->index = index;
    }
};
// Define the Task class to represent a task with its starting time, duration, and index.

