
# Define a structure to represent a task with a name and time
class task:
    def __init__(self, name, time):
        self.name = name
        self.time = time

# Function to process a task
def process_task(task, q, elaps):
    # Check if the task can be completed within the time quantum
    if(task.time <= q):
        # Update elapsed time
        elaps += task.time
        # Output task name and total elapsed time
        print(task.name, elaps)
    else:
        # If the task cannot be completed, reduce its time and re-add it to the queue
        task.time -= q
        elaps += q
        Q.append(task)

# Main function
if __name__ == "__main__":
    n, q = map(int, input().split()) # n: number of tasks, q: time quantum
    elaps = 0 # Variable to keep track of elapsed time
    Q = [] # Queue to manage tasks in a FIFO manner

    # Read each task's name and time, and add it to the queue
    for i in range(n):
        name, time = input().split() # Input task name and time
        Q.append(task(name, int(time))) # Push the task onto the queue

    # Process tasks until the queue is empty
    while(len(Q) > 0):
        task = Q[0] # Get the task at the front of the queue
        Q.pop(0) # Remove the task from the queue
        process_task(task, q, elaps) # Process the task

