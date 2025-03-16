import sys

def main():
    numProcesses = int(sys.stdin.readline())
    processes = []
    for i in range(numProcesses):
        processId, burstTime, deadline = sys.stdin.readline().split()
        processes.append(Process(processId, int(burstTime), int(deadline)))
    executedProcesses = scheduleProcesses(processes)
    for process in executedProcesses:
        print(
            process.processId + " " +
            process.waitingTime + " " +
            process.turnAroundTime
        )

def scheduleProcesses(processes):
    processes.sort(key=lambda x: x.deadline)
    currentTime = 0
    executedProcesses = []
    for process in processes:
        process.waitingTime = currentTime
        currentTime += process.burstTime
        process.turnAroundTime = process.waitingTime + process.burstTime
        if currentTime > process.deadline:
            print("Warning: Process " + process.processId + " missed its deadline.")
        executedProcesses.append(process)
    return executedProcesses

class Process:
    def __init__(self, processId, burstTime, deadline):
        self.processId = processId
        self.burstTime = burstTime
        self.deadline = deadline
        self.waitingTime = 0
        self.turnAroundTime = 0

if __name__ == "__main__":
    main()

