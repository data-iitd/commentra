
# Include the queue library for using the queue data structure.
from queue import Queue

# Define a function named 'process_task' to process a task.
def process_task(task, time_quantum, elapsed_time):
    # Check if the remaining time for the task is less than or equal to the time quantum.
    if task.time <= time_quantum:
        # Update the elapsed time by adding the task's remaining time.
        elapsed_time += task.time
        # Print the task's name and the current elapsed time.
        print(task.name, elapsed_time)
    else:
        # Reduce the task's remaining time by the time quantum.
        task.time -= time_quantum
        # Update the elapsed time by adding the time quantum.
        elapsed_time += time_quantum
        # Push the task back into the queue with the remaining time.
        Q.put(task)

# The main function is where the program execution begins.
if __name__ == '__main__':
    # Declare variables for the number of tasks, the time quantum, and the elapsed time.
    n = int(input())
    q = int(input())
    elaps = 0
    # Declare a queue of tasks.
    Q = Queue()
    # Loop to read each task's name and time.
    for i in range(n):
        # Create a temporary task object.
        tmp = task()
        # Read the task's name and time from the standard input.
        tmp.name, tmp.time = input().split()
        # Push the task into the queue.
        Q.put(tmp)
    # Process each task in the queue until it is empty.
    while not Q.empty():
        # Get the front task from the queue and remove it from the queue.
        p = Q.get()
        # Process the task.
        process_task(p, q, elaps)

