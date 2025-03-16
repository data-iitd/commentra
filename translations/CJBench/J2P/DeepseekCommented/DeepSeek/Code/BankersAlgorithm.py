def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    # Initialize the need array
    need_array = [[0] * total_resources for _ in range(total_process)]
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)

    # Array to keep track of finished processes
    finish_processes = [False] * total_process

    # Array to store the safe sequence
    safe_sequence_array = [0] * total_process

    # Array to represent the available resources
    work_array = available_array.copy()

    # Counter for the number of processes that have been processed
    count = 0

    # Loop until all processes are processed
    while count < total_process:
        found_safe_system = False
        for m in range(total_process):
            if not finish_processes[m]:
                for j in range(total_resources):
                    if need_array[m][j] > work_array[j]:
                        break
                if j == total_resources:
                    for k in range(total_resources):
                        work_array[k] += allocation_array[m][k]
                    safe_sequence_array[count] = m
                    count += 1
                    finish_processes[m] = True
                    found_safe_system = True
        if not found_safe_system:
            print("The system is not in a safe state due to insufficient resources.")
            return False
    print("The system is in a safe state. Safe sequence: ", end="")
    for i in range(total_process):
        print(f"P{safe_sequence_array[i]}", end=" ")
    print()
    return True

# Main method to run the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    number_of_processes = int(data[index])
    index += 1
    number_of_resources = int(data[index])
    index += 1

    # Array to store process IDs
    processes = [i for i in range(number_of_processes)]

    # Array to store the available resources
    available_array = [int(data[index]) for index in range(index, index + number_of_resources)]
    index += number_of_resources

    # Matrix to store the maximum resource requirements for each process
    max_array = [[int(data[index]) for index in range(index, index + number_of_resources)] for _ in range(number_of_processes)]
    index += number_of_processes * number_of_resources

    # Matrix to store the current resource allocations for each process
    allocation_array = [[int(data[index]) for index in range(index, index + number_of_resources)] for _ in range(number_of_processes)]
    index += number_of_processes * number_of_resources

    # Check if the system is in a safe state and print the result
    check_safe_system(processes, available_array, max_array, allocation_array, number_of_processes, number_of_resources)
