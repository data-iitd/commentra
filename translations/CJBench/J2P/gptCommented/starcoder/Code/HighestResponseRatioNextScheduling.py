import sys
import math

# Class representing a process with its attributes
class Process:
    def __init__(self, name, arrivalTime, burstTime):
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.turnAroundTime = 0
        self.finished = False

    # Method to calculate the response ratio of the process
    def calculateResponseRatio(self, currentTime):
        return (self.burstTime + currentTime - self.arrivalTime) / self.burstTime

# Method to calculate turnaround times for all processes
def calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses):
    currentTime = 0 # Initialize current time
    turnAroundTime = [0] * noOfProcesses # Array to store turnaround times
    processes = [None] * noOfProcesses # Array to hold process objects

    # Create process objects and initialize them
    for i in range(noOfProcesses):
        processes[i] = Process(processNames[i], arrivalTimes[i], burstTimes[i])

    # Sort processes based on their arrival times
    processes.sort(key = lambda p: p.arrivalTime)

    finishedProcessCount = 0 # Counter for finished processes

    # Process scheduling loop
    while finishedProcessCount < noOfProcesses:
        # Find the next process to execute based on response ratio
        nextProcessIndex = findNextProcess(processes, currentTime)
        if nextProcessIndex == -1:
            # If no process is found, increment current time
            currentTime += 1
            continue

        # Get the current process to execute
        currentProcess = processes[nextProcessIndex]
        # Update current time to the arrival time of the current process if necessary
        currentTime = max(currentTime, currentProcess.arrivalTime)
        # Calculate turnaround time for the current process
        currentProcess.turnAroundTime = currentTime + currentProcess.burstTime - currentProcess.arrivalTime
        # Update current time after executing the current process
        currentTime += currentProcess.burstTime
        # Mark the current process as finished
        currentProcess.finished = True
        finishedProcessCount += 1 # Increment the count of finished processes

    # Store the calculated turnaround times in the array
    for i in range(noOfProcesses):
        turnAroundTime[i] = processes[i].turnAroundTime
    return turnAroundTime # Return the array of turnaround times

# Method to calculate waiting times based on turnaround times and burst times
def calculateWaitingTime(turnAroundTime, burstTimes):
    waitingTime = [0] * len(turnAroundTime) # Array to store waiting times
    # Calculate waiting time for each process
    for i in range(len(turnAroundTime)):
        waitingTime[i] = turnAroundTime[i] - burstTimes[i]
    return waitingTime # Return the array of waiting times

# Method to find the next process to execute based on response ratio
def findNextProcess(processes, currentTime):
    return findHighestResponseRatio(processes, currentTime) # Delegate to find highest response ratio

# Method to find the process with the highest response ratio
def findHighestResponseRatio(processes, currentTime):
    maxResponseRatio = -1.0 # Initialize maximum response ratio
    maxIndex = -1 # Index of the process with the highest response ratio

    # Iterate through processes to find the one with the highest response ratio
    for i in range(len(processes)):
        process = processes[i]
        # Check if the process is not finished and has arrived
        if not process.finished and process.arrivalTime <= currentTime:
            responseRatio = process.calculateResponseRatio(currentTime)
            # Update maximum response ratio and index if a higher one is found
            if responseRatio > maxResponseRatio:
                maxResponseRatio = responseRatio
                maxIndex = i

    return maxIndex # Return the index of the process with the highest response ratio

# Main function
def main():
    # Read the number of processes
    noOfProcesses = int(input())
    processNames = [None] * noOfProcesses
    arrivalTimes = [0] * noOfProcesses
    burstTimes = [0] * noOfProcesses

    # Read process details from user input
    for i in range(noOfProcesses):
        processNames[i] = input()
        arrivalTimes[i] = int(input())
        burstTimes[i] = int(input())

    # Calculate turnaround times for the processes
    turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses)
    # Calculate waiting times based on turnaround times
    waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes)

    # Print the waiting and turnaround times for each process
    print("Process WaitingTime TurnAroundTime")
    for i in range(noOfProcesses):
        print(processNames[i], waitingTimes[i], turnAroundTimes[i])

# Entry point of the program
if __name__ == "__main__":
    main()

