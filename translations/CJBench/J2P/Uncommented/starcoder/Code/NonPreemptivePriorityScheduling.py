import heapq
import sys
class Process:
    def __init__(self, id, arrivalTime, burstTime, priority):
        self.id = id
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.priority = priority
        self.startTime = -1
    def __lt__(self, other):
        return self.priority < other.priority
    def __eq__(self, other):
        return self.priority == other.priority and self.arrivalTime == other.arrivalTime
def scheduleProcesses(processes):
    pq = []
    waitingQueue = []
    for process in processes:
        heapq.heappush(pq, process)
        waitingQueue.append(process)
    currentTime = 0
    index = 0
    executionOrder = [None] * len(processes)
    while waitingQueue or pq:
        while waitingQueue and waitingQueue[0].arrivalTime <= currentTime:
            heapq.heappush(pq, waitingQueue.pop(0))
        if pq:
            currentProcess = heapq.heappop(pq)
            currentProcess.startTime = currentTime
            executionOrder[index] = currentProcess
            currentTime += currentProcess.burstTime
        else:
            currentTime = waitingQueue[0].arrivalTime
    return executionOrder
def calculateAverageWaitingTime(executionOrder):
    totalWaitingTime = 0
    for process in executionOrder:
        waitingTime = process.startTime - process.arrivalTime
        totalWaitingTime += waitingTime
    return totalWaitingTime / len(executionOrder)
def calculateAverageTurnaroundTime(executionOrder):
    totalTurnaroundTime = 0
    for process in executionOrder:
        turnaroundTime = process.startTime + process.burstTime - process.arrivalTime
        totalTurnaroundTime += turnaroundTime
    return totalTurnaroundTime / len(executionOrder)
if __name__ == "__main__":
    n = int(sys.stdin.readline())
    processes = []
    for i in range(n):
        id, arrivalTime, burstTime, priority = map(int, sys.stdin.readline().split())
        processes.append(Process(id, arrivalTime, burstTime, priority))
    executionOrder = scheduleProcesses(processes)
    print("Execution Order:")
    for process in executionOrder:
        print("Process " + str(process.id) + " started at time " + str(process.startTime))
    avgWaitingTime = calculateAverageWaitingTime(executionOrder)
    avgTurnaroundTime = calculateAverageTurnaroundTime(executionOrder)
    print("Average Waiting Time: " + str(avgWaitingTime))
    print("Average Turnaround Time: " + str(avgTurnaroundTime))
