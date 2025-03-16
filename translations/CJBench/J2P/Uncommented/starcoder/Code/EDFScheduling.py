import sys
import heapq

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

    def setWaitingTime(self, waitingTime):
        self.waitingTime = waitingTime

    def getTurnAroundTime(self):
        return self.turnAroundTime

    def setTurnAroundTime(self, turnAroundTime):
        self.turnAroundTime = turnAroundTime

def scheduleProcesses(processes):
    processes.sort(key=lambda process: process.getDeadline())
    currentTime = 0
    executedProcesses = []
    for process in processes:
        process.setWaitingTime(currentTime)
        currentTime += process.getBurstTime()
        process.setTurnAroundTime(process.getWaitingTime() + process.getBurstTime())
        if currentTime > process.getDeadline():
            print("Warning: Process " + process.getProcessId() + " missed its deadline.")
        executedProcesses.append(process)
    return executedProcesses

def main():
    numProcesses = int(sys.stdin.readline().strip())
    processes = []
    for i in range(numProcesses):
        processId, burstTime, deadline = sys.stdin.readline().strip().split()
        processes.append(Process(processId, int(burstTime), int(deadline)))
    executedProcesses = scheduleProcesses(processes)
    for process in executedProcesses:
        print(
            process.getProcessId() + " " +
            str(process.getWaitingTime()) + " " +
            str(process.getTurnAroundTime())
        )

if __name__ == "__main__":
    main()

