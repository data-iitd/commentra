from collections import deque

# Define a structure to represent a task with a name and time
class Task:
    def __init__(self, name, time):
        self.name = name
        self.time = time

# Main function to process tasks
def main():
    n, q = map(int, input().split())  # n: number of tasks, q: time quantum
    elaps = 0  # Variable to keep track of elapsed time
    Q = deque()  # Queue to manage tasks in a FIFO manner

    # Read each task's name and time, and add it to the queue
    for _ in range(n):
        name, time = input().split()
        time = int(time)  # Convert time to integer
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
    main()
