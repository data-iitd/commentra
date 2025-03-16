def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    for i in range(total_process):
        for j in range(total_resources):
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    need_array = [[0] * total_resources for _ in range(total_process)]
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)

    finish_processes = [False] * total_process
    safe_sequence_array = [0] * total_process
    work_array = available_array.copy()

    count = 0

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
                    count += 1
                    finish_processes[m] = True
                    found_safe_system = True

        if not found_safe_system:
            print("The system is not in a safe state due to insufficient resources.")
            return False

    print("The system is in a safe state. Safe sequence: ", end="")
    for i in range(total_process):
        print(f"P{safe_sequence_array[i]} ", end="")
    print()

    return True

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    numberOfProcesses = int(data[index])
    index += 1
    numberOfResources = int(data[index])
    index += 1

    processes = [i for i in range(numberOfProcesses)]

    availableArray = [int(data[index]) for index in range(index, index + numberOfResources)]
    index += numberOfResources

    maxArray = [[int(data[index]) for index in range(index, index + numberOfResources)] for _ in range(numberOfProcesses)]
    index += numberOfProcesses * numberOfResources

    allocationArray = [[int(data[index]) for index in range(index, index + numberOfResources)] for _ in range(numberOfProcesses)]
    index += numberOfProcesses * numberOfResources

    check_safe_system(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources)

if __name__ == "__main__":
    main()
