
import sys

# Abstract class representing the main memory allocation algorithm
class Main:
    # Abstract method to fit processes into memory blocks
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        pass

    # Constant representing no allocation
    NO_ALLOCATION = -255

# Class implementing the Best Fit memory allocation algorithm
class BestFitCPU(Main):
    # Method to find the best fit block for a given process size
    def findBestFit(self, sizeOfBlocks, processSize):
        minDiff = sys.maxsize # Initialize minimum difference
        index = Main.NO_ALLOCATION # Initialize index for no allocation

        # Iterate through the blocks to find the best fit
        for i in range(len(sizeOfBlocks)):
            if sizeOfBlocks[i] >= processSize and sizeOfBlocks[i] - processSize < minDiff:
                minDiff = sizeOfBlocks[i] - processSize # Update minimum difference
                index = i # Update index of the best fit block

        return index # Return the index of the best fit block

    # Override the fitProcess method to implement Best Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = [] # List to store memory allocations

        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findBestFit(sizeOfBlocks, processSize) # Find the best fit block
            memAlloc.append(chosenBlockIdx) # Add the allocation result

            # If a block is allocated, reduce its size
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize

        return memAlloc # Return the list of allocations

# Class implementing the Worst Fit memory allocation algorithm
class WorstFitCPU(Main):
    # Method to find the worst fit block for a given process size
    def findWorstFit(self, sizeOfBlocks, processSize):
        max = -1 # Initialize maximum size
        index = Main.NO_ALLOCATION # Initialize index for no allocation

        # Iterate through the blocks to find the worst fit
        for i in range(len(sizeOfBlocks)):
            if sizeOfBlocks[i] >= processSize and sizeOfBlocks[i] > max:
                max = sizeOfBlocks[i] # Update maximum size
                index = i # Update index of the worst fit block

        return index # Return the index of the worst fit block

    # Override the fitProcess method to implement Worst Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = [] # List to store memory allocations

        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findWorstFit(sizeOfBlocks, processSize) # Find the worst fit block
            memAlloc.append(chosenBlockIdx) # Add the allocation result

            # If a block is allocated, reduce its size
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize

        return memAlloc # Return the list of allocations

# Class implementing the First Fit memory allocation algorithm
class FirstFitCPU(Main):
    # Method to find the first fit block for a given process size
    def findFirstFit(self, sizeOfBlocks, processSize):
        # Iterate through the blocks to find the first fit
        for i in range(len(sizeOfBlocks)):
            if sizeOfBlocks[i] >= processSize:
                return i # Return the index of the first fit block

        return Main.NO_ALLOCATION # Return no allocation if no fit is found

    # Override the fitProcess method to implement First Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = [] # List to store memory allocations

        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize) # Find the first fit block
            memAlloc.append(chosenBlockIdx) # Add the allocation result

            # If a block is allocated, reduce its size
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize

        return memAlloc # Return the list of allocations

# Class implementing the Next Fit memory allocation algorithm
class NextFit(Main):
    def __init__(self):
        self.counter = 0 # Counter to track the next fit position

    # Method to find the next fit block for a given process size
    def findNextFit(self, sizeOfBlocks, processSize):
        # Iterate through the blocks starting from the last allocated position
        for i in range(len(sizeOfBlocks)):
            idx = (self.counter + i) % len(sizeOfBlocks) # Calculate the index in a circular manner
            if sizeOfBlocks[idx] >= processSize:
                self.counter = idx # Update the counter to the current index
                return idx # Return the index of the next fit block

        return Main.NO_ALLOCATION # Return no allocation if no fit is found

    # Override the fitProcess method to implement Next Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = [] # List to store memory allocations

        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize) # Find the next fit block
            memAlloc.append(chosenBlockIdx) # Add the allocation result

            # If a block is allocated, reduce its size
            if chosenBlockIdx!= Main.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize

        return memAlloc # Return the list of allocations

# Translate the above Java code to Python and end with comment "