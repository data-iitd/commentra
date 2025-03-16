
import sys

# Input number of processes
n = int(sys.stdin.readline())

# Input process details
processes = []
for i in range(n):
    processId, arrivalTime, burstTime = sys.stdin.readline().split()
    processes.append((processId, int(arrivalTime), int(burstTime)))

# Perform SJF scheduling
schedule = []
ready = []
time = 0
executed = 0
k = 0

if n == 0:
    pass

while executed < n:
    while k < n and processes[k][1] <= time:
        ready.append(processes[k])
        k += 1

    if len(ready) == 0:
        time += 1
    else:
        running = min(ready, key=lambda x: x[2])
        time += running[2]
        schedule.append(running[0])
        ready.remove(running)
        executed += 1

# Output the execution order
print("Execution Order:")
for processId in schedule:
    print(processId)

