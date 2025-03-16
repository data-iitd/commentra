
import sys

# Class representing a process with its attributes and comparison logic
class Process:
    def __init__(self, id, arrival_time, burst_time, priority):
        self.id = id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.start_time = -1 # Initialize start time to -1 (not started)

    # Comparison logic for priority queue based on priority and arrival time
    def __lt__(self, other):
        if self.priority == other.priority:
            return self.arrival_time < other.arrival_time
        return self.priority < other.priority

# Method to schedule processes based on their arrival time and priority
def schedule_processes(processes):
    # Priority queue to manage processes based on priority
    pq = []
    # Queue to hold processes that are waiting to be scheduled
    waiting_queue = []
    # Add all processes to the waiting queue
    waiting_queue.extend(processes)
    
    current_time = 0 # Tracks the current time in the scheduling
    index = 0 # Index to track the execution order
    execution_order = [None] * len(processes) # Array to store execution order

    # Loop until all processes are executed
    while waiting_queue or pq:
        # Add processes that have arrived to the priority queue
        while waiting_queue and waiting_queue[0].arrival_time <= current_time:
            pq.append(waiting_queue.pop(0))
        # If there are processes in the priority queue, execute the highest priority one
        if pq:
            current_process = pq.pop(0) # Get the process with the highest priority
            current_process.start_time = current_time # Set the start time for the current process
            execution_order[index] = current_process # Record the execution order
            current_time += current_process.burst_time # Update current time after execution
        else:
            # If no process is ready, jump to the next arriving process
            current_time = waiting_queue[0].arrival_time

    return execution_order # Return the order in which processes were executed

# Method to calculate the average waiting time of the executed processes
def calculate_average_waiting_time(execution_order):
    total_waiting_time = 0 # Variable to accumulate total waiting time
    # Calculate waiting time for each process
    for process in execution_order:
        waiting_time = process.start_time - process.arrival_time # Calculate waiting time
        total_waiting_time += waiting_time # Add to total waiting time
    # Return average waiting time
    return total_waiting_time / len(execution_order)

# Method to calculate the average turnaround time of the executed processes
def calculate_average_turnaround_time(execution_order):
    total_turnaround_time = 0 # Variable to accumulate total turnaround time
    # Calculate turnaround time for each process
    for process in execution_order:
        turnaround_time = process.start_time + process.burst_time - process.arrival_time # Calculate turnaround time
        total_turnaround_time += turnaround_time # Add to total turnaround time
    # Return average turnaround time
    return total_turnaround_time / len(execution_order)

# Main method to execute the scheduling program
def main():
    n = int(sys.stdin.readline()) # Read the number of processes
    processes = [] # Array to hold the processes

    # Read process details from input
    for i in range(n):
        id, arrival_time, burst_time, priority = map(int, sys.stdin.readline().split()) # Read process ID, arrival time, burst time, and priority
        processes.append(Process(id, arrival_time, burst_time, priority)) # Create process object

    # Schedule the processes and get the execution order
    execution_order = schedule_processes(processes)
    print("Execution Order:")
    # Print the execution order of processes
    for process in execution_order:
        print("Process", process.id, "started at time", process.start_time)

    # Calculate and print average waiting time
    avg_waiting_time = calculate_average_waiting_time(execution_order)
    # Calculate and print average turnaround time
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)
    print("Average Waiting Time:", avg_waiting_time)
    print("Average Turnaround Time:", avg_turnaround_time)

if __name__ == "__main__":
    main()
