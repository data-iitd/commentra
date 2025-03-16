
import sys

# Private constructor to prevent instantiation
class Main:
    def __init__(self):
        pass

    # Method to calculate the need matrix for each process
    def calculateNeed(self, needArray, maxArray, allocationArray, totalProcess, totalResources):
        for i in range(totalProcess):
            for j in range(totalResources):
                needArray[i][j] = maxArray[i][j] - allocationArray[i][j]

    # Method to check if the system is in a safe state
    def checkSafeSystem(self, processes, availableArray, maxArray, allocationArray, totalProcess, totalResources):
        # Initialize the need array
        needArray = [[0 for i in range(totalResources)] for j in range(totalProcess)]
        self.calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources)

        # Array to keep track of finished processes
        finishProcesses = [False for i in range(totalProcess)]

        # Array to store the safe sequence
        safeSequenceArray = [0 for i in range(totalProcess)]

        # Array to represent the available resources
        workArray = availableArray[:]

        # Counter for the number of processes that have been processed
        count = 0

        # Loop until all processes are processed
        while count < totalProcess:
            foundSafeSystem = False
            for m in range(totalProcess):
                if not finishProcesses[m]:
                    j = 0
                    while j < totalResources:
                        if needArray[m][j] > workArray[j]:
                            break
                        j += 1
                    if j == totalResources:
                        for k in range(totalResources):
                            workArray[k] += allocationArray[m][k]
                        safeSequenceArray[count] = processes[m]
                        finishProcesses[m] = True
                        foundSafeSystem = True
            if not foundSafeSystem:
                print("The system is not in a safe state due to insufficient resources.")
                return False
            count += 1
        print("The system is in a safe state. Safe sequence: ", end="")
        for i in range(totalProcess):
            print("P" + str(safeSequenceArray[i]) + " ", end="")
        print()
        return True

    # Main method to run the program
    def main(self):
        # Read input from stdin
        numberOfProcesses, numberOfResources = map(int, input().split())

        # Array to store process IDs
        processes = [i for i in range(numberOfProcesses)]

        # Array to store the available resources
        availableArray = list(map(int, input().split()))

        # Matrix to store the maximum resource requirements for each process
        maxArray = []
        for i in range(numberOfProcesses):
            maxArray.append(list(map(int, input().split())))

        # Matrix to store the current resource allocations for each process
        allocationArray = []
        for i in range(numberOfProcesses):
            allocationArray.append(list(map(int, input().split())))

        # Check if the system is in a safe state and print the result
        self.checkSafeSystem(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources)

# Main function to run the program
if __name__ == "__main__":
    main = Main()
    main.main()

