from collections import deque

# Define a custom class for tasks
class Task:
    def __init__(self, name, time):
        self.name = name  # Name of the task
        self.time = time  # Time taken by the task

def main():
    n, q = map(int, input().split())  # Number of tasks and queries
    elaps = 0  # Elapsed time
    Q = deque()  # Queue to store tasks

    # Read tasks details and add them to the queue
    for _ in range(n):
        name, time = input().split()
        time = int(time)
        Q.append(Task(name, time))  # Add the task to the queue

    # Process tasks in the queue until it is empty
    while Q:
        p = Q.popleft()  # Get the task at the front of the queue

        # Check if the current task can be completed within the given query time
        if p.time <= q:
            elaps += p.time  # Add the time taken by the task to the elapsed time
            print(f"{p.name} {elaps}")  # Print the name and elapsed time of the task
        else:  # If the current task cannot be completed within the given query time
            p.time -= q  # Subtract the query time from the time taken by the task
            Q.append(p)  # Add the task back to the queue with updated time

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
