
import random

# Define a Process class with its properties and methods
class Process:
    def __init__(self, processId, burstTime, tickets):
        self.processId = processId
        self.burstTime = burstTime
        self.tickets = tickets
        self.waitingTime = 0
        self.turnAroundTime = 0

    # Getters for process properties
    def getProcessId(self):
        return self.processId

    def getBurstTime(self):
        return self.burstTime

    def getTickets(self):
        return self.tickets

    def getWaitingTime(self):
        return self.waitingTime

    # Setters for process properties
    def setWaitingTime(self, waitingTime):
        self.waitingTime = waitingTime

    def setTurnAroundTime(self, turnAroundTime):
        self.turnAroundTime = turnAroundTime

# Schedule processes using the Round-Robin Scheduling Algorithm
def scheduleProcesses(processes):
    totalTickets = sum(process.getTickets() for process in processes) # Calculate the total number of tickets
    currentTime = 0 # Initialize the current time to zero
    executedProcesses = [] # Initialize an empty list to store the executed processes

    while len(processes) > 0: # While there are still processes to be executed
        winningTicket = random.randint(1, totalTickets) # Generate a random number between 1 and the total number of tickets
        selectedProcess = selectProcessByTicket(processes, winningTicket) # Select the process with the corresponding ticket

        # Update the process properties
        selectedProcess.setWaitingTime(currentTime)
        currentTime += selectedProcess.getBurstTime()
        selectedProcess.setTurnAroundTime(selectedProcess.getWaitingTime() + selectedProcess.getBurstTime())
        executedProcesses.append(selectedProcess) # Add the executed process to the list
        processes.remove(selectedProcess) # Remove the executed process from the list

        totalTickets = sum(process.getTickets() for process in processes) # Update the total number of tickets
    return executedProcesses # Return the list of executed processes

# Helper method to select a process by its ticket number
def selectProcessByTicket(processes, winningTicket):
    ticketSum = 0 # Initialize a variable to keep track of the total number of tickets of the previous processes

    for process in processes: # Iterate through the list of processes
        ticketSum += process.getTickets() # Add the number of tickets of the current process to the total

        if ticketSum >= winningTicket: # If the total number of tickets is greater than or equal to the winning ticket number
            return process # Return the process with the corresponding tickets
    return None # If no process is found with the winning ticket number, return null

# Main method to read input and call the scheduling algorithm
def main():
    n = int(input()) # Read the number of processes
    processes = [] # Initialize an empty list to store the processes

    for i in range(n): # Iterate through the list of processes and read their properties
        processId = input()
        burstTime = int(input())
        tickets = int(input())
        processes.append(Process(processId, burstTime, tickets))

    scheduledProcesses = scheduleProcesses(processes) # Call the scheduling algorithm and store the result

    print("Process WaitingTime TurnAroundTime") # Print the header of the output table

    for process in scheduledProcesses: # Iterate through the list of executed processes and print their properties
        print(process.getProcessId() + " " + str(process.getWaitingTime()) + " " + str(process.getTurnAroundTime()))

if __name__ == "__main__":
    main()

# 