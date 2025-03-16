from collections import deque  # Import deque from collections for using a queue data structure.

class Task:  # Define a class named 'Task' to hold the name and time for each task.
    def __init__(self, name, time):  # Initialize the task with a name and time.
        self.name = name  # The name of the task.
        self.time = time  # The time required to complete the task.

def main():  # The main function is where the program execution begins.
    n, q = map(int, input().split())  # Read the number of tasks and the time quantum from the standard input.
    elaps = 0  # Initialize the elapsed time to 0.
    Q = deque()  # Declare a queue of tasks using deque.

    for _ in range(n):  # Loop to read each task's name and time.
        name, time = input().split()  # Read the task's name and time from the standard input.
        Q.append(Task(name, int(time)))  # Create a Task object and append it to the queue.

    while Q:  # Process each task in the queue until it is empty.
        p = Q.popleft()  # Get the front task from the queue and remove it from the queue.
        if p.time <= q:  # Check if the remaining time for the task is less than or equal to the time quantum.
            elaps += p.time  # Update the elapsed time by adding the task's remaining time.
            print(p.name, elaps)  # Print the task's name and the current elapsed time.
        else:  # If the task's remaining time is greater than the time quantum.
            p.time -= q  # Reduce the task's remaining time by the time quantum.
            elaps += q  # Update the elapsed time by adding the time quantum.
            Q.append(p)  # Push the task back into the queue with the remaining time.

if __name__ == "__main__":  # Check if the script is being run directly.
    main()  # Call the main function to execute the program.

# <END-OF-CODE>
