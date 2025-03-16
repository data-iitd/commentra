
# Define a structure to hold the name and time of each process
class pp:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Declare a queue to hold processes
Q = []
head = 0
tail = 0
n = 0

# Function to add a process to the queue
def enqueue(x):
    Q.append(x) # Add the process to the tail of the queue
    tail = (tail + 1) % n # Move the tail pointer forward, wrapping around if necessary

# Function to remove and return a process from the front of the queue
def dequeue():
    x = Q[head] # Get the process at the head of the queue
    head = (head + 1) % n # Move the head pointer forward, wrapping around if necessary
    return x # Return the dequeued process

# Function to return the minimum of two integers
def min(a, b):
    return a if a < b else b

# Read the number of processes and the time quantum
n, q = map(int, input().split())

# Read the name and time for each process
for i in range(1, n + 1):
    name, t = input().split()
    Q.append(pp(name, int(t)))

# Process the queue until all processes are completed
while head!= tail:
    u = dequeue() # Dequeue the next process
    c = min(q, u.t) # Determine the time slice to process (minimum of quantum and remaining time)
    u.t -= c # Reduce the remaining time of the process
    elaps += c # Increase the elapsed time by the time slice
    
    # If the process still has remaining time, enqueue it back
    if u.t > 0:
        enqueue(u)
    else: # If the process is completed, print its name and the elapsed time
        print(u.name, elaps)

# 