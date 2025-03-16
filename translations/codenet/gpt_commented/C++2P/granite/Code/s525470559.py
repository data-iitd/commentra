
from collections import deque

n, q = map(int, input().split()) # Read the number of tasks and the time quantum
Q = deque() # Initialize an empty queue
elaps = 0 # Initialize elapsed time to 0

# Read each task's name and time, and add it to the queue
for i in range(n):
    name, time = input().split() # Input task name and time
    Q.append((name, int(time))) # Add the task to the queue

# Process tasks until the queue is empty
while Q:
    name, time = Q.popleft() # Get the task at the front of the queue
    if time <= q: # Check if the task can be completed within the time quantum
        elaps += time # Update elapsed time
        print(name, elaps) # Output task name and total elapsed time
    else: # If the task cannot be completed, reduce its time and re-add it to the queue
        time -= q # Decrease the remaining time of the task
        elaps += q # Update elapsed time by the time quantum
        Q.append((name, time)) # Re-add the task to the queue for further processing

