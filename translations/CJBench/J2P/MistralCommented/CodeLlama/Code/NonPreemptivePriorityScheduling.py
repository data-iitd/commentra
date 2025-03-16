
import queue

# Define a Process class to store process details
class Process:
    def __init__(self, id, arrival_time, burst_time, priority):
        self.id = id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.start_time = -1

    # Implement Comparable interface for sorting based on priority and arrival time
    def __lt__(self, other):
        if self.priority == other.priority:
            return self.arrival_time < other.arrival_time
        return self.priority < other.priority

# Function to schedule processes based on priority and arrival time
def schedule_processes(processes):
    # Initialize a priority queue and a waiting queue
    pq = queue.PriorityQueue()
    waiting_queue = queue.Queue()

    # Add all processes to the waiting queue
    for process in processes:
        waiting_queue.put(process)

    current_time = 0 # Initialize current time
    index = 0 # Initialize index for execution order array
    execution_order = [None] * len(processes) # Initialize execution order array

    # Simulate the CPU scheduling algorithm
    while not waiting_queue.empty() or not pq.empty():
        # While the waiting queue has processes that have arrived, add them to the priority queue
        while not waiting_queue.empty() and waiting_queue.queue[0].arrival_time <= current_time:
            pq.put(waiting_queue.get())

        # If the priority queue is not empty, take the process with the highest priority and execute it
        if not pq.empty():
            current_process = pq.get()
            current_process.start_time = current_time # Update start time
            execution_order[index] = current_process # Add to execution order
            current_time += current_process.burst_time # Update current time
        else: # If the priority queue is empty, wait for the next process to arrive
            current_time = waiting_queue.queue[0].arrival_time

    # Return the execution order
    return execution_order

# Function to calculate average waiting time
def calculate_average_waiting_time(execution_order):
    total_waiting_time = 0 # Initialize total waiting time

    # Calculate waiting time for each process and add to total waiting time
    for process in execution_order:
        waiting_time = process.start_time - process.arrival_time
        total_waiting_time += waiting_time

    # Calculate and return average waiting time
    return total_waiting_time / len(execution_order)

# Function to calculate average turnaround time
def calculate_average_turnaround_time(execution_order):
    total_turnaround_time = 0 # Initialize total turnaround time

    # Calculate turnaround time for each process and add to total turnaround time
    for process in execution_order:
        turnaround_time = process.start_time + process.burst_time - process.arrival_time
        total_turnaround_time += turnaround_time

    # Calculate and return average turnaround time
    return total_turnaround_time / len(execution_order)

# Main function to read input and call scheduling functions
def main():
    # Initialize scanner to read input from the console
    scanner = input

    # Read number of processes from the console
    n = int(scanner())

    # Initialize an array of processes
    processes = [None] * n

    # Read details of each process and initialize them
    for i in range(n):
        id, arrival_time, burst_time, priority = map(int, scanner().split())
        processes[i] = Process(id, arrival_time, burst_time, priority)

    # Call the scheduling function and store the execution order
    execution_order = schedule_processes(processes)

    # Print the execution order
    print("Execution Order:")
    for process in execution_order:
        print("Process", process.id, "started at time", process.start_time)

    # Calculate and print average waiting time and turnaround time
    avg_waiting_time = calculate_average_waiting_time(execution_order)
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)
    print("Average Waiting Time:", avg_waiting_time)
    print("Average Turnaround Time:", avg_turnaround_time)

# Call the main function
main()

