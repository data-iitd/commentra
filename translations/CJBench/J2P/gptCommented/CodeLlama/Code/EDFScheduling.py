
# Import the necessary libraries
from collections import namedtuple
from typing import List

# Define a named tuple to represent a process
Process = namedtuple("Process", ["process_id", "burst_time", "deadline"])

def schedule_processes(processes: List[Process]) -> List[Process]:
    # Sort the processes based on their deadlines
    processes.sort(key=lambda process: process.deadline)
    
    # Initialize the current time to track the scheduling
    current_time = 0
    
    # List to hold the processes that have been executed
    executed_processes = []
    
    # Loop through each process to calculate waiting and turnaround times
    for process in processes:
        # Set the waiting time for the current process
        process.waiting_time = current_time
        
        # Update the current time by adding the burst time of the current process
        current_time += process.burst_time
        
        # Calculate the turnaround time for the current process
        process.turnaround_time = process.waiting_time + process.burst_time
        
        # Check if the process has missed its deadline and print a warning if so
        if current_time > process.deadline:
            print(f"Warning: Process {process.process_id} missed its deadline.")
        
        # Add the current process to the list of executed processes
        executed_processes.append(process)
    
    # Return the list of executed processes
    return executed_processes

# Main function to read input from the console and schedule the processes
def main():
    # Create a Scanner object to read input from the console
    scanner = Scanner(System.in)
    
    # Read the number of processes to be scheduled
    num_processes = scanner.nextInt()
    
    # Initialize a list to hold the processes
    processes = []
    
    # Loop to read each process's details
    for i in range(num_processes):
        process_id = scanner.next()
        burst_time = scanner.nextInt()
        deadline = scanner.nextInt()
        # Add the new process to the list
        processes.append(Process(process_id, burst_time, deadline))
    
    # Schedule the processes and get the list of executed processes
    executed_processes = schedule_processes(processes)
    
    # Output the results for each executed process
    for process in executed_processes:
        print(
            process.process_id + " " +
            process.waiting_time + " " +
            process.turnaround_time
        )
    
    # Close the scanner to prevent resource leaks
    scanner.close()

if __name__ == "__main__":
    main()

