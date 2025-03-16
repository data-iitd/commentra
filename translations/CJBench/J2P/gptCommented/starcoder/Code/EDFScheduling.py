import sys

class Process:
    def __init__(self, processId, burstTime, deadline):
        self.processId = processId
        self.burstTime = burstTime
        self.deadline = deadline
        self.waitingTime = 0
        self.turnAroundTime = 0

    def getProcessId(self):
        return self.processId

    def getBurstTime(self):
        return self.burstTime

    def getDeadline(self):
        return self.deadline

    def getWaitingTime(self):
        return self.waitingTime

    def getTurnAroundTime(self):
        return self.turnAroundTime

    def setWaitingTime(self, waitingTime):
        self.waitingTime = waitingTime

    def setTurnAroundTime(self, turnAroundTime):
        self.turnAroundTime = turnAroundTime

def scheduleProcesses(processes):
    # Sort the processes based on their deadlines
    processes.sort(key=lambda process: process.getDeadline())

    # Initialize the current time to track the scheduling
    currentTime = 0

    # List to hold the processes that have been executed
    executedProcesses = []

    # Loop through each process to calculate waiting and turnaround times
    for process in processes:
        # Set the waiting time for the current process
        process.setWaitingTime(currentTime)

        # Update the current time by adding the burst time of the current process
        currentTime += process.getBurstTime()

        # Calculate the turnaround time for the current process
        process.setTurnAroundTime(process.getWaitingTime() + process.getBurstTime())

        # Check if the process has missed its deadline and print a warning if so
        if currentTime > process.getDeadline():
            print("Warning: Process " + process.getProcessId() + " missed its deadline.")

        # Add the current process to the list of executed processes
        executedProcesses.append(process)

    # Return the list of executed processes
    return executedProcesses

def main():
    # Create a Scanner object to read input from the console
    scanner = sys.stdin

    # Read the number of processes to be scheduled
    numProcesses = int(scanner.readline())

    # Initialize a list to hold the processes
    processes = []

    # Loop to read each process's details
    for i in range(numProcesses):
        processId, burstTime, deadline = scanner.readline().split()
        # Add the new process to the list
        processes.append(Process(processId, int(burstTime), int(deadline)))

    # Schedule the processes and get the list of executed processes
    executedProcesses = scheduleProcesses(processes)

    # Output the results for each executed process
    for process in executedProcesses:
        print(
            process.getProcessId() + " " +
            str(process.getWaitingTime()) + " " +
            str(process.getTurnAroundTime())
        )

if __name__ == "__main__":
    main()

# 