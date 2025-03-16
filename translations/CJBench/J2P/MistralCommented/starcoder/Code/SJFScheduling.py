
import sys

class Main:
    # Initialize instance variables
    def __init__(self, processes):
        self.processes = processes # Assign input processes to the instance variable
        self.schedule = [] # Initialize an empty list to store the execution order
        self.sortProcessesByArrivalTime(self.processes) # Sort the processes based on their arrival time

    # Static method to sort the processes based on their arrival time
    def sortProcessesByArrivalTime(self, processes):
        processes.sort(key=lambda p: p.getArrivalTime()) # Use sorted() method with a custom key function

    # Method to schedule the processes based on Shortest Job First (SJF) algorithm
    def scheduleProcesses(self):
        ready = [] # Initialize an empty list to store the ready processes
        size = len(self.processes) # Get the number of processes
        time = 0 # Initialize the current time to zero
        executed = 0 # Initialize the number of executed processes to zero
        k = 0 # Initialize an index variable to traverse the processes list

        if size == 0: # Check if there are any processes to schedule
            return

        while executed < size: # Iterate while all processes are not executed
            while k < size and self.processes[k].getArrivalTime() <= time: # Iterate while there are ready processes or processes that have arrived
                ready.append(self.processes[k]) # Add the process to the ready list
                k += 1 # Increment the index
            running = self.findShortestJob(ready) # Find the process with the shortest burst time from the ready list
            if running == None: # If the ready list is empty, increment the time and continue the loop
                time += 1
            else: # Else, execute the shortest process and update the schedule and ready list
                time += running.getBurstTime()
                self.schedule.append(running.getProcessId())
                ready.remove(running)
                executed += 1

    # Method to find the process with the shortest burst time from the ready list
    def findShortestJob(self, readyProcesses):
        if len(readyProcesses) == 0: # If the ready list is empty, return None
            return None
        return min(readyProcesses, key=lambda p: p.getBurstTime()) # Use min() method with a custom key function to find the process with the shortest burst time

    # Method to get the execution order of the processes
    def getSchedule(self):
        return self.schedule # Return the execution order list

class ProcessDetails:
    # Initialize instance variables and constructor
    def __init__(self, processId, arrivalTime, burstTime):
        self.processId = processId
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime

    # Getter methods for the instance variables
    def getProcessId(self):
        return self.processId

    def getArrivalTime(self):
        return self.arrivalTime

    def getBurstTime(self):
        return self.burstTime

if __name__ == "__main__":
    processes = [] # Initialize an empty list to store the processes
    n = int(input()) # Read the number of processes
    for i in range(n): # Iterate through each process and add it to the processes list
        processId = input()
        arrivalTime = int(input())
        burstTime = int(input())
        processes.append(ProcessDetails(processId, arrivalTime, burstTime))
    sjfScheduling = Main(processes) # Create an instance of the Main class and pass the processes list as an argument to the constructor
    sjfScheduling.scheduleProcesses() # Call the scheduleProcesses() method to schedule the processes
    print("Execution Order:") # Print the execution order header
    for processId in sjfScheduling.getSchedule(): # Iterate through the execution order list and print each process ID
        print(processId)

