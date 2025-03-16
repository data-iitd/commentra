import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
class Main:
    def __init__(self, levels, timeQuantums):
        self.queues = []
        for i in range(levels):
            self.queues.append(LinkedList())
        self.timeQuantum = timeQuantums
        self.currentTime = 0
    def addProcess(self, p):
        self.queues[0].add(p)
    def run(self):
        while not self.allQueuesEmpty():
            for i in range(len(self.queues)):
                queue = self.queues[i]
                if not queue.isEmpty():
                    p = queue.poll()
                    quantum = self.timeQuantum[i]
                    timeSlice = min(quantum, p.remainingTime)
                    p.execute(timeSlice)
                    self.currentTime += timeSlice
                    if p.isFinished():
                        print("Process " + str(p.pid) + " finished at time " + str(self.currentTime))
                    else:
                        if i < len(self.queues) - 1:
                            p.priority += 1
                            self.queues[i + 1].add(p)
                        else:
                            queue.add(p)
    def allQueuesEmpty(self):
        for queue in self.queues:
            if not queue.isEmpty():
                return False
        return True
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
if __name__ == "__main__":
    scanner = Scanner(System.in)
    levels = scanner.nextInt()
    timeQuantums = []
    for i in range(levels):
        timeQuantums.append(scanner.nextInt())
    scheduler = Main(levels, timeQuantums)
    n = scanner.nextInt()
    for i in range(n):
        pid = scanner.nextInt()
        burstTime = scanner.nextInt()
        arrivalTime = scanner.nextInt()
        scheduler.addProcess(Process(pid, burstTime, arrivalTime))
    scheduler.run()
    scanner.close()
