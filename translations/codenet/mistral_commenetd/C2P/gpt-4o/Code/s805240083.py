MAX = 100005
N = 100

class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t  # time taken by each process

class CircularQueue:
    def __init__(self):
        self.Q = [None] * (MAX + 1)  # Circular queue to store the processes
        self.head = 0  # pointer for head of the queue
        self.tail = 0  # pointer for tail of the queue

    def enqueue(self, process):
        # Function to add a process to the queue
        self.Q[self.tail] = process  # Store the process in the queue
        self.tail += 1  # Increment the tail pointer
        if self.tail == MAX:  # Wrap around if necessary
            self.tail = 0

    def dequeue(self):
        # Function to remove a process from the queue
        process = self.Q[self.head]  # Store the process to be removed
        self.head += 1  # Increment the head pointer
        if self.head == MAX:  # Wrap around if necessary
            self.head = 0
        return process  # Return the process

def main():
    n, q = map(int, input().split())  # Read the number of processes and the time limit from the input
    queue = CircularQueue()  # Create a circular queue
    total_time = 0  # Initialize the total time to 0

    for _ in range(n):  # Loop to read the details of each process and enqueue it
        name, t = input().split()
        t = int(t)
        process = Process(name, t)
        queue.enqueue(process)

    while n != 0:  # While there are still processes in the queue
        process = queue.dequeue()  # Dequeue the current process
        if process.t > q:  # If the process takes more time than the limit
            process.t -= q  # Subtract the excess time from the process time
            total_time += q  # Add the time limit to the total time
            queue.enqueue(process)  # Re-enqueue the process
        else:  # If the process takes less time than the limit
            total_time += process.t  # Add the process time to the total time
            print(f"{process.name} {total_time}")  # Print the name and total time taken for the process
            n -= 1  # Decrement the number of processes left

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
