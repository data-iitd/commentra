
# Import the necessary modules
from collections import namedtuple
from typing import List

# Define a named tuple to represent a process
Process = namedtuple("Process", ["process_id", "burst_time", "deadline"])

# Define a function to schedule processes based on their deadlines
def schedule_processes(processes: List[Process]) -> List[Process]:
    # Sort the processes by their deadlines
    processes.sort(key=lambda process: process.deadline)
    # Initialize the current time to 0
    current_time = 0
    # Create a list to store the executed processes
    executed_processes = []
    # Loop through each process to calculate waiting and turnaround times
    for process in processes:
        # Set the waiting time for the current process
        process.waiting_time = current_time
        # Update the current time by adding the burst time of the current process
        current_time += process.burst_time
        # Set the turnaround time for the current process
        process.turnaround_time = process.waiting_time + process.burst_time
        # Check if the process missed its deadline and print a warning if it did
        if current_time > process.deadline:
            print(f"Warning: Process {process.process_id} missed its deadline.")
        # Add the current process to the list of executed processes
        executed_processes.append(process)
    # Return the list of executed processes
    return executed_processes

# Main function
def main():
    # Initialize a list to store the processes
    processes = []
    # Loop to read each process's details and add to the list
    for _ in range(int(input())):
        process_id = input()
        burst_time = int(input())
        deadline = int(input())
        processes.append(Process(process_id, burst_time, deadline))
    # Schedule the processes and get the list of executed processes
    executed_processes = schedule_processes(processes)
    # Loop to print the details of each executed process
    for process in executed_processes:
        print(
            process.process_id,
            process.waiting_time,
            process.turnaround_time,
            sep=" "
        )

# Call the main function
if __name__ == "__main__":
    main()

# END-OF-CODE
