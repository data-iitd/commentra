

# Main class for the memory allocation problem solution
class Main:
    # Abstract method to find the best fit process for given block sizes and process sizes
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        pass

    # Constant value for no allocation
    NO_ALLOCATION = -255

# BestFitCPU class for the Best Fit algorithm
class BestFitCPU(Main):
    # Find the index of the block with the best fit for the given process size
    def findBestFit(self, sizeOfBlocks, processSize):
        minDiff = float('inf')
        index = Main.NO_ALLOCATION
        for i in range(len(sizeOfBlocks)):
            if sizeOfBlocks[i] >= processSize and sizeOfBlocks[i] - processSize < minDiff:
                minDiff = sizeOfBlocks[i] - processSize
                index = i
        return index

    # Override the fitProcess method to implement the Best Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findBestFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# WorstFitCPU class for the Worst Fit algorithm
class WorstFitCPU(Main):
    # Find the index of the block with the worst fit for the given process size
    def findWorstFit(self, sizeOfBlocks, processSize):
        max = -1
        index = Main.NO_ALLOCATION
        for i in range(len(sizeOfBlocks)):
            if sizeOfBlocks[i] >= processSize and sizeOfBlocks[i] > max:
                max = sizeOfBlocks[i]
                index = i
        return index

    # Override the fitProcess method to implement the Worst Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findWorstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# FirstFitCPU class for the First Fit algorithm
class FirstFitCPU(Main):
    # Find the index of the first available block for the given process size
    def findFirstFit(self, sizeOfBlocks, processSize):
        for i in range(len(sizeOfBlocks)):
            if sizeOfBlocks[i] >= processSize:
                return i
        return Main.NO_ALLOCATION

    # Override the fitProcess method to implement the First Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# NextFit class for the Next Fit algorithm
class NextFit(Main):
    # Counter variable to keep track of the index in the blockSizes array
    counter = 0

    # Find the index of the next available block for the given process size
    def findNextFit(self, sizeOfBlocks, processSize):
        idx = (self.counter + 1) % len(sizeOfBlocks)
        while idx < len(sizeOfBlocks):
            if sizeOfBlocks[idx] >= processSize:
                self.counter = idx
                return idx
            idx += 1
        return Main.NO_ALLOCATION

    # Override the fitProcess method to implement the Next Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# Translate the above Python code to C++ and end with comment "