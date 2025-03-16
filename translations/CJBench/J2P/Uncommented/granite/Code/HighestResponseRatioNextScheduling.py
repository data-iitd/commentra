
import sys
import heapq

def calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses):
    currentTime = 0
    turnAroundTime = [0] * noOfProcesses
    processes = []
    for i in range(noOfProcesses):
        processes.append((arrivalTimes[i], i))
    processes.sort()
    finishedProcessCount = 0
    while finishedProcessCount < noOfProcesses:
        nextProcessIndex = findNextProcess(processes, currentTime)
        if nextProcessIndex == -1:
            currentTime += 1
            continue
        currentProcess = processes[nextProcessIndex]
        currentTime = max(currentTime, currentProcess[0])
        turnAroundTime[currentProcess[1]] = currentTime + burstTimes[currentProcess[1]] - currentProcess[0]
        currentTime += burstTimes[currentProcess[1]]
        processes[nextProcessIndex] = (-1, -1)
        finishedProcessCount += 1
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
        if processes[i][0] <= currentTime and processes[i][0]!= -1:
            responseRatio = (burstTimes[processes[i][1]] + currentTime - arrivalTimes[processes[i][1]]) / burstTimes[processes[i][1]]
            if responseRatio > maxResponseRatio:
                maxResponseRatio = responseRatio
                maxIndex = i
    return maxIndex

if __name__ == "__main__":
    noOfProcesses = int(input())
    processNames = []
    arrivalTimes = []
    burstTimes = []
    for i in range(noOfProcesses):
        process, arrivalTime, burstTime = input().split()
        processNames.append(process)
        arrivalTimes.append(int(arrivalTime))
        burstTimes.append(int(burstTime))
    turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses)
    waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes)
    print("Process WaitingTime TurnAroundTime")
    for i in range(noOfProcesses):
        print(processNames[i] + " " + str(waitingTimes[i]) + " " + str(turnAroundTimes[i]))

