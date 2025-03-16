

import sys

def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    # Initialize the need array
    need_array = [[0 for _ in range(total_resources)] for _ in range(total_process)]
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)

    # Array to keep track of finished processes
    finish_processes = [False for _ in range(total_process)]

    # Array to store the safe sequence
    safe_sequence_array = [0 for _ in range(total_process)]

    # Array to represent the available resources
    work_array = available_array[:]

    # Counter for the number of processes that have been processed
    count = 0

    # Loop until all processes are processed
    while count < total_process:
        found_safe_system = False
        for m in range(total_process):
            if not finish_processes[m]:
                j = 0
                while j < total_resources:
                    if need_array[m][j] > work_array[j]:
                        break
                    j += 1
                if j == total_resources:
                    for k in range(total_resources):
                        work_array[k] += allocation_array[m][k]
                    safe_sequence_array[count] = m
                    finish_processes[m] = True
                    found_safe_system = True
        if not found_safe_system:
            print("The system is not in a safe state due to insufficient resources.")
            return False
    print("The system is in a safe state. Safe sequence:", end=" ")
    for i in range(total_process):
        print("P" + str(safe_sequence_array[i]), end=" ")
    print()
    return True

# Main method to run the program
def main():
    total_processes, total_resources = map(int, input().split())

    # Array to store process IDs
    processes = [i for i in range(total_processes)]

    # Array to store the available resources
    available_array = list(map(int, input().split()))

    # Matrix to store the maximum resource requirements for each process
    max_array = [[0 for _ in range(total_resources)] for _ in range(total_processes)]
    for i in range(total_processes):
        max_array[i] = list(map(int, input().split()))

    # Matrix to store the current resource allocations for each process
    allocation_array = [[0 for _ in range(total_resources)] for _ in range(total_processes)]
    for i in range(total_processes):
        allocation_array[i] = list(map(int, input().split()))

    # Check if the system is in a safe state and print the result
    check_safe_system(processes, available_array, max_array, allocation_array, total_processes, total_resources)

if __name__ == "__main__":
    main()

