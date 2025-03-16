
import sys
import math

def calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources):
    for i in range(totalProcess):
        for j in range(totalResources):
            needArray[i][j] = maxArray[i][j] - allocationArray[i][j]

def checkSafeSystem(processes, availableArray, maxArray, allocationArray, totalProcess, totalResources):
    needArray = [[0 for i in range(totalResources)] for j in range(totalProcess)]
    calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources)
    finishProcesses = [False for i in range(totalProcess)]
    safeSequenceArray = [0 for i in range(totalProcess)]
    workArray = [0 for i in range(totalResources)]
    workArray = availableArray[:]
    count = 0
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
                    safeSequenceArray[count] = m
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

def main():
    totalProcess = int(input())
    totalResources = int(input())
    processes = [i for i in range(totalProcess)]
    availableArray = [int(input()) for i in range(totalResources)]
    maxArray = [[int(input()) for i in range(totalResources)] for j in range(totalProcess)]
    allocationArray = [[int(input()) for i in range(totalResources)] for j in range(totalProcess)]
    checkSafeSystem(processes, availableArray, maxArray, allocationArray, totalProcess, totalResources)

if __name__ == "__main__":
    main()

