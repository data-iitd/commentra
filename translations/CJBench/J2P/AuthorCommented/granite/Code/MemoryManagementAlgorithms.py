

import sys

class Main:
    NO_ALLOCATION = -255

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        raise NotImplementedError("fitProcess must be implemented in subclass.")

    @staticmethod
    def readInput():
        numBlocks = int(input())
        blockSizes = list(map(int, input().split()))
        numProcesses = int(input())
        processSizes = list(map(int, input().split()))
        choice = int(input())
        return numBlocks, blockSizes, numProcesses, processSizes, choice

    @staticmethod
    def printAllocations(allocations):
        print("Memory Allocation Results:")
        for i, allocation in enumerate(allocations):
            if allocation!= Main.NO_ALLOCATION:
                print(f"Process {i} -> Block {allocation}")
            else:
                print(f"Process {i} -> No Allocation")

    @staticmethod
    def main():
        numBlocks, blockSizes, numProcesses, processSizes, choice = Main.readInput()

        algorithm = None
        if choice == 1:
            algorithm = BestFitCPU()
        elif choice == 2:
            algorithm = WorstFitCPU()
        elif choice == 3:
            algorithm = FirstFitCPU()
        elif choice == 4:
            algorithm = NextFit()
        else:
            print("Invalid choice.")
            sys.exit(1)

        allocations = algorithm.fitProcess(blockSizes, processSizes)
        Main.printAllocations(allocations)

class BestFitCPU(Main):
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        allocations = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findBestFit(sizeOfBlocks, processSize)
            allocations.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return allocations

    @staticmethod
    def findBestFit(blockSizes, processSize):
        minDiff = float("inf")
        index = Main.NO_ALLOCATION
        for i, blockSize in enumerate(blockSizes):
            if blockSize >= processSize and blockSize - processSize < minDiff:
                minDiff = blockSize - processSize
                index = i
        return index

class WorstFitCPU(Main):
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        allocations = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findWorstFit(sizeOfBlocks, processSize)
            allocations.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return allocations

    @staticmethod
    def findWorstFit(blockSizes, processSize):
        max = -1
        index = Main.NO_ALLOCATION
        for i, blockSize in enumerate(blockSizes):
            if blockSize >= processSize and blockSize > max:
                max = blockSize
                index = i
        return index

class FirstFitCPU(Main):
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        allocations = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize)
            allocations.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return allocations

    @staticmethod
    def findFirstFit(blockSizes, processSize):
        for i, blockSize in enumerate(blockSizes):
            if blockSize >= processSize:
                return i
        return Main.NO_ALLOCATION

class NextFit(Main):
    def __init__(self):
        self.counter = 0

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        allocations = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize)
            allocations.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return allocations

    def findNextFit(self, sizeOfBlocks, processSize):
        for i in range(len(sizeOfBlocks)):
            idx = (self.counter + i) % len(sizeOfBlocks)
            if sizeOfBlocks[idx] >= processSize:
                self.counter = idx
                return idx
        return Main.NO_ALLOCATION

if __name__ == "__main__":
    Main.main()

