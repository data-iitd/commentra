LEN = 100005  # Maximum size of the queue

# Define a structure 'pp' to store name and time of each process
class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Initialize head and tail pointers and size of the queue
Q = [None] * LEN
head = 0
tail = 0
n = 0

# Function to add an element to the queue
def enqueue(x):
    global tail
    Q[tail] = x
    tail = (tail + 1) % LEN

# Function to remove an element from the queue
def dequeue():
    global head
    x = Q[head]
    head = (head + 1) % LEN
    return x

# Function to find the minimum of two integers
def min(a, b):
    return a if a < b else b

# Main function
def main():
    global n, head, tail
    elaps = 0  # Initialize elapsed time
    q = 0  # Number of queries

    # Read number of processes and number of queries
    n, q = map(int, input().split())

    # Allocate memory for each process and read its name and time
    for i in range(n):
        name, t = input().split()
        p = Process(name, int(t))
        enqueue(p)  # Add the process to the queue

    # Simulate the queue and serve processes based on their arrival time and time taken
    while head != tail:
        u = dequeue()  # Dequeue a process
        c = min(q, u.t)  # Find the minimum of remaining queries and time taken by the process
        u.t -= c  # Subtract the time taken to serve the queries
        elaps += c  # Add the time taken to serve the queries to elapsed time
        if u.t > 0:
            enqueue(u)  # If the process still has time left, add it back to the queue
        else:
            print(u.name, elaps)  # Print the name of the process and elapsed time when it is finished

if __name__ == "__main__":
    main()
