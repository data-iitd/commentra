# Define a structure to hold process name and time
class pp:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Global variables for the queue, head, tail, and number of processes
Q = []
head = 0
tail = 0
n = 0

# Enqueue function to add a process to the queue
def enqueue(x):
    Q.append(x) # Assign the process to the current tail position
    tail = (tail + 1) % len(Q) # Update tail to the next position, wrapping around if necessary

# Dequeue function to remove and return the next process from the queue
def dequeue():
    x = Q[head] # Get the process at the head
    head = (head + 1) % len(Q) # Update head to the next position, wrapping around if necessary
    return x # Return the dequeued process

# Min function to return the smaller of two integers
def min(a, b):
    return a if a < b else b

def main():
    elaps = 0 # Initialize elapsed time
    q = 0 # Initialize a variable to hold the time quantum
    i = 0
    u = pp("", 0) # Initialize a process
    # Read the number of processes and the time quantum
    n, q = map(int, input().split())
    # Read each process's name and time
    for i in range(1, n + 1):
        u.name, u.t = input().split()
        u.t = int(u.t)
        enqueue(u) # Enqueue the process
    # Process each process in the queue
    while head!= tail:
        u = dequeue() # Dequeue the next process
        c = min(q, u.t) # Determine the time slice to process the process
        u.t -= c # Reduce the process time by the time slice
        elaps += c # Add the time slice to the elapsed time
        if u.t > 0:
            enqueue(u) # If there is more time left for the process, enqueue it again
        else:
            print(u.name, elaps) # Otherwise, print the process name and elapsed time

main()

