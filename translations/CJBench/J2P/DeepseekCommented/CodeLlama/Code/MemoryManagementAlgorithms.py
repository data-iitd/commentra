import sys

def fitProcess(blockSizes, processSizes):
    # Memory Allocation
    allocations = []
    for processSize in processSizes:
        chosenBlockIdx = findBestFit(blockSizes, processSize)
        allocations.append(chosenBlockIdx)
        if chosenBlockIdx != -255:
            blockSizes[chosenBlockIdx] -= processSize
    return allocations

def findBestFit(blockSizes, processSize):
    minDiff = sys.maxsize
    index = -255
    for i in range(len(blockSizes)):
        if blockSizes[i] >= processSize and blockSizes[i] - processSize < minDiff:
            minDiff = blockSizes[i] - processSize
            index = i
    return index

def findWorstFit(blockSizes, processSize):
    max = -1
    index = -255
    for i in range(len(blockSizes)):
        if blockSizes[i] >= processSize and blockSizes[i] > max:
            max = blockSizes[i]
            index = i
    return index

def findFirstFit(blockSizes, processSize):
    for i in range(len(blockSizes)):
        if blockSizes[i] >= processSize:
            return i
    return -255

def findNextFit(blockSizes, processSize):
    for i in range(len(blockSizes)):
        idx = (counter + i) % len(blockSizes)
        if blockSizes[idx] >= processSize:
            counter = idx
            return idx
    return -255

# Main
if __name__ == "__main__":
    # Input Reading and Initialization
    numBlocks = int(input())
    blockSizes = list(map(int, input().split()))
    numProcesses = int(input())
    processSizes = list(map(int, input().split()))
    
    # Algorithm Selection
    choice = int(input())
    algorithm = None
    if choice == 1:
        algorithm = findBestFit
    elif choice == 2:
        algorithm = findWorstFit
    elif choice == 3:
        algorithm = findFirstFit
    elif choice == 4:
        algorithm = findNextFit
    else:
        print("Invalid choice.")
        sys.exit()
    
    # Memory Allocation
    allocations = fitProcess(blockSizes, processSizes)
    
    # Output Results
    print("Memory Allocation Results:")
    for i in range(len(allocations)):
        if allocations[i] != -255:
            print(f"Process {i} -> Block {allocations[i]}")
        else:
            print(f"Process {i} -> No Allocation")

# END-OF-CODE
