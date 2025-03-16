
import sys

# List of queues to hold processes at different priority levels
queues = []
# Array to hold time quantums for each priority level
timeQuantum = []
# Variable to track the current time in the scheduling process
currentTime = 0

# Constructor to initialize the scheduler with the number of levels and their respective time quantums
def __init__(self, levels, timeQuantums):
    global queues, timeQuantum, currentTime
    queues = []
    # Initialize each queue for the different priority levels
    for i in range(levels):
        queues.append(Queue())
    timeQuantum = timeQuantums
    currentTime = 0 # Start time at 0

# Method to add a new process to the highest priority queue (queue 0)
def addProcess(self, p):
    queues[0].put(p)

# Method to run the scheduling algorithm
def run(self):
    # Continue running until all queues are empty
    while not allQueuesEmpty():
        # Iterate through each priority level's queue
        for i in range(len(queues)):
            queue = queues[i]
            # If the current queue is not empty, process the next process
            if not queue.empty():
                p = queue.get() # Get the next process from the queue
                quantum = timeQuantum[i] # Get the time quantum for the current level
                timeSlice = min(quantum, p.remainingTime) # Determine the time slice to execute

                # Execute the process for the determined time slice
                p.execute(timeSlice)
                currentTime += timeSlice # Update the current time

                # Check if the process has finished executing
                if p.isFinished():
                    print("Process " + str(p.pid) + " finished at time " + str(currentTime))
                else:
                    # If not finished and not at the last queue, increase priority and move to the next queue
                    if i < len(queues) - 1:
                        p.priority += 1
                        queues[i + 1].put(p) # Add to the next priority queue
                    else:
                        queue.put(p) # If at the last queue, re-add to the same queue

# Helper method to check if all queues are empty
def allQueuesEmpty(self):
    for queue in queues:
        if not queue.empty():
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

# Main method to run the scheduler
def main():
    # Read the number of priority levels
    levels = int(sys.stdin.readline())
    timeQuantums = []
    # Read the time quantums for each level
    for i in range(levels):
        timeQuantums.append(int(sys.stdin.readline()))
    # Initialize the scheduler with levels and time quantums
    scheduler = Main(levels, timeQuantums)
    # Read the number of processes to schedule
    n = int(sys.stdin.readline())
    # Read each process's details and add to the scheduler
    for i in range(n):
        pid = int(sys.stdin.readline()) # Process ID
        burstTime = int(sys.stdin.readline()) # Burst time of the process
        arrivalTime = int(sys.stdin.readline()) # Arrival time of the process
        scheduler.addProcess(Process(pid, burstTime, arrivalTime))
    # Start the scheduling process
    scheduler.run()

# Main method to run the scheduler
if __name__ == "__main__":
    main()

