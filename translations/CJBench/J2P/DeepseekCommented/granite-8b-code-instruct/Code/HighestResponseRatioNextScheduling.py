
import sys
import heapq

# Define a class to store process details
class Process:
    def __init__(self, name, arrivalTime, burstTime):
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.turnAroundTime = 0
        self.finished = False

    # Method to calculate response ratio
    def calculateResponseRatio(self, currentTime):
        return (self.burstTime + currentTime - self.arrivalTime) / self.burstTime

# Main method to execute the program
def main():
    noOfProcesses = int(input()) # Read the number of processes
    processNames = []
    arrivalTimes = []
    burstTimes = []
    for i in range(noOfProcesses):
        processName, arrivalTime, burstTime = input().split() # Read process names, arrival times, and burst times
        processNames.append(processName)
        arrivalTimes.append(int(arrivalTime))
        burstTimes.append(int(burstTime))

    turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses)
    waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes)
    print("Process WaitingTime TurnAroundTime")
    for i in range(noOfProcesses):
        print(processNames[i] + " " + str(waitingTimes[i]) + " " + str(turnAroundTimes[i]))

# Method to calculate turn around times
def calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses):
    currentTime = 0
    turnAroundTime = [0] * noOfProcesses
    processes = []
    for i in range(noOfProcesses):
        processes.append(Process(processNames[i], arrivalTimes[i], burstTimes[i]))
    processes.sort(key=lambda p: p.arrivalTime) # Sort processes by arrival time
    finishedProcessCount = 0
    while finishedProcessCount < noOfProcesses:
        nextProcessIndex = findNextProcess(processes, currentTime)
        if nextProcessIndex == -1:
            currentTime += 1
            continue
        currentProcess = processes[nextProcessIndex]
        currentTime = max(currentTime, currentProcess.arrivalTime)
        currentProcess.turnAroundTime = currentTime + currentProcess.burstTime - currentProcess.arrivalTime
        currentTime += currentProcess.burstTime
        currentProcess.finished = True
        finishedProcessCount += 1
    for i in range(noOfProcesses):
        turnAroundTime[i] = processes[i].turnAroundTime
    return turnAroundTime

# Method to calculate waiting times
def calculateWaitingTime(turnAroundTime, burstTimes):
    waitingTime = [0] * len(turnAroundTime)
    for i in range(len(turnAroundTime)):
        waitingTime[i] = turnAroundTime[i] - burstTimes[i]
    return waitingTime

# Method to find the next process to execute
def findNextProcess(processes, currentTime):
    return findHighestResponseRatio(processes, currentTime)

# Method to find the process with the highest response ratio
def findHighestResponseRatio(processes, currentTime):
    maxResponseRatio = -1.0
    maxIndex = -1
    for i in range(len(processes)):
        process = processes[i]
        if not process.finished and process.arrivalTime <= currentTime:
            responseRatio = process.calculateResponseRatio(currentTime)
            if responseRatio > maxResponseRatio:
                maxResponseRatio = responseRatio
                maxIndex = i
    return maxIndex

if __name__ == "__main__":
    main()

