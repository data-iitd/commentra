#include <stdio.h>
#include <string.h>
#define LEN 100005

# Define a structure to hold the name and time of each process
class P:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Declare a queue to hold processes
Q = [P("", 0) for i in range(LEN)]
head, tail, n = 0, 1, 0 # Queue pointers and number of processes

# Function to add a process to the queue
def enqueue(x):
    Q[tail] = x # Add the process to the tail of the queue
    tail = (tail + 1) % LEN # Move the tail pointer forward, wrapping around if necessary

# Function to remove and return a process from the front of the queue
def dequeue():
    x = Q[head] # Get the process at the head of the queue
    head = (head + 1) % LEN # Move the head pointer forward, wrapping around if necessary
    return x # Return the dequeued process

# Function to return the minimum of two integers
def min(a, b):
    return a if a < b else b

def main():
    elaps = 0 # elaps keeps track of elapsed time
    c = 0 # c is the time slice
    i = 0 # Loop variable
    q = 0 # The time quantum
    u = P("", 0) # Variable to hold the current process

    # Read the number of processes and the time quantum
    n, q = map(int, input().split())

    # Read the name and time for each process
    for i in range(1, n + 1):
        name = input()
        t = int(input())
        enqueue(P(name, t))

    # Initialize the head and tail pointers for the queue
    head, tail = 1, n + 1

    # Process the queue until all processes are completed
    while head != tail:
        u = dequeue() # Dequeue the next process
        c = min(q, u.t) # Determine the time slice to process (minimum of quantum and remaining time)
        u.t -= c # Reduce the remaining time of the process
        elaps += c # Increase the elapsed time by the time slice
        
        # If the process still has remaining time, enqueue it back
        if u.t > 0:
            enqueue(u)
        else: # If the process is completed, print its name and the elapsed time
            print(u.name, elaps)

    return 0 # End of the program


