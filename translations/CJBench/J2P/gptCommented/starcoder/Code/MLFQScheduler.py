import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Main:
    # List of queues to hold processes at different priority levels
    queues = []
    # Array to hold time quantums for each priority level
    timeQuantum = []
    # Variable to track the current time in the scheduling process
    currentTime = 0

    # Constructor to initialize the scheduler with the number of levels and their respective time quantums
    def __init__(self, levels, timeQuantums):
        self.queues = [LinkedList() for i in range(levels)]
        # Initialize each queue for the different priority levels
        for i in range(levels):
            self.queues[i] = LinkedList()
        self.timeQuantum = timeQuantums
        self.currentTime = 0 # Start time at 0

    # Method to add a new process to the highest priority queue (queue 0)
    def addProcess(self, p):
        self.queues[0].add(p)

    # Method to run the scheduling algorithm
    def run(self):
        # Continue running until all queues are empty
        while not self.allQueuesEmpty():
            # Iterate through each priority level's queue
            for i in range(len(self.queues)):
                queue = self.queues[i]
                # If the current queue is not empty, process the next process
                if not queue.isEmpty():
                    p = queue.poll() # Get the next process from the queue
                    quantum = self.timeQuantum[i] # Get the time quantum for the current level
                    timeSlice = min(quantum, p.remainingTime) # Determine the time slice to execute

                    # Execute the process for the determined time slice
                    p.execute(timeSlice)
                    self.currentTime += timeSlice # Update the current time

                    # Check if the process has finished executing
                    if p.isFinished():
                        print("Process " + str(p.pid) + " finished at time " + str(self.currentTime))
                    else:
                        # If not finished and not at the last queue, increase priority and move to the next queue
                        if i < len(self.queues) - 1:
                            p.priority += 1
                            self.queues[i + 1].add(p) # Add to the next priority queue
                        else:
                            queue.add(p) # If at the last queue, re-add to the same queue
                else:
                    continue

    # Helper method to check if all queues are empty
    def allQueuesEmpty(self):
        for queue in self.queues:
            if not queue.isEmpty():
                return False # If any queue is not empty, return false
        return True # All queues are empty

# Class representing a process with its attributes and methods
class Process:
    pid = 0 # Process ID
    burstTime = 0 # Total burst time required for the process
    remainingTime = 0 # Remaining time for the process to finish
    arrivalTime = 0 # Arrival time of the process
    priority = 0 # Priority level of the process

    # Constructor to initialize a process with its attributes
    def __init__(self, pid, burstTime, arrivalTime):
        self.pid = pid
        self.burstTime = burstTime
        self.remainingTime = burstTime # Initially, remaining time is equal to burst time
        self.arrivalTime = arrivalTime
        self.priority = 0 # Initial priority is set to 0

    # Method to execute the process for a given time slice
    def execute(self, timeSlice):
        self.remainingTime -= timeSlice # Decrease the remaining time by the time slice
        if self.remainingTime < 0:
            self.remainingTime = 0 # Ensure remaining time does not go negative

    # Method to check if the process has finished executing
    def isFinished(self):
        return self.remainingTime == 0 # Process is finished if remaining time is 0

if __name__ == "__main__":
    scanner = Scanner(System.in)
    # Read the number of priority levels
    levels = scanner.nextInt()
    timeQuantums = []
    # Read the time quantums for each level
    for i in range(levels):
        timeQuantums.append(scanner.nextInt())
    # Initialize the scheduler with levels and time quantums
    scheduler = Main(levels, timeQuantums)
    # Read the number of processes to schedule
    n = scanner.nextInt()
    # Read each process's details and add to the scheduler
    for i in range(n):
        pid = scanner.nextInt() # Process ID
        burstTime = scanner.nextInt() # Burst time of the process
        arrivalTime = scanner.nextInt() # Arrival time of the process
        scheduler.addProcess(Process(pid, burstTime, arrivalTime))
    # Start the scheduling process
    scheduler.run()
    scanner.close() # Close the scanner

