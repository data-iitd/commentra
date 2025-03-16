
import heapq
import collections
class Process:
    def __init__(self, id, arrivalTime, burstTime, priority):
        self.id = id
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.priority = priority
        self.startTime = -1
def scheduleProcesses(processes):
    pq = []
    waitingQueue = collections.deque(processes)
    currentTime = 0
    index = 0
    executionOrder = [None] * len(processes)
    while waitingQueue or pq:
        while waitingQueue and waitingQueue[0].arrivalTime <= currentTime:
            heapq.heappush(pq, waitingQueue.popleft())
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
        if process:
            waitingTime = process.startTime - process.arrivalTime
            totalWaitingTime += waitingTime
    return totalWaitingTime / len(executionOrder)
def calculateAverageTurnaroundTime(executionOrder):
    totalTurnaroundTime = 0
    for process in executionOrder:
        if process:
            turnaroundTime = process.startTime + process.burstTime - process.arrivalTime
            totalTurnaroundTime += turnaroundTime
    return totalTurnaroundTime / len(executionOrder)
if __name__ == "__main__":
    import sys
    n = int(input())
    processes = [Process(*map(int, input().split())) for _ in range(n)]
    executionOrder = scheduleProcesses(processes)
    print("Execution Order:")
    for process in executionOrder:
        if process:
            print(f"Process {process.id} started at time {process.startTime}")
    avgWaitingTime = calculateAverageWaitingTime(executionOrder)
    avgTurnaroundTime = calculateAverageTurnaroundTime(executionOrder)
    print(f"Average Waiting Time: {avgWaitingTime:.2f}")
    print(f"Average Turnaround Time: {avgTurnaroundTime:.2f}")
