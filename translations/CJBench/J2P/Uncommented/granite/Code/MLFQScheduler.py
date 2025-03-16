
import queue
class Process:
    def __init__(self, pid, burstTime, arrivalTime):
        self.pid = pid
        self.burstTime = burstTime
        self.remainingTime = burstTime
        self.arrivalTime = arrivalTime
        self.priority = 0
    def execute(self, timeSlice):
        self.remainingTime -= timeSlice
        if self.remainingTime < 0:
            self.remainingTime = 0
    def isFinished(self):
        return self.remainingTime == 0
class Main:
    def __init__(self, levels, timeQuantums):
        self.queues = [queue.Queue() for _ in range(levels)]
        self.timeQuantum = timeQuantums
        self.currentTime = 0
    def addProcess(self, p):
        self.queues[0].put(p)
    def run(self):
        while not self.allQueuesEmpty():
            for i in range(len(self.queues)):
                queue = self.queues[i]
                if not queue.empty():
                    p = queue.get()
                    quantum = self.timeQuantum[i]
                    timeSlice = min(quantum, p.remainingTime)
                    p.execute(timeSlice)
                    self.currentTime += timeSlice
                    if p.isFinished():
                        print(f"Process {p.pid} finished at time {self.currentTime}")
                    else:
                        if i < len(self.queues) - 1:
                            p.priority += 1
                            self.queues[i + 1].put(p)
                        else:
                            queue.put(p)
    def allQueuesEmpty(self):
        for queue in self.queues:
            if not queue.empty():
                return False
        return True
if __name__ == "__main__":
    import sys
    scanner = iter(sys.stdin.read().splitlines())
    levels = int(next(scanner))
    timeQuantums = [int(x) for x in next(scanner).split()]
    main = Main(levels, timeQuantums)
    n = int(next(scanner))
    for _ in range(n):
        pid, burstTime, arrivalTime = map(int, next(scanner).split())
        main.addProcess(Process(pid, burstTime, arrivalTime))
    main.run()
