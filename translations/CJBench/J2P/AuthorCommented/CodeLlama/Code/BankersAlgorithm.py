
import sys

# This function calculates the need matrix for each process.
def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]

# This function checks if the system is in a safe state.
def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    need_array = [[0 for i in range(total_resources)] for j in range(total_process)]

    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)

    finish_processes = [False for i in range(total_process)]

    safe_sequence_array = [0 for i in range(total_process)]

    work_array = [0 for i in range(total_resources)]
    for i in range(total_resources):
        work_array[i] = available_array[i]

    count = 0

    # While all processes are not finished or system is not in a safe state.
    while count < total_process:
        found_safe_system = False
        for m in range(total_process):
            if not finish_processes[m]:
                j = 0

                for j in range(total_resources):
                    if need_array[m][j] > work_array[j]:
                        break

                if j == total_resources:
                    for k in range(total_resources):
                        work_array[k] += allocation_array[m][k]

                    safe_sequence_array[count] = m

                    finish_processes[m] = True

                    found_safe_system = True

        # If we could not find a next process in the safe sequence.
        if not found_safe_system:
            print("The system is not in a safe state due to insufficient resources.")
            return False

        count += 1

    print("The system is in a safe state. Safe sequence: ", end="")
    for i in range(total_process):
        print("P" + str(safe_sequence_array[i]) + " ", end="")
    print()

    return True

# Main method for executing the Banker's Algorithm.
if __name__ == "__main__":
    # Input number of processes and resources
    number_of_processes = int(input())
    number_of_resources = int(input())

    processes = [i for i in range(number_of_processes)]

    # Input availability of resources
    available_array = [int(i) for i in input().split()]

    # Input maximum resource matrix
    max_array = [[int(i) for i in input().split()] for j in range(number_of_processes)]

    # Input allocation matrix
    allocation_array = [[int(i) for i in input().split()] for j in range(number_of_processes)]

    # Check if the system is in a safe state.
    check_safe_system(processes, available_array, max_array, allocation_array, number_of_processes, number_of_resources)

