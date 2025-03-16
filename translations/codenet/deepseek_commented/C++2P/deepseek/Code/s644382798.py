LEN = 100005

# Define a structure to hold process name and time
class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Global variables for the queue, head, tail, and number of processes
Q = [None] * LEN
head = 0
tail = 0
n = 0

# Enqueue function to add a process to the queue
def enqueue(x):
    global tail
    Q[tail] = x
    tail = (tail + 1) % LEN

# Dequeue function to remove and return the next process from the queue
def dequeue():
    global head
    x = Q[head]
    head = (head + 1) % LEN
    return x

# Min function to return the smaller of two integers
def min(a, b):
    return a if a < b else b

# Main function
def main():
    global n, head, tail
    elaps = 0
    q = 0
    n = int(input().split()[0])
    q = int(input().split()[1])

    # Read each process's name and time
    for i in range(n):
        name, t = input().split()
        t = int(t)
        enqueue(Process(name, t))

    # Process each process in the queue
    while head != tail:
        u = dequeue()
        c = min(q, u.t)
        u.t -= c
        elaps += c
        if u.t > 0:
            enqueue(u)
        else:
            print(f"{u.name} {elaps}")

if __name__ == "__main__":
    main()
