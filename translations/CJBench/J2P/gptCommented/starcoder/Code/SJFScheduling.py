import sys

# Class to hold the details of each process
class ProcessDetails:
    def __init__(self, processId, arrivalTime, burstTime):
        self.processId = processId
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime

    # Getter for process ID
    def getProcessId(self):
        return self.processId

    # Getter for arrival time
    def getArrivalTime(self):
        return self.arrivalTime

    # Getter for burst time
    def getBurstTime(self):
        return self.burstTime


# Class to schedule processes using Shortest Job First (SJF) algorithm
class Main:
    # List to hold the process details
    processes = []
    # List to hold the scheduled order of process execution
    schedule = []

    # Constructor to initialize the process list and sort them by arrival time
    def __init__(self, processes):
        self.processes = processes
        self.schedule = []
        self.sortProcessesByArrivalTime(self.processes)

    # Method to sort processes based on their arrival time
    def sortProcessesByArrivalTime(self, processes):
        processes.sort(key=lambda p: p.getArrivalTime())

    # Method to schedule processes using Shortest Job First (SJF) algorithm
    def scheduleProcesses(self):
        ready = [] # List of processes that are ready to execute
        size = len(self.processes) # Total number of processes
        time = 0 # Current time in the scheduling
        executed = 0 # Count of executed processes
        k = 0 # Index for traversing the processes

        # If there are no processes, exit the method
        if size == 0:
            return

        # Loop until all processes are executed
        while executed < size:
            # Add processes that have arrived by the current time to the ready list
            while k < size and self.processes[k].getArrivalTime() <= time:
                ready.append(self.processes[k])
                k += 1

            # Find the shortest job from the ready processes
            running = self.findShortestJob(ready)
            if running == None:
                # If no process is ready, increment time
                time += 1
            else:
                # Execute the shortest job
                time += running.getBurstTime() # Increment time by the burst time of the running process
                self.schedule.append(running.getProcessId()) # Add the process ID to the schedule
                ready.remove(running) # Remove the running process from the ready list
                executed += 1 # Increment the count of executed processes

    # Method to find the process with the shortest burst time from the ready list
    def findShortestJob(self, readyProcesses):
        if len(readyProcesses) == 0:
            return None # Return null if there are no ready processes
        # Return the process with the minimum burst time
        return min(readyProcesses, key=lambda p: p.getBurstTime())

    # Method to get the scheduled order of processes
    def getSchedule(self):
        return self.schedule


# Main method to execute the program
def main():
    # Read the number of processes
    n = int(input())
    processes = []

    # Read process details from input
    for i in range(n):
        processId = input()
        arrivalTime = int(input())
        burstTime = int(input())
        processes.append(ProcessDetails(processId, arrivalTime, burstTime))

    # Create an instance of Main with the list of processes
    sjfScheduling = Main(processes)
    # Schedule the processes
    sjfScheduling.scheduleProcesses()

    # Print the execution order of processes
    print("Execution Order:")
    for processId in sjfScheduling.getSchedule():
        print(processId)


if __name__ == "__main__":
    main()

# 