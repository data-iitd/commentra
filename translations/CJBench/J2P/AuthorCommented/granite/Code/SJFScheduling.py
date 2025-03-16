
import sys

class ProcessDetails:
    def __init__(self, process_id, arrival_time, burst_time):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time

def find_shortest_job(ready_processes):
    if not ready_processes:
        return None
    return min(ready_processes, key=lambda p: p.burst_time)

def schedule_processes(processes):
    ready_processes = []
    time = 0
    executed = 0
    k = 0
    schedule = []

    if not processes:
        return schedule

    while executed < len(processes):
        while k < len(processes) and processes[k].arrival_time <= time:
            ready_processes.append(processes[k])
            k += 1

        running = find_shortest_job(ready_processes)
        if not running:
            time += 1
        else:
            time += running.burst_time
            schedule.append(running.process_id)
            ready_processes.remove(running)
            executed += 1

    return schedule

if __name__ == "__main__":
    n = int(input("Enter the number of processes: "))
    processes = []

    for i in range(n):
        process_id, arrival_time, burst_time = input("Enter process details (space separated): ").split()
        processes.append(ProcessDetails(process_id, int(arrival_time), int(burst_time)))

    schedule = schedule_processes(processes)

    print("Execution Order:")
    for process_id in schedule:
        print(process_id)

