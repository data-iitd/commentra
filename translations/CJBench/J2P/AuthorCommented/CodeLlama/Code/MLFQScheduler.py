
import sys

# Input number of queues and their time quantums
levels = int(sys.stdin.readline())
timeQuantums = list(map(int, sys.stdin.readline().split()))

# Initialize the MLFQ scheduler
scheduler = []
for i in range(levels):
    scheduler.append([])

# Input number of processes
n = int(sys.stdin.readline())
for i in range(n):
    pid, burstTime, arrivalTime = map(int, sys.stdin.readline().split())
    scheduler[0].append([pid, burstTime, arrivalTime])

# Execute the scheduling process
currentTime = 0
while True:
    for i in range(levels):
        if len(scheduler[i]) > 0:
            p = scheduler[i].pop(0)
            quantum = timeQuantums[i]
            timeSlice = min(quantum, p[1])
            p[1] -= timeSlice
            currentTime += timeSlice

            if p[1] == 0:
                print("Process " + str(p[0]) + " finished at time " + str(currentTime))
            else:
                if i < levels - 1:
                    p[2] += 1
                    scheduler[i + 1].append(p)
                else:
                    scheduler[i].append(p)

    if allQueuesEmpty(scheduler):
        break

# Helper function to check if all the queues are empty (i.e., no process is left to execute)
def allQueuesEmpty(scheduler):
    for i in range(len(scheduler)):
        if len(scheduler[i]) > 0:
            return False
    return True

