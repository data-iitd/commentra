LEN = 100005

# Define a structure to hold the name and time of each process
class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Declare a queue to hold processes
Q = [None] * LEN
head = 0
tail = 0
n = 0

# Function to add a process to the queue
def enqueue(x):
    global tail
    Q[tail] = x
    tail = (tail + 1) % LEN

# Function to remove and return a process from the front of the queue
def dequeue():
    global head
    x = Q[head]
    head = (head + 1) % LEN
    return x

# Function to return the minimum of two integers
def min(a, b):
    return a if a < b else b

# Main function
def main():
    global n, head, tail
    elaps = 0
    q = 0
    processes = []

    # Read the number of processes and the time quantum
    n, q = map(int, input().split())

    # Read the name and time for each process
    for _ in range(n):
        name, t = input().split()
        t = int(t)
        processes.append(Process(name, t))
        enqueue(processes[-1])
    
    # Process the queue until all processes are completed
    while head != tail:
        u = dequeue()
        c = min(q, u.t)
        u.t -= c
        elaps += c
        
        # If the process still has remaining time, enqueue it back
        if u.t > 0:
            enqueue(u)
        else:
            print(u.name, elaps)

if __name__ == "__main__":
    main()
