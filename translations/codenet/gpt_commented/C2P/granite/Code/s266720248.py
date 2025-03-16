
# Python code to implement the Round-Robin Scheduling Algorithm

# Define a class to hold the name and time of each process
class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Initialize the queue with the given processes
def initialize_queue(processes):
    queue = []
    for process in processes:
        queue.append(process)
    return queue

# Function to add a process to the queue
def enqueue(queue, process):
    queue.append(process)

# Function to remove a process from the queue
def dequeue(queue):
    return queue.pop(0)

# Function to find the minimum of two integers
def min(a, b):
    return a if a < b else b

# Main function to implement the Round-Robin Scheduling Algorithm
def round_robin_scheduling(processes, quantum):
    queue = initialize_queue(processes)
    elapsed_time = 0
    current_time_slice = 0
    current_process = None

    while len(queue) > 0:
        if current_process is None:
            current_process = dequeue(queue)
        current_time_slice = min(quantum, current_process.t)
        current_process.t -= current_time_slice
        elapsed_time += current_time_slice
        if current_process.t > 0:
            enqueue(queue, current_process)
        else:
            print(f"{current_process.name} {elapsed_time}")
        current_process = None

    return elapsed_time

# Read the number of processes and the time quantum
n, quantum = map(int, input().split())

# Read the process names and their respective times
processes = []
for i in range(n):
    name, t = input().split()
    processes.append(Process(name, int(t)))

# Call the round_robin_scheduling function and print the elapsed time
elapsed_time = round_robin_scheduling(processes, quantum)
print(f"Elapsed time: {elapsed_time}")

