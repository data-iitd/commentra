import random

class Process:
    def __init__(self, processId, burstTime, tickets):
        self.processId = processId
        self.burstTime = burstTime
        self.tickets = tickets
        self.waitingTime = 0
        self.turnAroundTime = 0

def scheduleProcesses(processes):
    totalTickets = sum(process.tickets for process in processes)
    currentTime = 0
    executedProcesses = []

    while len(processes) > 0:
        winningTicket = random.randint(1, totalTickets)
        selectedProcess = selectProcessByTicket(processes, winningTicket)

        selectedProcess.waitingTime = currentTime
        currentTime += selectedProcess.burstTime
        selectedProcess.turnAroundTime = selectedProcess.waitingTime + selectedProcess.burstTime

        executedProcesses.append(selectedProcess)
        processes.remove(selectedProcess)

        totalTickets = sum(process.tickets for process in processes)

    return executedProcesses

def selectProcessByTicket(processes, winningTicket):
    ticketSum = 0
    for process in processes:
        ticketSum += process.tickets
        if ticketSum >= winningTicket:
            return process
    return None

if __name__ == "__main__":
    n = int(input())
    processes = []

    for i in range(n):
        processId, burstTime, tickets = input().split()
        processes.append(Process(processId, int(burstTime), int(tickets)))

    scheduledProcesses = scheduleProcesses(processes)

    print("Process WaitingTime TurnAroundTime")
    for process in scheduledProcesses:
        print(process.processId, process.waitingTime, process.turnAroundTime)

