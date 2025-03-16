
import sys

# Initialize a Scanner to read input from the console
scanner = sys.stdin

# Read the number of processes from the input
num_processes = int(scanner.readline().strip())

# Initialize an ArrayList to store the Process objects
processes = []

# Read the details of each process and add it to the list
for i in range(num_processes):
    process_id, burst_time, deadline = scanner.readline().strip().split()
    processes.append(Process(process_id, int(burst_time), int(deadline)))

# Schedule the processes and print the results
executed_processes = schedule_processes(processes)
for process in executed_processes:
    print(
        process.process_id + " " +
        process.waiting_time + " " +
        process.turnaround_time
    )

# Close the Scanner to free system resources
scanner.close()

# Define a static inner class Process to represent a process
class Process:
    def __init__(self, process_id, burst_time, deadline):
        self.process_id = process_id
        self.burst_time = burst_time
        self.deadline = deadline
        self.waiting_time = 0
        self.turnaround_time = 0

    # Getters for the process ID, burst time, deadline, waiting time, and turnaround time
    def get_process_id(self):
        return self.process_id
    def get_burst_time(self):
        return self.burst_time
    def get_deadline(self):
        return self.deadline
    def get_waiting_time(self):
        return self.waiting_time
    def set_waiting_time(self, waiting_time):
        self.waiting_time = waiting_time
    def get_turnaround_time(self):
        return self.turnaround_time
    def set_turnaround_time(self, turnaround_time):
        self.turnaround_time = turnaround_time

# Sort the list of processes based on their deadlines
def schedule_processes(processes):
    # Sort the list using a Comparator that compares the deadlines
    processes.sort(key=lambda process: process.get_deadline())

    # Initialize variables for current time and executed processes
    current_time = 0
    executed_processes = []

    # Iterate through the sorted list of processes and execute them
    for process in processes:
        # Calculate the waiting time and turnaround time for the current process
        process.set_waiting_time(current_time)
        current_time += process.get_burst_time()
        process.set_turnaround_time(process.get_waiting_time() + process.get_burst_time())

        # Check if the current process missed its deadline
        if current_time > process.get_deadline():
            print("Warning: Process " + process.get_process_id() + " missed its deadline.")

        # Add the executed process to the list of executed processes
        executed_processes.append(process)

    # Return the list of executed processes
    return executed_processes

# 