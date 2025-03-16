

import sys

# Define a Process class to represent a process
class Process:
    def __init__(self, process_id, burst_time, deadline):
        self.process_id = process_id
        self.burst_time = burst_time
        self.deadline = deadline
        self.waiting_time = 0
        self.turn_around_time = 0

# Define a function to schedule the processes and print the results
def schedule_processes(processes):
    # Sort the list of processes based on their deadlines
    processes.sort(key=lambda x: x.deadline)

    # Initialize variables for current time and executed processes
    current_time = 0
    executed_processes = []

    # Iterate through the sorted list of processes and execute them
    for process in processes:
        # Calculate the waiting time and turnaround time for the current process
        process.waiting_time = current_time
        current_time += process.burst_time
        process.turn_around_time = process.waiting_time + process.burst_time

        # Check if the current process missed its deadline
        if current_time > process.deadline:
            print("Warning: Process " + process.process_id + " missed its deadline.")

        # Add the executed process to the list of executed processes
        executed_processes.append(process)

    # Return the list of executed processes
    return executed_processes

# Read the number of processes from the input
num_processes = int(input())

# Initialize an empty list to store the Process objects
processes = []

# Read the details of each process and add it to the list
for i in range(num_processes):
    process_id, burst_time, deadline = input().split()
    processes.append(Process(process_id, int(burst_time), int(deadline)))

# Schedule the processes and print the results
executed_processes = schedule_processes(processes)
for process in executed_processes:
    print(
        process.process_id + " " +
        str(process.waiting_time) + " " +
        str(process.turn_around_time)
    )

# End the program
print("