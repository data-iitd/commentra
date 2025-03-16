
import sys

def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    need_array = [[0 for i in range(total_resources)] for j in range(total_process)]
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)
    finish_processes = [False for i in range(total_process)]
    safe_sequence_array = [0 for i in range(total_process)]
    work_array = [0 for i in range(total_resources)]
    for i in range(total_resources):
        work_array[i] = available_array[i]
    count = 0
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
        if not found_safe_system:
            print("The system is not in a safe state due to insufficient resources.")
            return False
        count += 1
    print("The system is in a safe state. Safe sequence: ")
    for i in range(total_process):
        print("P" + str(safe_sequence_array[i]) + " ", end="")
    print()
    return True

if __name__ == "__main__":
    number_of_processes = int(sys.stdin.readline().strip())
    number_of_resources = int(sys.stdin.readline().strip())
    processes = [i for i in range(number_of_processes)]
    available_array = [int(i) for i in sys.stdin.readline().strip().split()]
    max_array = [[0 for i in range(number_of_resources)] for j in range(number_of_processes)]
    for i in range(number_of_processes):
        max_array[i] = [int(i) for i in sys.stdin.readline().strip().split()]
    allocation_array = [[0 for i in range(number_of_resources)] for j in range(number_of_processes)]
    for i in range(number_of_processes):
        allocation_array[i] = [int(i) for i in sys.stdin.readline().strip().split()]
    check_safe_system(processes, available_array, max_array, allocation_array, number_of_processes, number_of_resources)
    # 