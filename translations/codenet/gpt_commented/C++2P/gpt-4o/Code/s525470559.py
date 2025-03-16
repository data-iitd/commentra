from collections import deque

# Define a class to represent a task with a name and time
class Task:
    def __init__(self, name, time):
        self.name = name  # Name of the task
        self.time = time  # Time required to complete the task

def main():
    n, q = map(int, input().split())  # Read the number of tasks and the time quantum
    elaps = 0  # Variable to keep track of elapsed time
    Q = deque()  # Queue to manage tasks in a FIFO manner

    # Read each task's name and time, and add it to the queue
    for _ in range(n):
        name, time = input().split()
        time = int(time)
        Q.append(Task(name, time))  # Append the task to the queue

    # Process tasks until the queue is empty
    while Q:
        p = Q.popleft()  # Get the task at the front of the queue
        
        # Check if the task can be completed within the time quantum
        if p.time <= q:
            elaps += p.time  # Update elapsed time
            print(f"{p.name} {elaps}")  # Output task name and total elapsed time
        else:
            # If the task cannot be completed, reduce its time and re-add it to the queue
            p.time -= q  # Decrease the remaining time of the task
            elaps += q  # Update elapsed time by the time quantum
            Q.append(p)  # Re-add the task to the queue for further processing

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
