class Process:
    def __init__(self, name, time):
        self.name = name  # Name of the process
        self.remaining_time = time  # Remaining time for the process

class Queue:
    def __init__(self, length):
        self.queue = [None] * length  # Initialize the queue with a fixed length
        self.head = 0  # Head pointer
        self.tail = 0  # Tail pointer
        self.length = length  # Length of the queue

    def enqueue(self, process):
        self.queue[self.tail] = process  # Add the process to the queue at the tail
        self.tail = (self.tail + 1) % self.length  # Move the tail pointer in a circular manner

    def dequeue(self):
        process = self.queue[self.head]  # Get the process at the head of the queue
        self.head = (self.head + 1) % self.length  # Move the head pointer in a circular manner
        return process  # Return the removed process

def min(a, b):
    return a if a < b else b  # Return the smaller of the two values

def main():
    elaps = 0  # Elapsed time
    n, q = map(int, input().split())  # Read the number of processes and the time quantum
    queue = Queue(100005)  # Create a queue with a large enough size

    # Read the process names and their respective times
    for _ in range(n):
        name = input().strip()  # Read process name
        time = int(input().strip())  # Read remaining time for the process
        queue.enqueue(Process(name, time))  # Enqueue the process

    # Process the queue until all processes are completed
    while queue.head != queue.tail:
        current_process = queue.dequeue()  # Remove the next process from the queue
        c = min(q, current_process.remaining_time)  # Determine the time slice to process
        current_process.remaining_time -= c  # Decrease the remaining time of the process
        elaps += c  # Increase the elapsed time by the time slice
        if current_process.remaining_time > 0:
            queue.enqueue(current_process)  # Re-add the process if not finished
        else:
            # If the process is finished, print its name and the total elapsed time
            print(f"{current_process.name} {elaps}")

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
