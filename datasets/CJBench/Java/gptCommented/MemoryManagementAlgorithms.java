import java.util.ArrayList;
import java.util.Scanner;

// Abstract class representing the main memory allocation algorithm
public abstract class Main {
    // Abstract method to fit processes into memory blocks
    public abstract ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses);
    
    // Constant representing no allocation
    protected static final int NO_ALLOCATION = -255;

    public static void main(String[] args) {
        // Create a scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of memory blocks
        int numBlocks = scanner.nextInt();
        int[] blockSizes = new int[numBlocks];
        
        // Read the sizes of each memory block
        for (int i = 0; i < numBlocks; i++) {
            blockSizes[i] = scanner.nextInt();
        }
        
        // Read the number of processes
        int numProcesses = scanner.nextInt();
        int[] processSizes = new int[numProcesses];
        
        // Read the sizes of each process
        for (int i = 0; i < numProcesses; i++) {
            processSizes[i] = scanner.nextInt();
        }
        
        // Read the user's choice of memory allocation algorithm
        int choice = scanner.nextInt();
        Main algorithm;
        
        // Select the appropriate memory allocation algorithm based on user choice
        switch (choice) {
            case 1:
                algorithm = new BestFitCPU();
                break;
            case 2:
                algorithm = new WorstFitCPU();
                break;
            case 3:
                algorithm = new FirstFitCPU();
                break;
            case 4:
                algorithm = new NextFit();
                break;
            default:
                // Handle invalid choice
                System.out.println("Invalid choice.");
                scanner.close();
                return;
        }
        
        // Perform memory allocation using the selected algorithm
        ArrayList<Integer> allocations = algorithm.fitProcess(blockSizes, processSizes);
        
        // Output the results of memory allocation
        System.out.println("Memory Allocation Results:");
        for (int i = 0; i < allocations.size(); i++) {
            if (allocations.get(i) != NO_ALLOCATION) {
                System.out.printf("Process %d -> Block %d\n", i, allocations.get(i));
            } else {
                System.out.printf("Process %d -> No Allocation\n", i);
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}

// Class implementing the Best Fit memory allocation algorithm
class BestFitCPU extends Main {
    // Method to find the best fit block for a given process size
    private static int findBestFit(int[] blockSizes, int processSize) {
        int minDiff = Integer.MAX_VALUE; // Initialize minimum difference
        int index = NO_ALLOCATION; // Initialize index for no allocation
        
        // Iterate through the blocks to find the best fit
        for (int i = 0; i < blockSizes.length; i++) {
            if (blockSizes[i] >= processSize && blockSizes[i] - processSize < minDiff) {
                minDiff = blockSizes[i] - processSize; // Update minimum difference
                index = i; // Update index of the best fit block
            }
        }
        return index; // Return the index of the best fit block
    }

    // Override the fitProcess method to implement Best Fit allocation
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>(); // List to store memory allocations
        
        // Allocate memory for each process
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findBestFit(sizeOfBlocks, processSize); // Find the best fit block
            memAlloc.add(chosenBlockIdx); // Add the allocation result
            
            // If a block is allocated, reduce its size
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc; // Return the list of allocations
    }
}

// Class implementing the Worst Fit memory allocation algorithm
class WorstFitCPU extends Main {
    // Method to find the worst fit block for a given process size
    private static int findWorstFit(int[] blockSizes, int processSize) {
        int max = -1; // Initialize maximum size
        int index = NO_ALLOCATION; // Initialize index for no allocation
        
        // Iterate through the blocks to find the worst fit
        for (int i = 0; i < blockSizes.length; i++) {
            if (blockSizes[i] >= processSize && blockSizes[i] > max) {
                max = blockSizes[i]; // Update maximum size
                index = i; // Update index of the worst fit block
            }
        }
        return index; // Return the index of the worst fit block
    }

    // Override the fitProcess method to implement Worst Fit allocation
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>(); // List to store memory allocations
        
        // Allocate memory for each process
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findWorstFit(sizeOfBlocks, processSize); // Find the worst fit block
            memAlloc.add(chosenBlockIdx); // Add the allocation result
            
            // If a block is allocated, reduce its size
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc; // Return the list of allocations
    }
}

// Class implementing the First Fit memory allocation algorithm
class FirstFitCPU extends Main {
    // Method to find the first fit block for a given process size
    private static int findFirstFit(int[] blockSizes, int processSize) {
        // Iterate through the blocks to find the first fit
        for (int i = 0; i < blockSizes.length; i++) {
            if (blockSizes[i] >= processSize) {
                return i; // Return the index of the first fit block
            }
        }
        return NO_ALLOCATION; // Return no allocation if no fit is found
    }

    // Override the fitProcess method to implement First Fit allocation
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>(); // List to store memory allocations
        
        // Allocate memory for each process
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findFirstFit(sizeOfBlocks, processSize); // Find the first fit block
            memAlloc.add(chosenBlockIdx); // Add the allocation result
            
            // If a block is allocated, reduce its size
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc; // Return the list of allocations
    }
}

// Class implementing the Next Fit memory allocation algorithm
class NextFit extends Main {
    private int counter = 0; // Counter to track the next fit position

    // Method to find the next fit block for a given process size
    private int findNextFit(int[] blockSizes, int processSize) {
        // Iterate through the blocks starting from the last allocated position
        for (int i = 0; i < blockSizes.length; i++) {
            int idx = (counter + i) % blockSizes.length; // Calculate the index in a circular manner
            if (blockSizes[idx] >= processSize) {
                counter = idx; // Update the counter to the current index
                return idx; // Return the index of the next fit block
            }
        }
        return NO_ALLOCATION; // Return no allocation if no fit is found
    }

    // Override the fitProcess method to implement Next Fit allocation
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>(); // List to store memory allocations
        
        // Allocate memory for each process
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findNextFit(sizeOfBlocks, processSize); // Find the next fit block
            memAlloc.add(chosenBlockIdx); // Add the allocation result
            
            // If a block is allocated, reduce its size
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc; // Return the list of allocations
    }
}
