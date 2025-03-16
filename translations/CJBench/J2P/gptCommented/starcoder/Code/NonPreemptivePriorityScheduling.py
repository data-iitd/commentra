import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class Main:
    # Class representing a process with its attributes and comparison logic
    class Process:
        def __init__(self, id, arrivalTime, burstTime, priority):
            self.id = id
            self.arrivalTime = arrivalTime
            self.burstTime = burstTime
            self.priority = priority
            self.startTime = -1 # Initialize start time to -1 (not started)

        # Comparison logic for priority queue based on priority and arrival time
        def compareTo(self, other):
            if self.priority == other.priority:
                return Integer.compare(self.arrivalTime, other.arrivalTime)
            return Integer.compare(self.priority, other.priority)

    # Method to schedule processes based on their arrival time and priority
    def scheduleProcesses(self, processes):
        # Priority queue to manage processes based on priority
        pq = PriorityQueue<Process>()
        # Queue to hold processes that are waiting to be scheduled
        waitingQueue = LinkedList<Process>()
        # Add all processes to the waiting queue
        Collections.addAll(waitingQueue, processes)
        
        currentTime = 0 # Tracks the current time in the scheduling
        index = 0 # Index to track the execution order
        executionOrder = [None] * len(processes) # Array to store execution order

        # Loop until all processes are executed
        while not waitingQueue.isEmpty() or not pq.isEmpty():
            # Add processes that have arrived to the priority queue
            while not waitingQueue.isEmpty() and waitingQueue.peek().arrivalTime <= currentTime:
                pq.add(waitingQueue.poll())
            # If there are processes in the priority queue, execute the highest priority one
            if not pq.isEmpty():
                currentProcess = pq.poll() # Get the process with the highest priority
                currentProcess.startTime = currentTime # Set the start time for the current process
                executionOrder[index] = currentProcess # Record the execution order
                currentTime += currentProcess.burstTime # Update current time after execution
            else:
                # If no process is ready, jump to the next arriving process
                currentTime = waitingQueue.peek().arrivalTime
            index += 1
        return executionOrder # Return the order in which processes were executed

    # Method to calculate the average waiting time of the executed processes
    def calculateAverageWaitingTime(self, executionOrder):
        totalWaitingTime = 0 # Variable to accumulate total waiting time
        # Calculate waiting time for each process
        for process in executionOrder:
            waitingTime = process.startTime - process.arrivalTime # Calculate waiting time
            totalWaitingTime += waitingTime # Add to total waiting time
        # Return average waiting time
        return totalWaitingTime / len(executionOrder)

    # Method to calculate the average turnaround time of the executed processes
    def calculateAverageTurnaroundTime(self, executionOrder):
        totalTurnaroundTime = 0 # Variable to accumulate total turnaround time
        # Calculate turnaround time for each process
        for process in executionOrder:
            turnaroundTime = process.startTime + process.burstTime - process.arrivalTime # Calculate turnaround time
            totalTurnaroundTime += turnaroundTime # Add to total turnaround time
        # Return average turnaround time
        return totalTurnaroundTime / len(executionOrder)

    # Main method to execute the scheduling program
    def main(self):
        scanner = java.util.Scanner(System.in)
        n = scanner.nextInt() # Read the number of processes
        processes = [None] * n # Array to hold the processes

        # Read process details from input
        for i in range(n):
            id = scanner.nextInt() # Read process ID
            arrivalTime = scanner.nextInt() # Read arrival time
            burstTime = scanner.nextInt() # Read burst time
            priority = scanner.nextInt() # Read priority
            processes[i] = self.Process(id, arrivalTime, burstTime, priority) # Create process object

        # Schedule the processes and get the execution order
        executionOrder = self.scheduleProcesses(processes)
        print("Execution Order:")
        # Print the execution order of processes
        for process in executionOrder:
            print("Process " + str(process.id) + " started at time " + str(process.startTime))

        # Calculate and print average waiting time
        avgWaitingTime = self.calculateAverageWaitingTime(executionOrder)
        # Calculate and print average turnaround time
        avgTurnaroundTime = self.calculateAverageTurnaroundTime(executionOrder)
        print("Average Waiting Time: " + str(avgWaitingTime))
        print("Average Turnaround Time: " + str(avgTurnaroundTime))
        
        scanner.close() # Close the scanner resource

# 