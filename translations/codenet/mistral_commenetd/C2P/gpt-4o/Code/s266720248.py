class Process:
    def __init__(self, name, time):
        self.name = name  # Name of the process
        self.time = time  # Time taken by the process

class Queue:
    def __init__(self, max_size):
        self.queue = [None] * max_size  # Initialize the queue with a fixed size
        self.head = 0  # Head pointer
        self.tail = 0  # Tail pointer

    def enqueue(self, process):
        self.queue[self.tail] = process  # Add the process to the queue
        self.tail = (self.tail + 1) % len(self.queue)  # Increment tail pointer

    def dequeue(self):
        process = self.queue[self.head]  # Store the process to be removed
        self.head = (self.head + 1) % len(self.queue)  # Increment head pointer
        return process  # Return the removed process

def min(a, b):
    return a if a < b else b  # Return the smaller integer

def main():
    elaps = 0  # Initialize elapsed time
    n, q = map(int, input().split())  # Read number of processes and number of queries

    queue = Queue(100005)  # Create a queue with a maximum size

    # Read each process's name and time, and enqueue it
    for _ in range(n):
        name = input().strip()  # Read name of the process
        time = int(input().strip())  # Read time taken by the process
        process = Process(name, time)  # Create a Process object
        queue.enqueue(process)  # Add the process to the queue

    # Simulate the queue and serve processes
    while queue.head != queue.tail:
        u = queue.dequeue()  # Dequeue a process
        c = min(q, u.time)  # Find the minimum of remaining queries and time taken by the process
        u.time -= c  # Subtract the time taken to serve the queries
        elaps += c  # Add the time taken to serve the queries to elapsed time
        if u.time > 0:
            queue.enqueue(u)  # If the process still has time left, add it back to the queue
        else:
            print(f"{u.name} {elaps}")  # Print the name of the process and elapsed time when it is finished

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
