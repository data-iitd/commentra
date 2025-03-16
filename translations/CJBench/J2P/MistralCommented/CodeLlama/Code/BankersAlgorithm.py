
import sys

def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    # Calculate the need matrix by subtracting the allocation matrix from the maximum matrix
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]
            # Update the need matrix element for the current process and resource

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    need_array = [[0 for i in range(total_resources)] for j in range(total_process)]
    # Initialize the need matrix
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)
    finish_processes = [False for i in range(total_process)]
    # Initialize the finish processes array with false values
    safe_sequence_array = [0 for i in range(total_process)]
    # Initialize the safe sequence array
    work_array = [0 for i in range(total_resources)]
    # Initialize the work array with the available resources
    for i in range(total_resources):
        work_array[i] = available_array[i]
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
        if not found_safe_system:
            # If no safe sequence is found, print the error message and return false
            print("The system is not in a safe state due to insufficient resources.")
            return False
        count += 1
    # If a safe sequence is found, print the safe sequence message and return true
    print("The system is in a safe state. Safe sequence: ", end="")
    for i in range(total_process):
        print("P" + str(safe_sequence_array[i]) + " ", end="")
    print()
    return True

if __name__ == "__main__":
    number_of_processes = int(sys.stdin.readline().strip())
    # Read the number of processes from the console
    number_of_resources = int(sys.stdin.readline().strip())
    # Read the number of resources from the console
    processes = [i for i in range(number_of_processes)]
    # Assign each process an index
    available_array = [int(i) for i in sys.stdin.readline().strip().split()]
    # Read the available resources for each resource from the console
    max_array = [[int(i) for i in sys.stdin.readline().strip().split()] for j in range(number_of_processes)]
    # Read the maximum resources for each process and resource from the console
    allocation_array = [[int(i) for i in sys.stdin.readline().strip().split()] for j in range(number_of_processes)]
    # Read the allocated resources for each process and resource from the console
    check_safe_system(processes, available_array, max_array, allocation_array, number_of_processes, number_of_resources)
    # Call the checkSafeSystem method with the given input parameters
    # 