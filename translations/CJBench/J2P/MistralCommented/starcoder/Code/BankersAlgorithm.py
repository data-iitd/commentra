
import sys

def calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources):
    # Calculate the need matrix by subtracting the allocation matrix from the maximum matrix
    for i in range(totalProcess):
        for j in range(totalResources):
            needArray[i][j] = maxArray[i][j] - allocationArray[i][j]
            # Update the need matrix element for the current process and resource

def checkSafeSystem(processes, availableArray, maxArray, allocationArray, totalProcess, totalResources):
    needArray = [[0 for i in range(totalResources)] for j in range(totalProcess)]
    # Initialize the need matrix
    calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources)
    finishProcesses = [False for i in range(totalProcess)]
    # Initialize the finish processes array with false values
    safeSequenceArray = [0 for i in range(totalProcess)]
    # Initialize the safe sequence array
    workArray = availableArray[:]
    # Initialize the work array with the available resources
    count = 0
    # Initialize the safe sequence counter
    while count < totalProcess:
        foundSafeSystem = False
        # Initialize the foundSafeSystem flag
        for m in range(totalProcess):
            if not finishProcesses[m]:
                j = 0
                # Initialize the j index
                while j < totalResources:
                    if needArray[m][j] > workArray[j]:
                        # If the current process needs more resources than available, break the inner loop
                        break
                    j += 1
                if j == totalResources:
                    # If the current process can be executed safely, update the work array and safe sequence array
                    for k in range(totalResources):
                        workArray[k] += allocationArray[m][k]
                    safeSequenceArray[count] = processes[m]
                    finishProcesses[m] = True
                    foundSafeSystem = True
                    # Update the finishProcesses array for the current process
        if not foundSafeSystem:
            # If no safe sequence is found, print the error message and return false
            print("The system is not in a safe state due to insufficient resources.")
            return False
        count += 1
    # If a safe sequence is found, print the safe sequence message and return true
    print("The system is in a safe state. Safe sequence: ", end="")
    for i in range(totalProcess):
        print("P" + str(safeSequenceArray[i]) + " ", end="")
    print()
    return True

if __name__ == "__main__":
    totalProcess = int(input())
    # Read the number of processes from the console
    totalResources = int(input())
    # Read the number of resources from the console
    processes = [i for i in range(totalProcess)]
    # Initialize the processes array
    availableArray = [int(input()) for i in range(totalResources)]
    # Read the available resources for each resource from the console
    maxArray = [[int(input()) for i in range(totalResources)] for j in range(totalProcess)]
    # Read the maximum resources for each process and resource from the console
    allocationArray = [[int(input()) for i in range(totalResources)] for j in range(totalProcess)]
    # Read the allocated resources for each process and resource from the console
    checkSafeSystem(processes, availableArray, maxArray, allocationArray, totalProcess, totalResources)
    # Call the checkSafeSystem method with the given input parameters

