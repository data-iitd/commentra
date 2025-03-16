

import sys

def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    # Calculate the need matrix by subtracting the allocation matrix from the maximum matrix
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]
            # Update the need matrix element for the current process and resource

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    need_array = [[0 for _ in range(total_resources)] for _ in range(total_process)]
    # Initialize the need matrix
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)
    finish_processes = [False for _ in range(total_process)]
    # Initialize the finish processes array with false values
    safe_sequence_array = [0 for _ in range(total_process)]
    # Initialize the safe sequence array
    work_array = available_array[:]
    # Initialize the work array with the available resources
    count = 0
    # Initialize the safe sequence counter
    while count < total_process:
        found_safe_system = False
        # Initialize the foundSafeSystem flag
        for m in range(total_process):
            if not finish_processes[m]:
                j = 0
                # Initialize the j index
                while j < total_resources:
                    if need_array[m][j] > work_array[j]:
                        # If the current process needs more resources than available, break the inner loop
                        break
                    j += 1
                if j == total_resources:
                    # If the current process can be executed safely, update the work array and safe sequence array
                    for k in range(total_resources):
                        work_array[k] += allocation_array[m][k]
                    safe_sequence_array[count] = m
                    finish_processes[m] = True
                    found_safe_system = True
                    # Update the finishProcesses array for the current process
                    count += 1
        if not found_safe_system:
            # If no safe sequence is found, print the error message and return false
            print("The system is not in a safe state due to insufficient resources.")
            return False
    # If a safe sequence is found, print the safe sequence message and return true
    print("The system is in a safe state. Safe sequence:", end=" ")
    for i in range(total_process):
        print("P" + str(safe_sequence_array[i]), end=" ")
    print()
    return True

if __name__ == "__main__":
    # Read input from the console
    total_processes = int(input("Enter the number of processes: "))
    total_resources = int(input("Enter the number of resources: "))
    processes = list(range(total_processes))
    # Assign each process an index
    available_array = list(map(int, input("Enter the available resources for each resource (space separated): ").split()))
    max_array = [[0 for _ in range(total_resources)] for _ in range(total_processes)]
    # Initialize the maximum resources array
    for i in range(total_processes):
        max_array[i] = list(map(int, input("Enter the maximum resources for process P" + str(i) + " (space separated): ").split()))
    allocation_array = [[0 for _ in range(total_resources)] for _ in range(total_processes)]
    # Initialize the allocation resources array
    for i in range(total_processes):
        allocation_array[i] = list(map(int, input("Enter the allocated resources for process P" + str(i) + " (space separated): ").split()))
    check_safe_system(processes, available_array, max_array, allocation_array, total_processes, total_resources)
    # Call the checkSafeSystem method with the given input parameters

