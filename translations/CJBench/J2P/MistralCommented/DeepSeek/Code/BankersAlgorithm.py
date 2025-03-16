def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    # Calculate the need matrix by subtracting the allocation matrix from the maximum matrix
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]
            # Update the need matrix element for the current process and resource

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    need_array = [[0] * total_resources for _ in range(total_process)]
    # Initialize the need matrix
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)
    finish_processes = [False] * total_process
    # Initialize the finish processes array with False values
    safe_sequence_array = [0] * total_process
    # Initialize the safe sequence array
    work_array = available_array.copy()
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
                    count += 1
                    finish_processes[m] = True
                    found_safe_system = True
                    # Update the finishProcesses array for the current process
        if not found_safe_system:
            # If no safe sequence is found, print the error message and return False
            print("The system is not in a safe state due to insufficient resources.")
            return False
    # If a safe sequence is found, print the safe sequence message and return True
    print("The system is in a safe state. Safe sequence: ", end="")
    for i in range(total_process):
        print(f"P{safe_sequence_array[i]}", end=" ")
    print()
    return True

# Main function to read input and call the checkSafeSystem method
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    # Read the number of processes
    number_of_processes = int(data[index])
    index += 1
    # Read the number of resources
    number_of_resources = int(data[index])
    index += 1
    # Initialize the processes array
    processes = [i for i in range(number_of_processes)]
    # Read the available resources
    available_array = [int(data[index]) for index in range(index, index + number_of_resources)]
    index += number_of_resources
    # Initialize the maximum resources array
    max_array = [[int(data[index]) for index in range(index, index + number_of_resources)] for _ in range(number_of_processes)]
    index += number_of_processes * number_of_resources
    # Initialize the allocation resources array
    allocation_array = [[int(data[index]) for index in range(index, index + number_of_resources)] for _ in range(number_of_processes)]
    index += number_of_processes * number_of_resources
    check_safe_system(processes, available_array, max_array, allocation_array, number_of_processes, number_of_resources)

if __name__ == "__main__":
    main()
