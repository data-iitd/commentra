import heapq
from collections import deque

class Process:
    def __init__(self, id, arrival_time, burst_time, priority):
        self.id = id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.start_time = -1

    def __lt__(self, other):
        if self.priority == other.priority:
            return self.arrival_time < other.arrival_time
        return self.priority < other.priority

def schedule_processes(processes):
    pq = []
    waiting_queue = deque(processes)
    current_time = 0
    execution_order = []

    while waiting_queue or pq:
        while waiting_queue and waiting_queue[0].arrival_time <= current_time:
            heapq.heappush(pq, waiting_queue.popleft())

        if pq:
            current_process = heapq.heappop(pq)
            current_process.start_time = current_time
            execution_order.append(current_process)
            current_time += current_process.burst_time
        else:
            current_time = waiting_queue[0].arrival_time

    return execution_order

def calculate_average_waiting_time(execution_order):
    total_waiting_time = 0
    for process in execution_order:
        waiting_time = process.start_time - process.arrival_time
        total_waiting_time += waiting_time
    return total_waiting_time / len(execution_order)

def calculate_average_turnaround_time(execution_order):
    total_turnaround_time = 0
    for process in execution_order:
        turnaround_time = process.start_time + process.burst_time - process.arrival_time
        total_turnaround_time += turnaround_time
    return total_turnaround_time / len(execution_order)

def main():
    n = int(input())
    processes = []
    for _ in range(n):
        id, arrival_time, burst_time, priority = map(int, input().split())
        processes.append(Process(id, arrival_time, burst_time, priority))

    execution_order = schedule_processes(processes)
    print("Execution Order:")
    for process in execution_order:
        print(f"Process {process.id} started at time {process.start_time}")

    avg_waiting_time = calculate_average_waiting_time(execution_order)
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)
    print(f"Average Waiting Time: {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround_time:.2f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
