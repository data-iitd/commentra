import heapq
from collections import deque

class Process:
    def __init__(self, id, arrival_time, burst_time, priority):
        self.id = id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.start_time = -1  # Initialize start time

    # Define comparison for priority queue
    def __lt__(self, other):
        if self.priority == other.priority:
            return self.arrival_time < other.arrival_time
        return self.priority < other.priority

def schedule_processes(processes):
    # Initialize a priority queue and a waiting queue
    pq = []
    waiting_queue = deque(processes)

    current_time = 0  # Initialize current time
    execution_order = []  # Initialize execution order list

    # Simulate the CPU scheduling algorithm
    while waiting_queue or pq:
        # While the waiting queue has processes that have arrived, add them to the priority queue
        while waiting_queue and waiting_queue[0].arrival_time <= current_time:
            heapq.heappush(pq, waiting_queue.popleft())

        # If the priority queue is not empty, take the process with the highest priority and execute it
        if pq:
            current_process = heapq.heappop(pq)
            current_process.start_time = current_time  # Update start time
            execution_order.append(current_process)  # Add to execution order
            current_time += current_process.burst_time  # Update current time
        else:  # If the priority queue is empty, wait for the next process to arrive
            current_time = waiting_queue[0].arrival_time

    return execution_order

def calculate_average_waiting_time(execution_order):
    total_waiting_time = 0  # Initialize total waiting time

    # Calculate waiting time for each process and add to total waiting time
    for process in execution_order:
        waiting_time = process.start_time - process.arrival_time
        total_waiting_time += waiting_time

    # Calculate and return average waiting time
    return total_waiting_time / len(execution_order)

def calculate_average_turnaround_time(execution_order):
    total_turnaround_time = 0  # Initialize total turnaround time

    # Calculate turnaround time for each process and add to total turnaround time
    for process in execution_order:
        turnaround_time = process.start_time + process.burst_time - process.arrival_time
        total_turnaround_time += turnaround_time

    # Calculate and return average turnaround time
    return total_turnaround_time / len(execution_order)

def main():
    # Read number of processes from the console
    n = int(input("Enter number of processes: "))

    # Initialize a list of processes
    processes = []

    # Read details of each process and initialize them
    for _ in range(n):
        id, arrival_time, burst_time, priority = map(int, input().split())
        processes.append(Process(id, arrival_time, burst_time, priority))

    # Call the scheduling function and store the execution order
    execution_order = schedule_processes(processes)

    # Print the execution order
    print("Execution Order:")
    for process in execution_order:
        print(f"Process {process.id} started at time {process.start_time}")

    # Calculate and print average waiting time and turnaround time
    avg_waiting_time = calculate_average_waiting_time(execution_order)
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)
    print(f"Average Waiting Time: {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround_time:.2f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
