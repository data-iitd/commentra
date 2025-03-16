
import sys

class Main:
    def __init__(self):
        self.NO_ALLOCATION = -255

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        pass

    def findBestFit(self, blockSizes, processSize):
        minDiff = sys.maxsize
        index = self.NO_ALLOCATION
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] - processSize < minDiff:
                minDiff = blockSizes[i] - processSize
                index = i
        return index

    def findWorstFit(self, blockSizes, processSize):
        max = -1
        index = self.NO_ALLOCATION
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] > max:
                max = blockSizes[i]
                index = i
        return index

    def findFirstFit(self, blockSizes, processSize):
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize:
                return i
        return self.NO_ALLOCATION

    def findNextFit(self, blockSizes, processSize):
        for i in range(len(blockSizes)):
            idx = (self.counter + i) % len(blockSizes)
            if blockSizes[idx] >= processSize:
                self.counter = idx
                return idx
        return self.NO_ALLOCATION

    def main(self):
        scanner = sys.stdin
        numBlocks = int(scanner.readline())
        blockSizes = [int(scanner.readline()) for _ in range(numBlocks)]
        numProcesses = int(scanner.readline())
        sizeOfProcesses = [int(scanner.readline()) for _ in range(numProcesses)]
        choice = int(scanner.readline())

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
            return

        allocations = algorithm.fitProcess(blockSizes, sizeOfProcesses)
        print("Memory Allocation Results:")
        for i in range(len(allocations)):
            if allocations[i]!= self.NO_ALLOCATION:
                print("Process %d -> Block %d" % (i, allocations[i]))
            else:
                print("Process %d -> No Allocation" % i)

class BestFitCPU(Main):
    def __init__(self):
        super().__init__()

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findBestFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

class WorstFitCPU(Main):
    def __init__(self):
        super().__init__()

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findWorstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

class FirstFitCPU(Main):
    def __init__(self):
        super().__init__()

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

class NextFit(Main):
    def __init__(self):
        super().__init__()
        self.counter = 0

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

if __name__ == "__main__":
    Main().main()

