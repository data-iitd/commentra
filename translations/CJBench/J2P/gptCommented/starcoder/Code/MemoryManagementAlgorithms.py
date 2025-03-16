import java.util.ArrayList;
import java.util.Scanner;

# Abstract class representing the main memory allocation algorithm
class Main:
    # Abstract method to fit processes into memory blocks
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        pass
    
    # Constant representing no allocation
    NO_ALLOCATION = -255

    def main(self):
        # Create a scanner object for user input
        scanner = Scanner(System.in);
        
        # Read the number of memory blocks
        numBlocks = scanner.nextInt();
        blockSizes = [0] * numBlocks;
        
        # Read the sizes of each memory block
        for i in range(numBlocks):
            blockSizes[i] = scanner.nextInt();
        
        # Read the number of processes
        numProcesses = scanner.nextInt();
        processSizes = [0] * numProcesses;
        
        # Read the sizes of each process
        for i in range(numProcesses):
            processSizes[i] = scanner.nextInt();
        
        # Read the user's choice of memory allocation algorithm
        choice = scanner.nextInt();
        algorithm = None;
        
        # Select the appropriate memory allocation algorithm based on user choice
        if choice == 1:
            algorithm = BestFitCPU();
        elif choice == 2:
            algorithm = WorstFitCPU();
        elif choice == 3:
            algorithm = FirstFitCPU();
        elif choice == 4:
            algorithm = NextFit();
        else:
            # Handle invalid choice
            print("Invalid choice.");
            scanner.close();
            return;
        
        # Perform memory allocation using the selected algorithm
        allocations = algorithm.fitProcess(blockSizes, processSizes);
        
        # Output the results of memory allocation
        print("Memory Allocation Results:");
        for i in range(allocations.size()):
            if allocations.get(i)!= NO_ALLOCATION:
                print("Process %d -> Block %d" % (i, allocations.get(i)));
            else:
                print("Process %d -> No Allocation" % i);
        
        # Close the scanner
        scanner.close();

# Class implementing the Best Fit memory allocation algorithm
class BestFitCPU(Main):
    # Method to find the best fit block for a given process size
    def findBestFit(self, blockSizes, processSize):
        minDiff = Integer.MAX_VALUE; # Initialize minimum difference
        index = self.NO_ALLOCATION; # Initialize index for no allocation
        
        # Iterate through the blocks to find the best fit
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] - processSize < minDiff:
                minDiff = blockSizes[i] - processSize; # Update minimum difference
                index = i; # Update index of the best fit block
        return index; # Return the index of the best fit block

    # Override the fitProcess method to implement Best Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = ArrayList(); # List to store memory allocations
        
        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findBestFit(sizeOfBlocks, processSize); # Find the best fit block
            memAlloc.add(chosenBlockIdx); # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize;
        return memAlloc; # Return the list of allocations

# Class implementing the Worst Fit memory allocation algorithm
class WorstFitCPU(Main):
    # Method to find the worst fit block for a given process size
    def findWorstFit(self, blockSizes, processSize):
        max = -1; # Initialize maximum size
        index = self.NO_ALLOCATION; # Initialize index for no allocation
        
        # Iterate through the blocks to find the worst fit
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] > max:
                max = blockSizes[i]; # Update maximum size
                index = i; # Update index of the worst fit block
        return index; # Return the index of the worst fit block

    # Override the fitProcess method to implement Worst Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = ArrayList(); # List to store memory allocations
        
        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findWorstFit(sizeOfBlocks, processSize); # Find the worst fit block
            memAlloc.add(chosenBlockIdx); # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize;
        return memAlloc; # Return the list of allocations

# Class implementing the First Fit memory allocation algorithm
class FirstFitCPU(Main):
    # Method to find the first fit block for a given process size
    def findFirstFit(self, blockSizes, processSize):
        # Iterate through the blocks to find the first fit
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize:
                return i; # Return the index of the first fit block
        return self.NO_ALLOCATION; # Return no allocation if no fit is found

    # Override the fitProcess method to implement First Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = ArrayList(); # List to store memory allocations
        
        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize); # Find the first fit block
            memAlloc.add(chosenBlockIdx); # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize;
        return memAlloc; # Return the list of allocations

# Class implementing the Next Fit memory allocation algorithm
class NextFit(Main):
    counter = 0; # Counter to track the next fit position

    # Method to find the next fit block for a given process size
    def findNextFit(self, blockSizes, processSize):
        # Iterate through the blocks starting from the last allocated position
        for i in range(len(blockSizes)):
            idx = (self.counter + i) % len(blockSizes); # Calculate the index in a circular manner
            if blockSizes[idx] >= processSize:
                self.counter = idx; # Update the counter to the current index
                return idx; # Return the index of the next fit block
        return self.NO_ALLOCATION; # Return no allocation if no fit is found

    # Override the fitProcess method to implement Next Fit allocation
    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = ArrayList(); # List to store memory allocations
        
        # Allocate memory for each process
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize); # Find the next fit block
            memAlloc.add(chosenBlockIdx); # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosenBlockIdx!= self.NO_ALLOCATION:
                sizeOfBlocks[chosenBlockIdx] -= processSize;
        return memAlloc; # Return the list of allocations

# Main function
if __name__ == "__main__":
    Main().main();

