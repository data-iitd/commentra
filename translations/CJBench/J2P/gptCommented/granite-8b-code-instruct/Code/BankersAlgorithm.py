
import sys

def calculate_need(need_array, max_array, allocation_array, total_process, total_resources):
    # Iterate through each process and resource to calculate the need
    for i in range(total_process):
        for j in range(total_resources):
            # Need is calculated as maximum demand minus current allocation
            need_array[i][j] = max_array[i][j] - allocation_array[i][j]

def check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources):
    # Create a need array to hold the remaining resource needs for each process
    need_array = [[0 for _ in range(total_resources)] for _ in range(total_process)]
    # Calculate the need for each process
    calculate_need(need_array, max_array, allocation_array, total_process, total_resources)
    
    # Array to track which processes have finished
    finish_processes = [False] * total_process
    # Array to store the safe sequence of processes
    safe_sequence_array = [0] * total_process
    # Work array to keep track of available resources
    work_array = available_array[:]
    # Loop until all processes are finished
    count = 0
    while count < total_process:
        found_safe_system = False # Flag to check if a safe process was found
        # Check each process to see if it can finish
        for m in range(total_process):
            if not finish_processes[m]:
                j = 0
                # Check if the process can be satisfied with the current work array
                while j < total_resources and need_array[m][j] <= work_array[j]:
                    j += 1
                # If all resource needs are satisfied
                if j == total_resources:
                    # Simulate the allocation of resources to the process
                    for k in range(total_resources):
                        work_array[k] += allocation_array[m][k]
                    # Add the process to the safe sequence
                    safe_sequence_array[count] = m
                    finish_processes[m] = True # Mark process as finished
                    found_safe_system = True # A safe process was found
                else:
                    j = 0
                    # Check if the process can be satisfied with the current work array
                    while j < total_resources and need_array[m][j] <= work_array[j]:
                        j += 1
                    # If all resource needs are satisfied
                    if j == total_resources:
                        # Simulate the allocation of resources to the process
                        for k in range(total_resources):
                            work_array[k] += allocation_array[m][k]
                        # Add the process to the safe sequence
                        safe_sequence_array[count] = m
                        finish_processes[m] = True # Mark process as finished
                        found_safe_system = True # A safe process was found
        # If no process could be found to finish, the system is not in a safe state
        if not found_safe_system:
            print("The system is not in a safe state due to insufficient resources.")
            return False # Return false indicating unsafe state
    # If the system is in a safe state, print the safe sequence
    print("The system is in a safe state. Safe sequence:", end=" ")
    for i in range(total_process):
        print("P" + str(safe_sequence_array[i]), end=" ") # Print each process in the safe sequence
    print() # New line after printing the safe sequence
    return True # Return true indicating safe state

# Main method to execute the program
def main():
    # Read the number of processes and resources
    total_process, total_resources = map(int, input().split())
    
    # Initialize the processes array
    processes = list(range(total_process))
    
    # Initialize the available resources array
    available_array = list(map(int, input().split()))
    
    # Initialize the maximum resources array for each process
    max_array = [[0 for _ in range(total_resources)] for _ in range(total_process)]
    for i in range(total_process):
        max_array[i] = list(map(int, input().split()))
    
    # Initialize the allocation array for each process
    allocation_array = [[0 for _ in range(total_resources)] for _ in range(total_process)]
    for i in range(total_process):
        allocation_array[i] = list(map(int, input().split()))
    
    # Check if the system is in a safe state
    check_safe_system(processes, available_array, max_array, allocation_array, total_process, total_resources)

if __name__ == "__main__":
    main()

