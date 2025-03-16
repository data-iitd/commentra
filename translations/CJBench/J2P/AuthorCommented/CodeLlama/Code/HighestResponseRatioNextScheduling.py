
import sys

# Input number of processes
noOfProcesses = int(input())

# Input process details
processNames = []
arrivalTimes = []
burstTimes = []
for i in range(noOfProcesses):
    processNames.append(input())
    arrivalTimes.append(int(input()))
    burstTimes.append(int(input()))

# Calculate turn around time
turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses)

# Calculate waiting time
waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes)

# Output results
print("Process WaitingTime TurnAroundTime")
for i in range(noOfProcesses):
    print(processNames[i] + " " + str(waitingTimes[i]) + " " + str(turnAroundTimes[i]))

def calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses):
    currentTime = 0
    turnAroundTime = [0] * noOfProcesses
    processes = []

    for i in range(noOfProcesses):
        processes.append(Process(processNames[i], arrivalTimes[i], burstTimes[i]))

    processes.sort(key=lambda p: p.arrivalTime)

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

def calculateWaitingTime(turnAroundTime, burstTimes):
    waitingTime = [0] * len(turnAroundTime)
    for i in range(len(turnAroundTime)):
        waitingTime[i] = turnAroundTime[i] - burstTimes[i]
    return waitingTime

def findNextProcess(processes, currentTime):
    return findHighestResponseRatio(processes, currentTime)

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

class Process:
    def __init__(self, name, arrivalTime, burstTime):
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.turnAroundTime = 0
        self.finished = False

    def calculateResponseRatio(self, currentTime):
        return (self.burstTime + currentTime - self.arrivalTime) / self.burstTime

