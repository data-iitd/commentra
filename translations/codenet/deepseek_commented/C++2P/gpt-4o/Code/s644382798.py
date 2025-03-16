class Process:
    def __init__(self, name, time):
        self.name = name
        self.time = time

# Global variables for the queue, head, tail, and number of processes
Q = []
head = 0
tail = 0

# Enqueue function to add a process to the queue
def enqueue(process):
    global tail
    Q.append(process)  # Add the process to the end of the list
    tail += 1  # Update tail to the next position

# Dequeue function to remove and return the next process from the queue
def dequeue():
    global head
    process = Q[head]  # Get the process at the head
    head += 1  # Update head to the next position
    return process  # Return the dequeued process

# Min function to return the smaller of two integers
def min(a, b):
    return a if a < b else b

def main():
    global head, tail
    elaps = 0  # Initialize elapsed time
    n, q = map(int, input().split())  # Read the number of processes and the time quantum

    # Read each process's name and time
    for _ in range(n):
        name = input().strip()  # Read the process name
        time = int(input().strip())  # Read the process time
        Q.append(Process(name, time))  # Create a Process object and add it to the queue

    tail = n  # Initialize tail to the position after the last process

    # Process each process in the queue
    while head < tail:
        u = dequeue()  # Dequeue the next process
        c = min(q, u.time)  # Determine the time slice to process the process
        u.time -= c  # Reduce the process time by the time slice
        elaps += c  # Add the time slice to the elapsed time
        if u.time > 0:
            enqueue(u)  # If there is more time left for the process, enqueue it again
        else:
            print(f"{u.name} {elaps}")  # Otherwise, print the process name and elapsed time

if __name__ == "__main__":
    main()

# <END-OF-CODE>
