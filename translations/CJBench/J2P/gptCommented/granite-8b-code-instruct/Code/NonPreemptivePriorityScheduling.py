
import heapq

class Process:
    def __init__(self, id, arrivalTime, burstTime, priority):
        self.id = id
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.priority = priority
        self.startTime = -1  # Initialize start time to -1 (not started)

    def __lt__(self, other):
        if self.priority == other.priority:
            return self.arrivalTime < other.arrivalTime
        return self.priority < other.priority

def schedule_processes(processes):
    pq = []  # Priority queue to manage processes based on priority
    waiting_queue = []  # Queue to hold processes that are waiting to be scheduled
    execution_order = []  # Array to store execution order

    for process in processes:
        heapq.heappush(waiting_queue, process)  # Add all processes to the waiting queue

    current_time = 0  # Tracks the current time in the scheduling
    index = 0  # Index to track the execution order

    while waiting_queue or pq:
        # Add processes that have arrived to the priority queue
        while waiting_queue and waiting_queue[0].arrivalTime <= current_time:
            heapq.heappush(pq, heapq.heappop(waiting_queue))

        # If there are processes in the priority queue, execute the highest priority one
        if pq:
            current_process = heapq.heappop(pq)  # Get the process with the highest priority
            current_process.startTime = current_time  # Set the start time for the current process
            execution_order.append(current_process)  # Record the execution order
            current_time += current_process.burstTime  # Update current time after execution
        else:
            # If no process is ready, jump to the next arriving process
            current_time = waiting_queue[0].arrivalTime

    return execution_order  # Return the order in which processes were executed

def calculate_average_waiting_time(execution_order):
    total_waiting_time = 0  # Variable to accumulate total waiting time
    # Calculate waiting time for each process
    for process in execution_order:
        waiting_time = process.startTime - process.arrivalTime  # Calculate waiting time
        total_waiting_time += waiting_time  # Add to total waiting time
    # Return average waiting time
    return total_waiting_time / len(execution_order)

def calculate_average_turnaround_time(execution_order):
    total_turnaround_time = 0  # Variable to accumulate total turnaround time
    # Calculate turnaround time for each process
    for process in execution_order:
        turnaround_time = process.startTime + process.burstTime - process.arrivalTime  # Calculate turnaround time
        total_turnaround_time += turnaround_time  # Add to total turnaround time
    # Return average turnaround time
    return total_turnaround_time / len(execution_order)

if __name__ == "__main__":
    n = int(input())  # Read the number of processes
    processes = []  # List to hold the processes

    # Read process details from input
    for _ in range(n):
        id, arrivalTime, burstTime, priority = map(int, input().split())  # Read process ID, arrival time, burst time, and priority
        processes.append(Process(id, arrivalTime, burstTime, priority))  # Create process object

    # Schedule the processes and get the execution order
    execution_order = schedule_processes(processes)
    print("Execution Order:")
    # Print the execution order of processes
    for process in execution_order:
        print(f"Process {process.id} started at time {process.startTime}")

    # Calculate and print average waiting time
    avg_waiting_time = calculate_average_waiting_time(execution_order)
    # Calculate and print average turnaround time
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)
    print(f"Average Waiting Time: {avg_waiting_time}")
    print(f"Average Turnaround Time: {avg_turnaround_time}")