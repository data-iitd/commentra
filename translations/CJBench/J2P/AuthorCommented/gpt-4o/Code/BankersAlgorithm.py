class BankersAlgorithm:
    def __init__(self):
        pass

    def calculate_need(self, need_array, max_array, allocation_array, total_process, total_resources):
        for i in range(total_process):
            for j in range(total_resources):
                need_array[i][j] = max_array[i][j] - allocation_array[i][j]

    def check_safe_system(self, processes, available_array, max_array, allocation_array, total_process, total_resources):
        need_array = [[0] * total_resources for _ in range(total_process)]
        self.calculate_need(need_array, max_array, allocation_array, total_process, total_resources)

        finish_processes = [False] * total_process
        safe_sequence_array = [0] * total_process
        work_array = available_array[:]
        count = 0

        while count < total_process:
            found_safe_system = False
            for m in range(total_process):
                if not finish_processes[m]:
                    for j in range(total_resources):
                        if need_array[m][j] > work_array[j]:
                            break
                    else:  # This else corresponds to the for loop
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

if __name__ == "__main__":
    import sys

    # Input number of processes and resources
    number_of_processes = int(input())
    number_of_resources = int(input())

    processes = list(range(number_of_processes))

    # Input availability of resources
    available_array = list(map(int, input().split()))

    # Input maximum resource matrix
    max_array = []
    for _ in range(number_of_processes):
        max_array.append(list(map(int, input().split())))

    # Input allocation matrix
    allocation_array = []
    for _ in range(number_of_processes):
        allocation_array.append(list(map(int, input().split())))

    # Check if the system is in a safe state.
    banker = BankersAlgorithm()
    banker.check_safe_system(processes, available_array, max_array, allocation_array, number_of_processes, number_of_resources)

# <END-OF-CODE>
