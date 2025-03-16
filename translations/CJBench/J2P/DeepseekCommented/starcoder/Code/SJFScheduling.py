import sys
import heapq
class Main:
    def __init__(self, processes):
        self.processes = processes
        self.schedule = []
        self.sortProcessesByArrivalTime(self.processes)
    def sortProcessesByArrivalTime(self, processes):
        processes.sort(key=lambda p: p.getArrivalTime())
    def scheduleProcesses(self):
        ready = []
        size = len(self.processes)
        time = 0
        executed = 0
        k = 0
        if size == 0:
            return
        while executed < size:
            while k < size and self.processes[k].getArrivalTime() <= time:
                heapq.heappush(ready, self.processes[k])
                k += 1
            running = self.findShortestJob(ready)
            if running == None:
                time += 1
            else:
                time += running.getBurstTime()
                self.schedule.append(running.getProcessId())
                ready.remove(running)
                executed += 1
    def findShortestJob(self, readyProcesses):
        if len(readyProcesses) == 0:
            return None
        return min(readyProcesses, key=lambda p: p.getBurstTime())
    def getSchedule(self):
        return self.schedule
class ProcessDetails:
    def __init__(self, processId, arrivalTime, burstTime):
        self.processId = processId
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
    def getProcessId(self):
        return self.processId
    def getArrivalTime(self):
        return self.arrivalTime
    def getBurstTime(self):
        return self.burstTime
if __name__ == "__main__":
    processes = []
    n = int(sys.stdin.readline())
    for i in range(n):
        processId = sys.stdin.readline().strip()
        arrivalTime = int(sys.stdin.readline())
        burstTime = int(sys.stdin.readline())
        processes.append(ProcessDetails(processId, arrivalTime, burstTime))
    sjfScheduling = Main(processes)
    sjfScheduling.scheduleProcesses()
    print("Execution Order:")
    for processId in sjfScheduling.getSchedule():
        print(processId)
