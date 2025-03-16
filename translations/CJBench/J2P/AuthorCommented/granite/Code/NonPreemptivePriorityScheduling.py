
import heapq

class Process:
    def __init__(self, id, arrival_time, burst_time, priority):
        self.id = id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.start_time = -1  # Indicates the process has not started yet

def schedule_processes(processes):
    pq = []
    waiting_queue = []
    heapq.heapify(waiting_queue)
    waiting_queue.extend(processes)

    current_time = 0
    index = 0
    execution_order = [None] * len(processes)

    while waiting_queue or pq:
        # Add processes that have arrived to the priority queue
        while waiting_queue and waiting_queue[0].arrival_time <= current_time:
            heapq.heappush(pq, heapq.heappop(waiting_queue))

        if pq:
            current_process = heapq.heappop(pq)
            current_process.start_time = current_time
            execution_order[index] = current_process
            current_time += current_process.burst_time
        else:
            # If no process is ready, move to the next arrival time
            current_time = waiting_queue[0].arrival_time

    return execution_order

def calculate_average_waiting_time(execution_order):
    total_waiting_time = 0
    for process in execution_order:
        if process is not None:
            waiting_time = process.start_time - process.arrival_time
            total_waiting_time += waiting_time
    return total_waiting_time / len(execution_order)

def calculate_average_turnaround_time(execution_order):
    total_turnaround_time = 0
    for process in execution_order:
        if process is not None:
            turnaround_time = process.start_time + process.burst_time - process.arrival_time
            total_turnaround_time += turnaround_time
    return total_turnaround_time / len(execution_order)

if __name__ == "__main__":
    import sys

    # Input number of processes
    n = int(input())
    processes = [Process(*map(int, input().split())) for _ in range(n)]

    # Schedule processes
    execution_order = schedule_processes(processes)

    # Output execution order
    print("Execution Order:")
    for process in execution_order:
        if process is not None:
            print(f"Process {process.id} started at time {process.start_time}")

    avg_waiting_time = calculate_average_waiting_time(execution_order)
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)

    print(f"Average Waiting Time: {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround_time:.2f}")

