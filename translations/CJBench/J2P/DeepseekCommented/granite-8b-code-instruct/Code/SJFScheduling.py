
import sys
from typing import List
class ProcessDetails:
    def __init__(self, process_id: str, arrival_time: int, burst_time: int):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
class Main:
    def __init__(self, processes: List[ProcessDetails]):
        self.processes = processes
        self.processes.sort(key=lambda p: p.arrival_time)
        self.schedule = []
    def schedule_processes(self):
        ready = []
        time = 0
        executed = 0
        k = 0
        while executed < len(self.processes):
            while k < len(self.processes) and self.processes[k].arrival_time <= time:
                ready.append(self.processes[k])
                k += 1
            running = self.find_shortest_job(ready)
            if running is None:
                time += 1
            else:
                time += running.burst_time
                self.schedule.append(running.process_id)
                ready.remove(running)
                executed += 1
    def find_shortest_job(self, ready_processes: List[ProcessDetails]) -> ProcessDetails:
        if not ready_processes:
            return None
        return min(ready_processes, key=lambda p: p.burst_time)
    def get_schedule(self) -> List[str]:
        return self.schedule
if __name__ == "__main__":
    n = int(input())
    processes = []
    for i in range(n):
        process_id, arrival_time, burst_time = input().split()
        processes.append(ProcessDetails(process_id, int(arrival_time), int(burst_time)))
    sjf_scheduling = Main(processes)
    sjf_scheduling.schedule_processes()
    print("Execution Order:")
    for process_id in sjf_scheduling.get_schedule():
        print(process_id)
