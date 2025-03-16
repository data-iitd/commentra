class Process:
    def __init__(self, name, time):
        self.name = name  # Name of the process
        self.remaining_time = time  # Remaining time for the process

class Queue:
    def __init__(self):
        self.queue = []  # Initialize an empty queue

    def enqueue(self, process):
        self.queue.append(process)  # Add the process to the end of the queue

    def dequeue(self):
        return self.queue.pop(0)  # Remove and return the process from the front of the queue

    def is_empty(self):
        return len(self.queue) == 0  # Check if the queue is empty

def min(a, b):
    return a if a < b else b  # Return the minimum of two integers

def main():
    elaps = 0  # Elapsed time
    n, q = map(int, input().split())  # Read the number of processes and the time quantum
    queue = Queue()  # Create a queue to hold processes

    # Read the name and time for each process
    for _ in range(n):
        name = input().strip()  # Read the process name
        time = int(input().strip())  # Read the remaining time for the process
        queue.enqueue(Process(name, time))  # Enqueue the process

    # Process the queue until all processes are completed
    while not queue.is_empty():
        current_process = queue.dequeue()  # Dequeue the next process
        c = min(q, current_process.remaining_time)  # Determine the time slice to process
        current_process.remaining_time -= c  # Reduce the remaining time of the process
        elaps += c  # Increase the elapsed time by the time slice
        
        # If the process still has remaining time, enqueue it back
        if current_process.remaining_time > 0:
            queue.enqueue(current_process)
        else:  # If the process is completed, print its name and the elapsed time
            print(f"{current_process.name} {elaps}")

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
