
import sys

class Process:
    def __init__(self, processId, burstTime, deadline):
        self.processId = processId
        self.burstTime = burstTime
        self.deadline = deadline
        self.waitingTime = 0
        self.turnAroundTime = 0

def scheduleProcesses(processes):
    # Sort the list using a lambda function that compares the deadlines
    processes.sort(key=lambda process: process.deadline)

    # Initialize variables for current time and executed processes
    currentTime = 0
    executedProcesses = []

    # Iterate through the sorted list of processes and execute them
    for process in processes:
        # Calculate the waiting time and turnaround time for the current process
        process.waitingTime = currentTime
        currentTime += process.burstTime
        process.turnAroundTime = process.waitingTime + process.burstTime

        # Check if the current process missed its deadline
        if currentTime > process.deadline:
            print("Warning: Process " + process.processId + " missed its deadline.")

        # Add the executed process to the list of executed processes
        executedProcesses.append(process)

    # Return the list of executed processes
    return executedProcesses

def main():
    # Read the number of processes from the input
    numProcesses = int(input())

    # Initialize an array to store the Process objects
    processes = []

    # Read the details of each process and add it to the list
    for i in range(numProcesses):
        processId = input() # Read the process ID
        burstTime = int(input()) # Read the burst time
        deadline = int(input()) # Read the deadline
        processes.append(Process(processId, burstTime, deadline))

    # Schedule the processes and print the results
    executedProcesses = scheduleProcesses(processes)
    for process in executedProcesses:
        print(
            process.processId + " " +
            str(process.waitingTime) + " " +
            str(process.turnAroundTime)
        )

if __name__ == "__main__":
    main()

# 