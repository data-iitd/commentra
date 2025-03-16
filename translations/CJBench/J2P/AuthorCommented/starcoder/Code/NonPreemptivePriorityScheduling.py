import sys
import heapq

# Represents a process with an ID, arrival time, burst time, priority, and start time.
class Process:
    def __init__(self, id, arrivalTime, burstTime, priority):
        self.id = id
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.priority = priority
        self.startTime = -1 # Indicates the process has not started yet

    def __lt__(self, other):
        return self.priority < other.priority

# Schedules the processes based on their priority in a non-preemptive manner.
def scheduleProcesses(processes):
    pq = []
    waitingQueue = []
    for process in processes:
        heapq.heappush(pq, process)
        waitingQueue.append(process)

    currentTime = 0
    index = 0
    executionOrder = [None] * len(processes)

    while len(waitingQueue) > 0 or len(pq) > 0:
        # Add processes that have arrived to the priority queue
        while len(waitingQueue) > 0 and waitingQueue[0].arrivalTime <= currentTime:
            heapq.heappush(pq, waitingQueue.pop(0))

        if len(pq) > 0:
            currentProcess = heapq.heappop(pq)
            currentProcess.startTime = currentTime
            executionOrder[index] = currentProcess
            currentTime += currentProcess.burstTime
            index += 1
        else:
            # If no process is ready, move to the next arrival time
            currentTime = waitingQueue[0].arrivalTime

    return executionOrder

# Calculates the average waiting time of the processes.
def calculateAverageWaitingTime(executionOrder):
    totalWaitingTime = 0
    for process in executionOrder:
        waitingTime = process.startTime - process.arrivalTime
        totalWaitingTime += waitingTime
    return totalWaitingTime / len(executionOrder)

# Calculates the average turnaround time of the processes.
def calculateAverageTurnaroundTime(executionOrder):
    totalTurnaroundTime = 0
    for process in executionOrder:
        turnaroundTime = process.startTime + process.burstTime - process.arrivalTime
        totalTurnaroundTime += turnaroundTime
    return totalTurnaroundTime / len(executionOrder)

if __name__ == "__main__":
    # Input number of processes
    n = int(sys.stdin.readline())
    processes = []

    # Input process details
    for i in range(n):
        id, arrivalTime, burstTime, priority = map(int, sys.stdin.readline().split())
        processes.append(Process(id, arrivalTime, burstTime, priority))

    # Schedule processes
    executionOrder = scheduleProcesses(processes)

    # Output execution order
    print("Execution Order:")
    for process in executionOrder:
        print("Process " + str(process.id) + " started at time " + str(process.startTime))

    avgWaitingTime = calculateAverageWaitingTime(executionOrder)
    avgTurnaroundTime = calculateAverageTurnaroundTime(executionOrder)

    print("Average Waiting Time: " + str(avgWaitingTime))
    print("Average Turnaround Time: " + str(avgTurnaroundTime))

