from typing import List, Optional

class ProcessDetails:
    def __init__(self, process_id: str, arrival_time: int, burst_time: int):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time

    def get_process_id(self) -> str:
        return self.process_id

    def get_arrival_time(self) -> int:
        return self.arrival_time

    def get_burst_time(self) -> int:
        return self.burst_time


class Main:
    def __init__(self, processes: List[ProcessDetails]):
        self.processes = processes
        self.schedule = []
        self.sort_processes_by_arrival_time()

    def sort_processes_by_arrival_time(self):
        self.processes.sort(key=lambda p: p.get_arrival_time())

    def schedule_processes(self):
        ready = []
        size = len(self.processes)
        time = 0
        executed = 0
        k = 0

        if size == 0:
            return

        while executed < size:
            while k < size and self.processes[k].get_arrival_time() <= time:
                ready.append(self.processes[k])
                k += 1

            running = self.find_shortest_job(ready)
            if running is None:
                time += 1
            else:
                time += running.get_burst_time()
                self.schedule.append(running.get_process_id())
                ready.remove(running)
                executed += 1

    def find_shortest_job(self, ready_processes: List[ProcessDetails]) -> Optional[ProcessDetails]:
        if not ready_processes:
            return None
        return min(ready_processes, key=lambda p: p.get_burst_time())

    def get_schedule(self) -> List[str]:
        return self.schedule


if __name__ == "__main__":
    n = int(input("Enter number of processes: "))
    processes = []

    for _ in range(n):
        process_id = input("Enter process ID: ")
        arrival_time = int(input("Enter arrival time: "))
        burst_time = int(input("Enter burst time: "))
        processes.append(ProcessDetails(process_id, arrival_time, burst_time))

    sjf_scheduling = Main(processes)
    sjf_scheduling.schedule_processes()

    print("Execution Order:")
    for process_id in sjf_scheduling.get_schedule():
        print(process_id)

# <END-OF-CODE>
