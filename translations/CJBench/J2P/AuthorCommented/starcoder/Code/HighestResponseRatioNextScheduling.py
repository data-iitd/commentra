import sys
import math

# Represents a process in the scheduling algorithm.
class Process:
    def __init__(self, name, arrivalTime, burstTime):
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.turnAroundTime = 0
        self.finished = False

    # Calculates the response ratio for this process.
    def calculateResponseRatio(self, currentTime):
        return (self.burstTime + currentTime - self.arrivalTime) / self.burstTime

# The Main class implements the
# Highest Response Ratio Next (HRRN) scheduling algorithm.
# HRRN is a non-preemptive scheduling algorithm that selects the process with
# the highest response ratio for execution.
# The response ratio is calculated as:
#
#     Response Ratio = (waiting time + burst time) / burst time
#
# HRRN is designed to reduce the average waiting time and improve overall
# system performance by balancing between short and long processes,
# minimizing process starvation.
class Main:
    # The process not found constant.
    PROCESS_NOT_FOUND = -1

    # The initial max response ratio constant.
    INITIAL_MAX_RESPONSE_RATIO = -1.0

    # The main method.
    @staticmethod
    def main(args):
        # Read input.
        noOfProcesses = int(input())
        processNames = []
        arrivalTimes = []
        burstTimes = []
        for i in range(noOfProcesses):
            processNames.append(input())
            arrivalTimes.append(int(input()))
            burstTimes.append(int(input()))

        # Calculate turn around time.
        turnAroundTimes = calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses)

        # Calculate waiting time.
        waitingTimes = calculateWaitingTime(turnAroundTimes, burstTimes)

        # Output results.
        print("Process WaitingTime TurnAroundTime")
        for i in range(noOfProcesses):
            print(processNames[i], waitingTimes[i], turnAroundTimes[i])

    # Calculates the Turn Around Time (TAT) for each process.
    #
    # Turn Around Time is calculated as the total time a process spends
    # in the system from arrival to completion. It is the sum of the burst time
    # and the waiting time.
    @staticmethod
    def calculateTurnAroundTime(processNames, arrivalTimes, burstTimes, noOfProcesses):
        currentTime = 0
        turnAroundTime = [0] * noOfProcesses
        processes = [Process(processNames[i], arrivalTimes[i], burstTimes[i]) for i in range(noOfProcesses)]

        # Sort processes by arrival time.
        processes.sort(key=lambda p: p.arrivalTime)

        # Keep track of the number of finished processes.
        finishedProcessCount = 0

        # While there are unfinished processes.
        while finishedProcessCount < noOfProcesses:
            # Find the next process to be scheduled.
            nextProcessIndex = findNextProcess(processes, currentTime)
            if nextProcessIndex == PROCESS_NOT_FOUND:
                # No process is ready.
                currentTime += 1
                continue

            # Get the current process.
            currentProcess = processes[nextProcessIndex]

            # Update the current time.
            currentTime = max(currentTime, currentProcess.arrivalTime)

            # Calculate the turn around time.
            currentProcess.turnAroundTime = currentTime + currentProcess.burstTime - currentProcess.arrivalTime

            # Update the current time.
            currentTime += currentProcess.burstTime

            # Mark the process as finished.
            currentProcess.finished = True

            # Increment the number of finished processes.
            finishedProcessCount += 1

        # Copy the turn around times to an array.
        for i in range(noOfProcesses):
            turnAroundTime[i] = processes[i].turnAroundTime

        return turnAroundTime

    # Calculates the Waiting Time (WT) for each process.
    @staticmethod
    def calculateWaitingTime(turnAroundTime, burstTimes):
        waitingTime = [0] * len(turnAroundTime)
        for i in range(len(turnAroundTime)):
            waitingTime[i] = turnAroundTime[i] - burstTimes[i]
        return waitingTime

    # Finds the next process to be scheduled based on arrival times and the current time.
    @staticmethod
    def findNextProcess(processes, currentTime):
        return findHighestResponseRatio(processes, currentTime)

    # Finds the process with the highest response ratio.
    #
    # The response ratio is calculated as:
    # (waiting time + burst time) / burst time
    # where waiting time = current time - arrival time
    @staticmethod
    def findHighestResponseRatio(processes, currentTime):
        maxResponseRatio = Main.INITIAL_MAX_RESPONSE_RATIO
        maxIndex = Main.PROCESS_NOT_FOUND

        for i in range(len(processes)):
            process = processes[i]
            if not process.finished and process.arrivalTime <= currentTime:
                responseRatio = process.calculateResponseRatio(currentTime)
                if responseRatio > maxResponseRatio:
                    maxResponseRatio = responseRatio
                    maxIndex = i

        return maxIndex

# 