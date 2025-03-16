
import sys

class Main:
    # Initialize an empty list to store queues for each level
    queues = []
    
    # Initialize an array to store time quantum for each level
    timeQuantum = []
    
    # Initialize current time to zero
    currentTime = 0
    
    # Constructor to initialize the number of levels and time quanta for each level
    def __init__(self, levels, timeQuantums):
        for i in range(levels):
            self.queues.append([]) # Add an empty queue for each level
        self.timeQuantum = timeQuantums
    
    # Method to add a process to the first queue
    def addProcess(self, p):
        self.queues[0].append(p)
    
    # Method to run the scheduler
    def run(self):
        # Loop until all queues are empty
        while not self.allQueuesEmpty():
            for i in range(len(self.queues)):
                queue = self.queues[i] # Get the queue for the current level
                if len(queue) > 0: # If the queue is not empty
                    p = queue.pop(0) # Dequeue the process
                    quantum = self.timeQuantum[i] # Get the time quantum for the current level
                    timeSlice = min(quantum, p.remainingTime) # Calculate the time slice
                    p.execute(timeSlice) # Execute the process for the calculated time slice
                    self.currentTime += timeSlice # Increment the current time
                    
                    # Check if the process is finished
                    if p.isFinished():
                        print("Process " + str(p.pid) + " finished at time " + str(self.currentTime))
                    else:
                        # If there is a next level, increment the priority and add the process to the next queue
                        if i < len(self.queues) - 1:
                            p.priority += 1
                            self.queues[i + 1].append(p)
                        else: # Otherwise, add the process back to the current queue
                            queue.append(p)
    
    # Method to check if all queues are empty
    def allQueuesEmpty(self):
        for queue in self.queues:
            if len(queue) > 0:
                return False
        return True

class Process:
    pid = 0 # Process ID
    burstTime = 0 # Burst time of the process
    remainingTime = 0 # Remaining time of the process
    arrivalTime = 0 # Arrival time of the process
    priority = 0 # Priority of the process
    
    # Constructor to initialize a process with the given details
    def __init__(self, pid, burstTime, arrivalTime):
        self.pid = pid
        self.burstTime = burstTime
        self.remainingTime = burstTime
        self.arrivalTime = arrivalTime
    
    # Method to execute the process for a given time slice
    def execute(self, timeSlice):
        self.remainingTime -= timeSlice # Decrement the remaining time by the given time slice
        if self.remainingTime < 0:
            self.remainingTime = 0 # Set the remaining time to zero if it becomes negative
    
    # Method to check if the process is finished
    def isFinished(self):
        return self.remainingTime == 0

if __name__ == "__main__":
    # Read the number of levels and time quanta for each level
    levels = int(sys.stdin.readline().strip())
    timeQuantums = [int(x) for x in sys.stdin.readline().strip().split()]
    
    # Create a scheduler instance with the given levels and time quanta
    scheduler = Main(levels, timeQuantums)
    
    # Read the number of processes and their details
    n = int(sys.stdin.readline().strip())
    for i in range(n):
        pid, burstTime, arrivalTime = [int(x) for x in sys.stdin.readline().strip().split()]
        scheduler.addProcess(Process(pid, burstTime, arrivalTime))
    
    # Start the scheduler
    scheduler.run()

