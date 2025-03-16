
import sys

# Constants for special values
PROCESS_NOT_FOUND = -1
INITIAL_MAX_RESPONSE_RATIO = -1.0

# Class for process information
class Process:
    def __init__(self, name, arrivalTime, burstTime):
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.turnAroundTime = 0
        self.finished = False

    def calculateResponseRatio(self, currentTime):
        return (self.burstTime + currentTime - self.arrivalTime) / self.burstTime

def main():
    # Initialize scanner for user input
    scanner = sys.stdin

    # Read number of processes from user input
    noOfProcesses = int(scanner.readline().strip())

    # Initialize arrays for process names, arrival times, and burst times
    processNames = []
    arrivalTimes = []
    burstTimes = []

    # Read process information from user input
    for i in range(noOfProcesses):
        processNames.append(scanner.readline().strip())
        arrivalTimes.append(int(scanner.readline().strip()))
        burstTimes.append(int(scanner.readline().strip()))

    # Calculate turnaround times
    turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses)

    # Calculate waiting times
    waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes)

    # Print process information with waiting and turnaround times
    print("Process WaitingTime TurnAroundTime")
    for i in range(noOfProcesses):
        print(processNames[i] + " " + str(waitingTimes[i]) + " " + str(turnAroundTimes[i]))

    # Close scanner
    scanner.close()

def calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses):
    currentTime = 0 # Current time

    turnAroundTime = [0] * noOfProcesses # Array to store turnaround times
    processes = [Process(processNames[i], arrivalTimes[i], burstTimes[i]) for i in range(noOfProcesses)] # Array to store process objects

    # Initialize process objects
    for i in range(noOfProcesses):
        processes[i] = Process(processNames[i], arrivalTimes[i], burstTimes[i])

    # Sort processes based on arrival times
    processes.sort(key=lambda p: p.arrivalTime)

    finishedProcessCount = 0 # Number of finished processes

    # Simulate CPU scheduling
    while finishedProcessCount < noOfProcesses:
        nextProcessIndex = findNextProcess(processes, currentTime)

        if nextProcessIndex == PROCESS_NOT_FOUND:
            currentTime += 1 # Increment current time if no process is ready
            continue

        currentProcess = processes[nextProcessIndex] # Get the next process
        currentTime = max(currentTime, currentProcess.arrivalTime) # Set current time to the arrival time of the next process

        currentProcess.turnAroundTime = currentTime + currentProcess.burstTime - currentProcess.arrivalTime # Calculate turnaround time
        currentTime += currentProcess.burstTime # Increment current time by burst time of the current process
        currentProcess.finished = True # Mark the current process as finished
        finishedProcessCount += 1 # Increment finished process count

    # Copy turnaround times from process objects to the output array
    for i in range(noOfProcesses):
        turnAroundTime[i] = processes[i].turnAroundTime

    return turnAroundTime

def calculateWaitingTime(turnAroundTime, burstTimes):
    waitingTime = [0] * len(turnAroundTime) # Array to store waiting times

    for i in range(len(turnAroundTime)):
        waitingTime[i] = turnAroundTime[i] - burstTimes[i] # Calculate waiting time for each process

    return waitingTime

def findNextProcess(processes, currentTime):
    maxResponseRatio = INITIAL_MAX_RESPONSE_RATIO # Initialize maximum response ratio
    maxIndex = PROCESS_NOT_FOUND # Initialize index of the process with the maximum response ratio

    for i in range(len(processes)):
        process = processes[i] # Get the current process

        if not process.finished and process.arrivalTime <= currentTime: # Check if the process is ready and not finished
            responseRatio = process.calculateResponseRatio(currentTime) # Calculate response ratio

            if responseRatio > maxResponseRatio: # If the response ratio is higher than the current maximum
                maxResponseRatio = responseRatio # Update maximum response ratio
                maxIndex = i # Update index of the process with the maximum response ratio

    return maxIndex # Return the index of the process with the maximum response ratio

if __name__ == "__main__":
    main()

