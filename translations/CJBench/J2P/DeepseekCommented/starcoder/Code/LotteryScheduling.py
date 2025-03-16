
import random

class Process:
    def __init__(self, processId, burstTime, tickets):
        self.processId = processId
        self.burstTime = burstTime
        self.tickets = tickets
        self.waitingTime = 0
        self.turnAroundTime = 0

    # Getter for process ID
    def getProcessId(self):
        return self.processId

    # Getter for burst time
    def getBurstTime(self):
        return self.burstTime

    # Getter for tickets
    def getTickets(self):
        return self.tickets

    # Getter for waiting time
    def getWaitingTime(self):
        return self.waitingTime

    # Setter for waiting time
    def setWaitingTime(self, waitingTime):
        self.waitingTime = waitingTime

    # Getter for turn-around time
    def getTurnAroundTime(self):
        return self.turnAroundTime

    # Setter for turn-around time
    def setTurnAroundTime(self, turnAroundTime):
        self.turnAroundTime = turnAroundTime

# Method to schedule processes using a lottery scheduling algorithm
def scheduleProcesses(processes):
    totalTickets = sum(process.getTickets() for process in processes)
    currentTime = 0
    executedProcesses = []

    # Continue scheduling processes until there are no processes left
    while len(processes) > 0:
        winningTicket = random.randint(1, totalTickets)
        selectedProcess = selectProcessByTicket(processes, winningTicket)
        selectedProcess.setWaitingTime(currentTime)
        currentTime += selectedProcess.getBurstTime()
        selectedProcess.setTurnAroundTime(selectedProcess.getWaitingTime() + selectedProcess.getBurstTime())
        executedProcesses.append(selectedProcess)
        processes.remove(selectedProcess)
        totalTickets = sum(process.getTickets() for process in processes)
    return executedProcesses

# Helper method to select a process based on the winning ticket
def selectProcessByTicket(processes, winningTicket):
    ticketSum = 0
    for process in processes:
        ticketSum += process.getTickets()
        if ticketSum >= winningTicket:
            return process
    return None

# Main method to read process details, schedule them, and print their waiting and turn-around times
def main():
    n = int(input())
    processes = []

    # Read process details from the user
    for i in range(n):
        processId = input()
        burstTime = int(input())
        tickets = int(input())
        processes.append(Process(processId, burstTime, tickets))

    # Schedule the processes and print their details
    scheduledProcesses = scheduleProcesses(processes)
    print("Process WaitingTime TurnAroundTime")
    for process in scheduledProcesses:
        print(process.getProcessId() + " " + process.getWaitingTime() + " " + process.getTurnAroundTime())

if __name__ == "__main__":
    main()

