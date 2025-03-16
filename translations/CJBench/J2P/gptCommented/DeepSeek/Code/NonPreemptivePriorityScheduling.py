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
    waiting_queue = []
    for process in processes:
        waiting_queue.append(process)
    current_time = 0
    index = 0
    execution_order = [None] * len(processes)

    while waiting_queue or pq:
        while waiting_queue and waiting_queue[0].arrival_time <= current_time:
            process = waiting_queue.pop(0)
            pq.append(process)
        if pq:
            pq.sort()
            current_process = pq.pop(0)
            current_process.start_time = current_time
            execution_order[index] = current_process
            index += 1
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

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    processes = []

    for i in range(1, n + 1):
        id = int(data[i * 4 - 3])
        arrival_time = int(data[i * 4 - 2])
        burst_time = int(data[i * 4 - 1])
        priority = int(data[i * 4])
        process = Process(id, arrival_time, burst_time, priority)
        processes.append(process)

    execution_order = schedule_processes(processes)
    print("Execution Order:")
    for process in execution_order:
        print(f"Process {process.id} started at time {process.start_time}")

    avg_waiting_time = calculate_average_waiting_time(execution_order)
    avg_turnaround_time = calculate_average_turnaround_time(execution_order)
    print(f"Average Waiting Time: {avg_waiting_time:.2f}")
    print(f"Average Turnaround Time: {avg_turnaround_time:.2f}")
