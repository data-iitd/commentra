#include <stdio.h>
#include <string.h>
#define LEN 100005

# Define a structure to hold process name and time
class P:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Global variables for the queue, head, tail, and number of processes
Q = [P("", 0) for i in range(LEN)]
head = 1
tail = n + 1
n = 0

# Enqueue function to add a process to the queue
def enqueue(x):
    Q[tail] = x # Assign the process to the current tail position
    tail = (tail + 1) % LEN # Update tail to the next position, wrapping around if necessary

# Dequeue function to remove and return the next process from the queue
def dequeue():
    x = Q[head] # Get the process at the head
    head = (head + 1) % LEN # Update head to the next position, wrapping around if necessary
    return x # Return the dequeued process

# Min function to return the smaller of two integers
def min(a, b):
    return a if a < b else b

def main():
    elaps = 0 # Initialize elapsed time and a variable to hold the time quantum
    c = 0
    i = 0
    q = 0
    u = P("", 0)
    scanf("%d %d", &n, &q) # Read the number of processes and the time quantum

    # Read each process's name and time
    for i in range(1, n + 1):
        scanf("%s", Q[i].name) # Read the process name
        scanf("%d", &Q[i].t) # Read the process time

    head = 1 # Initialize head to the first position in the queue
    tail = n + 1 # Initialize tail to the position after the last process

    # Process each process in the queue
    while head != tail:
        u = dequeue() # Dequeue the next process
        c = min(q, u.t) # Determine the time slice to process the process
        u.t -= c # Reduce the process time by the time slice
        elaps += c # Add the time slice to the elapsed time
        if u.t > 0:
            enqueue(u) # If there is more time left for the process, enqueue it again
        else:
            printf("%s %d\n", u.name, elaps) # Otherwise, print the process name and elapsed time

    return 0

