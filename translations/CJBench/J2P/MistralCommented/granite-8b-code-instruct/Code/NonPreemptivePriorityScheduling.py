

import heapq

# Define a Process class to store process details
class Process:
    def __init__(self, id, arrivalTime, burstTime, priority):
        self.id = id
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.priority = priority
        self.startTime = -1

# Function to schedule processes based on priority and arrival time
def scheduleProcesses(processes):
    # Initialize a priority queue and a waiting queue
    pq = []
    waitingQueue = []

    # Add all processes to the waiting queue
    waitingQueue.extend(processes)

    currentTime = 0 # Initialize current time
    index = 0 # Initialize index for execution order array
    executionOrder = [None] * len(processes) # Initialize execution order array

    # Simulate the CPU scheduling algorithm
    while waitingQueue or pq:
        # While the waiting queue has processes that have arrived, add them to the priority queue
        while waitingQueue and waitingQueue[0].arrivalTime <= currentTime:
            heapq.heappush(pq, waitingQueue.pop(0))

        # If the priority queue is not empty, take the process with the highest priority and execute it
        if pq:
            currentProcess = heapq.heappop(pq)
            currentProcess.startTime = currentTime # Update start time
            executionOrder[index] = currentProcess # Add to execution order
            currentTime += currentProcess.burstTime # Update current time
        else: # If the priority queue is empty, wait for the next process to arrive
            currentTime = waitingQueue[0].arrivalTime

    # Return the execution order
    return executionOrder

# Function to calculate average waiting time
def calculateAverageWaitingTime(executionOrder):
    totalWaitingTime = 0 # Initialize total waiting time

    # Calculate waiting time for each process and add to total waiting time
    for process in executionOrder:
        if process:
            waitingTime = process.startTime - process.arrivalTime
            totalWaitingTime += waitingTime

    # Calculate and return average waiting time
    return totalWaitingTime / len(executionOrder)

# Function to calculate average turnaround time
def calculateAverageTurnaroundTime(executionOrder):
    totalTurnaroundTime = 0 # Initialize total turnaround time

    # Calculate turnaround time for each process and add to total turnaround time
    for process in executionOrder:
        if process:
            turnaroundTime = process.startTime + process.burstTime - process.arrivalTime
            totalTurnaroundTime += turnaroundTime

    # Calculate and return average turnaround time
    return totalTurnaroundTime / len(executionOrder)

# Main function to read input and call scheduling functions
def main():
    # Initialize scanner to read input from the console
    import sys

    # Read number of processes from the console
    n = int(input())

    # Initialize an array of processes
    processes = [Process(0, 0, 0, 0) for _ in range(n)]

    # Read details of each process and initialize them
    for i in range(n):
        id, arrivalTime, burstTime, priority = map(int, input().split())
        processes[i] = Process(id, arrivalTime, burstTime, priority)

    # Call the scheduling function and store the execution order
    executionOrder = scheduleProcesses(processes)

    # Print the execution order
    print("Execution Order:")
    for process in executionOrder:
        if process:
            print(f"Process {process.id} started at time {process.startTime}")

    # Calculate and print average waiting time and turnaround time
    avgWaitingTime = calculateAverageWaitingTime(executionOrder)
    avgTurnaroundTime = calculateAverageTurnaroundTime(executionOrder)
    print(f"Average Waiting Time: {avgWaitingTime}")
    print(f"Average Turnaround Time: {avgTurnaroundTime}")

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "