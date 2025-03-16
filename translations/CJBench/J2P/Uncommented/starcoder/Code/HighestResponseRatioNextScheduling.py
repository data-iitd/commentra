import sys
import math
import operator

class Process:
    def __init__(self, name, arrivalTime, burstTime):
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.turnAroundTime = 0
        self.finished = False

def calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses):
    currentTime = 0
    turnAroundTime = [0] * noOfProcesses
    processes = [Process(processNames[i], arrivalTimes[i], burstTimes[i]) for i in range(noOfProcesses)]
    processes.sort(key=operator.attrgetter('arrivalTime'))
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
    maxResponseRatio = -1.0
    maxIndex = -1
    for i in range(len(processes)):
        process = processes[i]
        if not process.finished and process.arrivalTime <= currentTime:
            responseRatio = (process.burstTime + currentTime - process.arrivalTime) / process.burstTime
            if responseRatio > maxResponseRatio:
                maxResponseRatio = responseRatio
                maxIndex = i
    return maxIndex

def main():
    noOfProcesses = int(input())
    processNames = [input() for i in range(noOfProcesses)]
    arrivalTimes = [int(input()) for i in range(noOfProcesses)]
    burstTimes = [int(input()) for i in range(noOfProcesses)]
    turnAroundTime = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses)
    waitingTime = calculateWaitingTime(turnAroundTime, burstTimes)
    print("Process WaitingTime TurnAroundTime")
    for i in range(noOfProcesses):
        print(processNames[i], waitingTime[i], turnAroundTime[i])

if __name__ == "__main__":
    main()

