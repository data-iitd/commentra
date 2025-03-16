import heapq
from collections import deque

class Process:
    def __init__(self, id, arrival_time, burst_time, priority):
        self.id = id  # Unique identifier for the process
        self.arrival_time = arrival_time  # Time at which the process arrives
        self.burst_time = burst_time  # Time required for the process to complete
        self.priority = priority  # Priority of the process
        self.start_time = -1  # Initialize start time to -1 (not started)

    def __lt__(self, other):
        if self.priority == other.priority:
            return self.arrival_time < other.arrival_time
        return self.priority < other.priority

def schedule_processes(processes):
    pq = []  # Priority queue to manage processes based on priority
    waiting_queue = deque(processes)  # Queue to hold processes that are waiting to be scheduled
    current_time = 0  # Tracks the current time in the scheduling
    execution_order = []  # List to store execution order

    while waiting_queue or pq:
        # Add processes that have arrived to the priority queue
        while waiting_queue and waiting_queue[0].arrival_time <= current_time:
            heapq.heappush(pq, waiting_queue.popleft())
        
        # If there are processes in the priority queue, execute the highest priority one
        if pq:
            current_process = heapq.heappop(pq)  # Get the process with the highest priority
            current_process.start_time = current_time  # Set the start time for the current process
            execution_order.append(current_process)  # Record the execution order
            current_time += current_process.burst_time  # Update current time after execution
        else:
            # If no process is ready, jump to the next arriving process
            current_time = waiting_queue[0].arrival_time

    return execution_order  # Return the order in which processes were executed

def calculate_average_waiting_time(execution_order):
    total_waiting_time = 0  # Variable to accumulate total waiting time
    # Calculate waiting time for each process
    for process in execution_order:
        waiting_time = process.start_time - process.arrival_time  # Calculate waiting time
        total_waiting_time += waiting_time  # Add to total waiting time
    # Return average waiting time
    return total_waiting_time / len(execution_order)

def calculate_average_turnaround_time(execution_order):
    total_turnaround_time = 0  # Variable to accumulate total turnaround time
    # Calculate turnaround time for each process
    for process in execution_order:
        turnaround_time = process.start_time + process.burst_time - process.arrival_time  # Calculate turnaround time
        total_turnaround_time += turnaround_time  # Add to total turnaround time
    # Return average turnaround time
    return total_turnaround_time / len(execution_order)

def main():
    n = int(input("Enter the number of processes: "))  # Read the number of processes
    processes = []  # List to hold the processes

    # Read process details from input
    for _ in range(n):
        id, arrival_time, burst_time, priority = map(int, input().split())  # Read process details
        processes.append(Process(id, arrival_time, burst_time, priority))  # Create process object

    # Schedule the processes and get the execution order
    execution_order = schedule_processes(processes)
    print("Execution Order:")
    # Print the execution order of processes
    for process in execution_order:
        print(f"Process {process.id} started at time {process.start_time}")

    # Calculate and print average waiting time
    avg_waiting_time = calculate_average_waiting_time(execution_order)
    # Calculate and print average turnaround time
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)
    print(f"Average Waiting Time: {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround_time:.2f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
