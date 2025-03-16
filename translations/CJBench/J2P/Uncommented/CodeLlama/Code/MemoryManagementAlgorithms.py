
import sys

def fitProcess(sizeOfBlocks, sizeOfProcesses):
    memAlloc = []
    for processSize in sizeOfProcesses:
        chosenBlockIdx = findBestFit(sizeOfBlocks, processSize)
        memAlloc.append(chosenBlockIdx)
        if chosenBlockIdx != -255:
            sizeOfBlocks[chosenBlockIdx] -= processSize
    return memAlloc

def findBestFit(sizeOfBlocks, processSize):
    minDiff = sys.maxsize
    index = -255
    for i in range(len(sizeOfBlocks)):
        if sizeOfBlocks[i] >= processSize and sizeOfBlocks[i] - processSize < minDiff:
            minDiff = sizeOfBlocks[i] - processSize
            index = i
    return index

def findWorstFit(sizeOfBlocks, processSize):
    max = -1
    index = -255
    for i in range(len(sizeOfBlocks)):
        if sizeOfBlocks[i] >= processSize and sizeOfBlocks[i] > max:
            max = sizeOfBlocks[i]
            index = i
    return index

def findFirstFit(sizeOfBlocks, processSize):
    for i in range(len(sizeOfBlocks)):
        if sizeOfBlocks[i] >= processSize:
            return i
    return -255

def findNextFit(sizeOfBlocks, processSize):
    for i in range(len(sizeOfBlocks)):
        idx = (counter + i) % len(sizeOfBlocks)
        if sizeOfBlocks[idx] >= processSize:
            counter = idx
            return idx
    return -255

def main():
    numBlocks = int(input())
    blockSizes = list(map(int, input().split()))
    numProcesses = int(input())
    processSizes = list(map(int, input().split()))
    choice = int(input())
    algorithm = None
    if choice == 1:
        algorithm = fitProcess
    elif choice == 2:
        algorithm = findWorstFit
    elif choice == 3:
        algorithm = findFirstFit
    elif choice == 4:
        algorithm = findNextFit
    else:
        print("Invalid choice.")
        return
    memAlloc = algorithm(blockSizes, processSizes)
    print("Memory Allocation Results:")
    for i in range(len(memAlloc)):
        if memAlloc[i] != -255:
            print(f"Process {i} -> Block {memAlloc[i]}")
        else:
            print(f"Process {i} -> No Allocation")

if __name__ == "__main__":
    main()

