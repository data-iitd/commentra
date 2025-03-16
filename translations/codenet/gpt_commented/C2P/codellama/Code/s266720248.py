#include<stdio.h>
#include<string.h>

#define LEN 100005

# Define a structure to hold the name and time of each process
class P:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Declare a queue to hold the processes
Q = [P("", 0) for i in range(LEN)]
head, tail, n = 1, 1, 0 # Variables for queue management and number of processes

# Function to add a process to the queue
def enqueue(x):
    Q[tail] = x # Add the process to the queue at the tail
    tail = (tail + 1) % LEN # Move the tail pointer in a circular manner

# Function to remove a process from the queue
def dequeue():
    x = Q[head] # Get the process at the head of the queue
    head = (head + 1) % LEN # Move the head pointer in a circular manner
    return x # Return the removed process

# Function to find the minimum of two integers
def min(a, b):
    return a if a < b else b # Return the smaller of the two values

def main():
    elaps = 0 # elaps keeps track of elapsed time
    c = 0 # c for current time slice
    i = 0 # Loop variable
    q = 0 # The time quantum
    u = P("", 0) # Variable to hold the current process

    # Read the number of processes and the time quantum
    n, q = map(int, input().split())

    # Read the process names and their respective times
    for i in range(n):
        u.name, u.t = input().split()
        u.t = int(u.t)
        enqueue(u)

    # Process the queue until all processes are completed
    while head != tail:
        u = dequeue() # Remove the next process from the queue
        c = min(q, u.t) # Determine the time slice to process (minimum of quantum and remaining time)
        u.t -= c # Decrease the remaining time of the process
        elaps += c # Increase the elapsed time by the time slice
        if u.t > 0: enqueue(u) # If the process is not finished, re-add it to the queue
        else:
            # If the process is finished, print its name and the total elapsed time
            print(u.name, elaps)

if __name__ == "__main__":
    main()

