class ProcessDetails:
    def __init__(self, process_id, arrival_time, burst_time):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time

    def get_process_id(self):
        return self.process_id

    def get_arrival_time(self):
        return self.arrival_time

    def get_burst_time(self):
        return self.burst_time


class Main:
    def __init__(self, processes):
        self.processes = processes
        self.schedule = []
        self.sort_processes_by_arrival_time(self.processes)

    @staticmethod
    def sort_processes_by_arrival_time(processes):
        processes.sort(key=lambda p: p.get_arrival_time())

    def schedule_processes(self):
        ready = []  # List of processes that are ready to execute
        size = len(self.processes)  # Total number of processes
        time = 0  # Current time in the scheduling
        executed = 0  # Count of executed processes
        k = 0  # Index for traversing the processes

        # If there are no processes, exit the method
        if size == 0:
            return

        # Loop until all processes are executed
        while executed < size:
            # Add processes that have arrived by the current time to the ready list
            while k < size and self.processes[k].get_arrival_time() <= time:
                ready.append(self.processes[k])
                k += 1

            # Find the shortest job from the ready processes
            running = self.find_shortest_job(ready)
            if running is None:
                # If no process is ready, increment time
                time += 1
            else:
                # Execute the shortest job
                time += running.get_burst_time()  # Increment time by the burst time of the running process
                self.schedule.append(running.get_process_id())  # Add the process ID to the schedule
                ready.remove(running)  # Remove the running process from the ready list
                executed += 1  # Increment the count of executed processes

    @staticmethod
    def find_shortest_job(ready_processes):
        if not ready_processes:
            return None  # Return None if there are no ready processes
        # Return the process with the minimum burst time
        return min(ready_processes, key=lambda p: p.get_burst_time())

    def get_schedule(self):
        return self.schedule


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])  # Read the number of processes
    processes = []

    # Read process details from input
    for i in range(1, n + 1):
        process_id = data[i * 3 - 2]
        arrival_time = int(data[i * 3 - 1])
        burst_time = int(data[i * 3])
        processes.append(ProcessDetails(process_id, arrival_time, burst_time))

    # Create an instance of Main with the list of processes
    sjf_scheduling = Main(processes)
    # Schedule the processes
    sjf_scheduling.schedule_processes()

    # Print the execution order of processes
    print("Execution Order:")
    for process_id in sjf_scheduling.get_schedule():
        print(process_id)
