import sys

# Private method to calculate the need matrix based on max and allocation matrices
def calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources):
    # Iterate through each process and resource to calculate the need
    for i in range(totalProcess):
        for j in range(totalResources):
            # Need is calculated as maximum demand minus current allocation
            needArray[i][j] = maxArray[i][j] - allocationArray[i][j]

# Private method to check if the system is in a safe state
def checkSafeSystem(processes, availableArray, maxArray, allocationArray, totalProcess, totalResources):
    # Create a need array to hold the remaining resource needs for each process
    needArray = [[0 for i in range(totalResources)] for j in range(totalProcess)]
    # Calculate the need for each process
    calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources)
    
    # Array to track which processes have finished
    finishProcesses = [False for i in range(totalProcess)]
    # Array to store the safe sequence of processes
    safeSequenceArray = [0 for i in range(totalProcess)]
    # Work array to keep track of available resources
    workArray = [0 for i in range(totalResources)]
    # Initialize work array with available resources
    workArray = availableArray[:]
    
    count = 0 # Count of processes that have finished
    # Loop until all processes are finished
    while count < totalProcess:
        foundSafeSystem = False # Flag to check if a safe process was found
        # Check each process to see if it can finish
        for m in range(totalProcess):
            # If the process has not finished yet
            if not finishProcesses[m]:
                j = 0
                # Check if the process can be satisfied with the current work array
                for j in range(totalResources):
                    if needArray[m][j] > workArray[j]:
                        break # Process cannot be satisfied
                # If all resource needs are satisfied
                if j == totalResources:
                    # Simulate the allocation of resources to the process
                    for k in range(totalResources):
                        workArray[k] += allocationArray[m][k]
                    # Add the process to the safe sequence
                    safeSequenceArray[count] = processes[m]
                    count += 1
                    finishProcesses[m] = True # Mark process as finished
                    foundSafeSystem = True # A safe process was found
        # If no process could be found to finish, the system is not in a safe state
        if not foundSafeSystem:
            print("The system is not in a safe state due to insufficient resources.")
            return False # Return false indicating unsafe state
    # If the system is in a safe state, print the safe sequence
    print("The system is in a safe state. Safe sequence: ", end="")
    for i in range(totalProcess):
        print("P" + str(safeSequenceArray[i]) + " ", end="") # Print each process in the safe sequence
    print() # New line after printing the safe sequence
    return True # Return true indicating safe state

# Main method to execute the program
def main():
    # Read the number of processes and resources
    numberOfProcesses, numberOfResources = map(int, input().split())
    
    # Initialize the processes array
    processes = [i for i in range(numberOfProcesses)]
    
    # Initialize the available resources array
    availableArray = list(map(int, input().split()))
    
    # Initialize the maximum resources array for each process
    maxArray = [[0 for i in range(numberOfResources)] for j in range(numberOfProcesses)]
    for i in range(numberOfProcesses):
        maxArray[i] = list(map(int, input().split()))
    
    # Initialize the allocation array for each process
    allocationArray = [[0 for i in range(numberOfResources)] for j in range(numberOfProcesses)]
    for i in range(numberOfProcesses):
        allocationArray[i] = list(map(int, input().split()))
    
    # Check if the system is in a safe state
    checkSafeSystem(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources)

if __name__ == "__main__":
    main()

# 