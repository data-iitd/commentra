
# Define a custom struct for tasks
class task:
    # Name of the task
    name = ""
    # Time taken by the task
    time = 0

n, q = map(int, input().split()) # Read number of tasks and queries from standard input

Q = [] # Queue to store tasks

# Read tasks details and add them to the queue
for i in range(n):
    tmp = task() # Create a new task
    tmp.name, tmp.time = input().split() # Read task name and time from standard input
    Q.append(tmp) # Add the task to the queue

elaps = 0 # Elapsed time

# Process tasks in the queue until it is empty
while len(Q) > 0:
    p = Q[0] # Get the task at the front of the queue
    del Q[0] # Remove the task from the queue

    # Check if the current task can be completed within the given query time
    if p.time <= q:
        elaps += p.time # Add the time taken by the task to the elapsed time
        print(p.name, elaps) # Print the name and elapsed time of the task
    else: # If the current task cannot be completed within the given query time
        # Subtract the query time from the time taken by the task
        p.time -= q
        # Add the task back to the queue with updated time
        Q.append(p)

# Return 0 to indicate successful execution of the program
0

