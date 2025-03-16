#include <iostream>
#include <queue>

using namespace std;

# Define a structure to represent a task with a name and time
struct task:
    name: str
    time: int

def main():
    n, q = 0, 0 # n: number of tasks, q: time quantum
    elaps = 0 # Variable to keep track of elapsed time
    Q = queue() # Queue to manage tasks in a FIFO manner

    # Read the number of tasks and the time quantum from input
    cin >> n >> q

    # Read each task's name and time, and add it to the queue
    for i in range(n):
        tmp = task() # Temporary task variable
        cin >> tmp.name >> tmp.time # Input task name and time
        Q.push(tmp) # Push the task onto the queue

    # Process tasks until the queue is empty
    while not Q.empty():
        p = Q.front() # Get the task at the front of the queue
        Q.pop() # Remove the task from the queue

        # Check if the task can be completed within the time quantum
        if p.time <= q:
            elaps += p.time # Update elapsed time
            cout << p.name << " " << elaps << endl # Output task name and total elapsed time
        else:
            # If the task cannot be completed, reduce its time and re-add it to the queue
            p.time -= q # Decrease the remaining time of the task
            elaps += q # Update elapsed time by the time quantum
            Q.push(p) # Re-add the task to the queue for further processing

    return 0 # Exit the program

