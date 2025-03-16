
# Import the necessary libraries
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
    def findBestFit(self, blockSizes, processSize):
        minDiff = sys.maxsize # Initialize minimum difference
        index = self.NO_ALLOCATION # Initialize index for no allocation

        # Iterate through the blocks to find the best fit
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] - processSize < minDiff:
                minDiff = blockSizes[i] - processSize # Update minimum difference
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
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc # Return the list of allocations

# Class implementing the Worst Fit memory allocation algorithm
class WorstFitCPU(Main):
    # Method to find the worst fit block for a given process size
    def findWorstFit(self, blockSizes, processSize):
        max = -1 # Initialize maximum size
        index = self.NO_ALLOCATION # Initialize index for no allocation

        # Iterate through the blocks to find the worst fit
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] > max:
                max = blockSizes[i] # Update maximum size
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
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc # Return the list of allocations

# Class implementing the First Fit memory allocation algorithm
class FirstFitCPU(Main):
    # Method to find the first fit block for a given process size
    def findFirstFit(self, blockSizes, processSize):
        # Iterate through the blocks to find the first fit
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize:
                return i # Return the index of the first fit block
        return self.NO_ALLOCATION # Return no allocation if no fit is found

    # Override the fitProcess method to implement First Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = [] # List to store memory allocations

        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize) # Find the first fit block
            memAlloc.append(chosenBlockIdx) # Add the allocation result

            # If a block is allocated, reduce its size
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc # Return the list of allocations

# Class implementing the Next Fit memory allocation algorithm
class NextFit(Main):
    def __init__(self):
        self.counter = 0 # Counter to track the next fit position

    # Method to find the next fit block for a given process size
    def findNextFit(self, blockSizes, processSize):
        # Iterate through the blocks starting from the last allocated position
        for i in range(len(blockSizes)):
            idx = (self.counter + i) % len(blockSizes) # Calculate the index in a circular manner
            if blockSizes[idx] >= processSize:
                self.counter = idx # Update the counter to the current index
                return idx # Return the index of the next fit block
        return self.NO_ALLOCATION # Return no allocation if no fit is found

    # Override the fitProcess method to implement Next Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = [] # List to store memory allocations

        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize) # Find the next fit block
            memAlloc.append(chosenBlockIdx) # Add the allocation result

            # If a block is allocated, reduce its size
            if chosenBlockIdx != self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc # Return the list of allocations

# Main function to read user input and perform memory allocation
def main():
    # Create a scanner object for user input
    scanner = sys.stdin

    # Read the number of memory blocks
    numBlocks = int(scanner.readline().strip())
    blockSizes = []

    # Read the sizes of each memory block
    for i in range(numBlocks):
        blockSizes.append(int(scanner.readline().strip()))

    # Read the number of processes
    numProcesses = int(scanner.readline().strip())
    processSizes = []

    # Read the sizes of each process
    for i in range(numProcesses):
        processSizes.append(int(scanner.readline().strip()))

    # Read the user's choice of memory allocation algorithm
    choice = int(scanner.readline().strip())
    algorithm = None

    # Select the appropriate memory allocation algorithm based on user choice
    if choice == 1:
        algorithm = BestFitCPU()
    elif choice == 2:
        algorithm = WorstFitCPU()
    elif choice == 3:
        algorithm = FirstFitCPU()
    elif choice == 4:
        algorithm = NextFit()
    else:
        # Handle invalid choice
        print("Invalid choice.")
        return

    # Perform memory allocation using the selected algorithm
    allocations = algorithm.fitProcess(blockSizes, processSizes)

    # Output the results of memory allocation
    print("Memory Allocation Results:")
    for i in range(len(allocations)):
        if allocations[i] != Main.NO_ALLOCATION:
            print("Process %d -> Block %d" % (i, allocations[i]))
        else:
            print("Process %d -> No Allocation" % i)

# Main function to run the program
if __name__ == "__main__":
    main()
