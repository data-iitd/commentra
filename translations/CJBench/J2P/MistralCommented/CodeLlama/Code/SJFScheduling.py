
import sys

class ProcessDetails:
    def __init__(self, process_id, arrival_time, burst_time):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time

class Main:
    def __init__(self, processes):
        self.processes = processes
        self.schedule = []
        self.sort_processes_by_arrival_time(self.processes)

    def sort_processes_by_arrival_time(self, processes):
        processes.sort(key=lambda x: x.arrival_time)

    def schedule_processes(self):
        ready = []
        size = len(self.processes)
        time = 0
        executed = 0
        k = 0

        if size == 0:
            return

        while executed < size:
            while k < size and self.processes[k].arrival_time <= time:
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

    def find_shortest_job(self, ready_processes):
        if not ready_processes:
            return None
        return min(ready_processes, key=lambda x: x.burst_time)

    def get_schedule(self):
        return self.schedule

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    processes = []

    for _ in range(n):
        process_id, arrival_time, burst_time = sys.stdin.readline().strip().split()
        arrival_time = int(arrival_time)
        burst_time = int(burst_time)
        processes.append(ProcessDetails(process_id, arrival_time, burst_time))

    main = Main(processes)
    main.schedule_processes()

    print("Execution Order:")
    for process_id in main.get_schedule():
        print(process_id)

