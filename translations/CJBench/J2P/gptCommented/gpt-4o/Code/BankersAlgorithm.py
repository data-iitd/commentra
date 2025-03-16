class Main:
    @staticmethod
    def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
        # Iterate through each process and resource to calculate the need
        for i in range(total_process):
            for j in range(total_resources):
                # Need is calculated as maximum demand minus current allocation
                need_array[i][j] = max_array[i][j] - allocation_array[i][j]

    @staticmethod
    def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
        # Create a need array to hold the remaining resource needs for each process
        need_array = [[0] * total_resources for _ in range(total_process)]
        # Calculate the need for each process
        Main.calculate_need(need_array, max_array, allocation_array, total_process, total_resources)

        # Array to track which processes have finished
        finish_processes = [False] * total_process
        # Array to store the safe sequence of processes
        safe_sequence_array = [0] * total_process
        # Work array to keep track of available resources
        work_array = available_array.copy()

        count = 0  # Count of processes that have finished
        # Loop until all processes are finished
        while count < total_process:
            found_safe_system = False  # Flag to check if a safe process was found
            # Check each process to see if it can finish
            for m in range(total_process):
                # If the process has not finished yet
                if not finish_processes[m]:
                    # Check if the process can be satisfied with the current work array
                    if all(need_array[m][j] <= work_array[j] for j in range(total_resources)):
                        # Simulate the allocation of resources to the process
                        for k in range(total_resources):
                            work_array[k] += allocation_array[m][k]
                        # Add the process to the safe sequence
                        safe_sequence_array[count] = m
                        count += 1
                        finish_processes[m] = True  # Mark process as finished
                        found_safe_system = True  # A safe process was found
            # If no process could be found to finish, the system is not in a safe state
            if not found_safe_system:
                print("The system is not in a safe state due to insufficient resources.")
                return False  # Return false indicating unsafe state

        # If the system is in a safe state, print the safe sequence
        print("The system is in a safe state. Safe sequence: ", end="")
        for i in range(total_process):
            print(f"P{safe_sequence_array[i]} ", end="")  # Print each process in the safe sequence
        print()  # New line after printing the safe sequence
        return True  # Return true indicating safe state

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().splitlines()
        
        # Read the number of processes and resources
        number_of_processes = int(data[0])
        number_of_resources = int(data[1])
        
        # Initialize the processes array
        processes = list(range(number_of_processes))
        
        # Initialize the available resources array
        available_array = list(map(int, data[2].split()))
        
        # Initialize the maximum resources array for each process
        max_array = [list(map(int, data[i + 3].split())) for i in range(number_of_processes)]
        
        # Initialize the allocation array for each process
        allocation_array = [list(map(int, data[i + 3 + number_of_processes].split())) for i in range(number_of_processes)]
        
        # Check if the system is in a safe state
        Main.check_safe_system(processes, available_array, max_array, allocation_array, number_of_processes, number_of_resources)

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
