
import sys

# Class to hold the details of each process
class ProcessDetails:
    def __init__(self, process_id, arrival_time, burst_time):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time

# Class to implement the Shortest Job First (SJF) algorithm
class SJFScheduling:
    def __init__(self, processes):
        self.processes = processes
        self.schedule = []
        self.sort_processes_by_arrival_time(self.processes)

    # Method to sort processes based on their arrival time
    def sort_processes_by_arrival_time(self, processes):
        processes.sort(key=lambda p: p.arrival_time)

    # Method to schedule processes using Shortest Job First (SJF) algorithm
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
            while k < size and self.processes[k].arrival_time <= time:
                ready.append(self.processes[k])
                k += 1

            # Find the shortest job from the ready processes
            running = self.find_shortest_job(ready)
            if running is None:
                # If no process is ready, increment time
                time += 1
            else:
                # Execute the shortest job
                time += running.burst_time  # Increment time by the burst time of the running process
                self.schedule.append(running.process_id)  # Add the process ID to the schedule
                ready.remove(running)  # Remove the running process from the ready list
                executed += 1  # Increment the count of executed processes

    # Method to find the process with the shortest burst time from the ready list
    def find_shortest_job(self, ready_processes):
        if not ready_processes:
            return None  # Return null if there are no ready processes
        # Return the process with the minimum burst time
        return min(ready_processes, key=lambda p: p.burst_time)

    # Method to get the scheduled order of processes
    def get_schedule(self):
        return self.schedule

# Main method to execute the program
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())  # Read the number of processes
    processes = []

    # Read process details from input
    for i in range(n):
        process_id, arrival_time, burst_time = sys.stdin.readline().strip().split()
        processes.append(ProcessDetails(process_id, int(arrival_time), int(burst_time)))

    # Create an instance of SJFScheduling with the list of processes
    sjf_scheduling = SJFScheduling(processes)
    # Schedule the processes
    sjf_scheduling.schedule_processes()

    # Print the execution order of processes
    print("Execution Order:")
    for process_id in sjf_scheduling.get_schedule():
        print(process_id)

