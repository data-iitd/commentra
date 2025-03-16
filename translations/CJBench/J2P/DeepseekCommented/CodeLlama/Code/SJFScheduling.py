import sys
import math

class ProcessDetails:
    def __init__(self, processId, arrivalTime, burstTime):
        self.processId = processId
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime

class Main:
    def __init__(self, processes):
        self.processes = processes
        self.schedule = []
        self.sortProcessesByArrivalTime(self.processes)

    def sortProcessesByArrivalTime(self, processes):
        processes.sort(key=lambda p: p.arrivalTime)

    def scheduleProcesses(self):
        ready = []
        size = len(self.processes)
        time = 0
        executed = 0
        k = 0
        if size == 0:
            return
        while executed < size:
            while k < size and self.processes[k].arrivalTime <= time:
                ready.append(self.processes[k])
                k += 1
            running = self.findShortestJob(ready)
            if running is None:
                time += 1
            else:
                time += running.burstTime
                self.schedule.append(running.processId)
                ready.remove(running)
                executed += 1

    def findShortestJob(self, readyProcesses):
        if len(readyProcesses) == 0:
            return None
        return min(readyProcesses, key=lambda p: p.burstTime)

    def getSchedule(self):
        return self.schedule

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    processes = []
    for i in range(n):
        processId, arrivalTime, burstTime = sys.stdin.readline().strip().split()
        processes.append(ProcessDetails(processId, int(arrivalTime), int(burstTime)))
    main = Main(processes)
    main.scheduleProcesses()
    print("Execution Order:")
    for processId in main.getSchedule():
        print(processId)

