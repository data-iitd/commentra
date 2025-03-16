import random

# Class representing a process with its attributes
class Process:
    def __init__(self, processId, burstTime, tickets):
        self.processId = processId
        self.burstTime = burstTime
        self.tickets = tickets
        self.waitingTime = 0
        self.turnAroundTime = 0

# Method to schedule processes based on a lottery system
def scheduleProcesses(processes):
    totalTickets = sum([process.tickets for process in processes]) # Calculate total tickets
    currentTime = 0 # Initialize current time
    executedProcesses = [] # List to store executed processes

    # Continue scheduling until all processes are executed
    while len(processes) > 0:
        # Select a winning ticket randomly
        winningTicket = random.randint(1, totalTickets)
        # Select the process corresponding to the winning ticket
        selectedProcess = selectProcessByTicket(processes, winningTicket)
        # Set the waiting time for the selected process
        selectedProcess.waitingTime = currentTime
        # Update current time by adding the burst time of the selected process
        currentTime += selectedProcess.burstTime
        # Calculate turn around time for the selected process
        selectedProcess.turnAroundTime = selectedProcess.waitingTime + selectedProcess.burstTime
        # Add the executed process to the list
        executedProcesses.append(selectedProcess)
        # Remove the executed process from the original list
        processes.remove(selectedProcess)
        # Recalculate total tickets after removing the executed process
        totalTickets = sum([process.tickets for process in processes])
    return executedProcesses # Return the list of executed processes

# Method to select a process based on the winning ticket
def selectProcessByTicket(processes, winningTicket):
    ticketSum = 0 # Initialize sum of tickets
    # Iterate through the processes to find the one corresponding to the winning ticket
    for process in processes:
        ticketSum += process.tickets # Accumulate ticket sum
        if ticketSum >= winningTicket: # Check if the winning ticket falls within the current sum
            return process # Return the selected process
    return None # Return None if no process is found (should not happen)

# Main method to execute the program
def main():
    n = int(input()) # Read the number of processes
    processes = [] # List to store all processes

    # Loop to read process details from user input
    for i in range(n):
        processId = input() # Read process ID
        burstTime = int(input()) # Read burst time
        tickets = int(input()) # Read number of tickets
        # Create a new process and add it to the list
        processes.append(Process(processId, burstTime, tickets))

    # Schedule the processes and get the executed order
    scheduledProcesses = scheduleProcesses(processes)
    # Print the results: Process ID, Waiting Time, and Turn Around Time
    print("Process WaitingTime TurnAroundTime")
    for process in scheduledProcesses:
        print(process.processId, process.waitingTime, process.turnAroundTime)

if __name__ == "__main__":
    main()

