
import sys

# Main class for the memory allocation problem solution
class Main:
    # Abstract method to find the best fit process for given block sizes and process sizes
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        pass

    # Constant value for no allocation
    NO_ALLOCATION = -255

    # Main method to read input and call the appropriate algorithm based on user choice
    def main(self):
        # Read the number of blocks and store their sizes in an array
        numBlocks = int(input())
        blockSizes = []
        for i in range(numBlocks):
            blockSizes.append(int(input())) # Read the size of each block and store it in the array

        # Read the number of processes and store their sizes in an array
        numProcesses = int(input())
        processSizes = []
        for i in range(numProcesses):
            processSizes.append(int(input())) # Read the size of each process and store it in the array

        # Read the user choice for the memory allocation algorithm
        choice = int(input())

        # Initialize the appropriate algorithm object based on the user choice
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
            print("Invalid choice.") # Print an error message for invalid user choice
            sys.exit()

        # Call the fitProcess method of the algorithm object to find the memory allocation for each process
        allocations = algorithm.fitProcess(blockSizes, processSizes)

        # Print the memory allocation results
        print("Memory Allocation Results:")
        for i in range(len(allocations)):
            if allocations[i] != self.NO_ALLOCATION:
                print(f"Process {i} -> Block {allocations[i]}")
            else:
                print(f"Process {i} -> No Allocation")

# BestFitCPU class for the Best Fit algorithm
class BestFitCPU(Main):
    # Find the index of the block with the best fit for the given process size
    def findBestFit(self, blockSizes, processSize):
        minDiff = sys.maxsize
        index = self.NO_ALLOCATION
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] - processSize < minDiff:
                minDiff = blockSizes[i] - processSize
                index = i
        return index

    # Override the fitProcess method to implement the Best Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findBestFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# WorstFitCPU class for the Worst Fit algorithm
class WorstFitCPU(Main):
    # Find the index of the block with the worst fit for the given process size
    def findWorstFit(self, blockSizes, processSize):
        max = -1
        index = self.NO_ALLOCATION
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] > max:
                max = blockSizes[i]
                index = i
        return index

    # Override the fitProcess method to implement the Worst Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findWorstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# FirstFitCPU class for the First Fit algorithm
class FirstFitCPU(Main):
    # Find the index of the first available block for the given process size
    def findFirstFit(self, blockSizes, processSize):
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize:
                return i
        return self.NO_ALLOCATION

    # Override the fitProcess method to implement the First Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# NextFit class for the Next Fit algorithm
class NextFit(Main):
    # Counter variable to keep track of the index in the blockSizes array
    counter = 0

    # Find the index of the next available block for the given process size
    def findNextFit(self, blockSizes, processSize):
        idx = (self.counter + 1) % len(blockSizes)
        while idx < len(blockSizes):
            if blockSizes[idx] >= processSize:
                self.counter = idx
                return idx
            idx += 1
        return self.NO_ALLOCATION

    # Override the fitProcess method to implement the Next Fit algorithm
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# Create an object of the Main class and call its main method
Main().main()

