import sys

# Input the number of processes
num_processes = int(input())

# Input process details
processes = []
for i in range(num_processes):
    process_id, burst_time, deadline = input().split()
    processes.append((process_id, int(burst_time), int(deadline)))

# Schedule processes
executed_processes = schedule_processes(processes)

# Output results
for process in executed_processes:
    print(
        process[0] + " " +
        str(process[1]) + " " +
        str(process[2])
    )

def schedule_processes(processes):
    processes.sort(key=lambda x: x[2])

    current_time = 0
    executed_processes = []

    for process in processes:
        process[1] = current_time
        current_time += process[1]
        process[2] = process[1] + process[2]

        if current_time > process[2]:
            print("Warning: Process " + process[0] + " missed its deadline.")

        executed_processes.append(process)

    return executed_processes

