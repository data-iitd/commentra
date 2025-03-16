
import sys
from collections import defaultdict

class Process:
    def __init__(self, process_id, burst_time, deadline):
        self.process_id = process_id
        self.burst_time = burst_time
        self.deadline = deadline
        self.waiting_time = 0
        self.turnaround_time = 0

def schedule_processes(processes):
    processes.sort(key=lambda x: x.deadline)
    current_time = 0
    executed_processes = []
    for process in processes:
        process.waiting_time = current_time
        current_time += process.burst_time
        process.turnaround_time = process.waiting_time + process.burst_time
        if current_time > process.deadline:
            print(f"Warning: Process {process.process_id} missed its deadline.")
        executed_processes.append(process)
    return executed_processes

if __name__ == "__main__":
    num_processes = int(input())
    processes = []
    for _ in range(num_processes):
        process_id, burst_time, deadline = input().split()
        processes.append(Process(process_id, int(burst_time), int(deadline)))
    executed_processes = schedule_processes(processes)
    for process in executed_processes:
        print(f"{process.process_id} {process.waiting_time} {process.turnaround_time}")

