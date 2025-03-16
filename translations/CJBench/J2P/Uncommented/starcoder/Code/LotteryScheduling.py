import random
class Process:
    def __init__(self, processId, burstTime, tickets):
        self.processId = processId
        self.burstTime = burstTime
        self.tickets = tickets
        self.waitingTime = 0
        self.turnAroundTime = 0
    def getProcessId(self):
        return self.processId
    def getBurstTime(self):
        return self.burstTime
    def getTickets(self):
        return self.tickets
    def getWaitingTime(self):
        return self.waitingTime
    def setWaitingTime(self, waitingTime):
        self.waitingTime = waitingTime
    def getTurnAroundTime(self):
        return self.turnAroundTime
    def setTurnAroundTime(self, turnAroundTime):
        self.turnAroundTime = turnAroundTime
def scheduleProcesses(processes):
    totalTickets = sum(process.getTickets() for process in processes)
    currentTime = 0
    executedProcesses = []
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
def selectProcessByTicket(processes, winningTicket):
    ticketSum = 0
    for process in processes:
        ticketSum += process.getTickets()
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
        print(process.getProcessId(), process.getWaitingTime(), process.getTurnAroundTime())
