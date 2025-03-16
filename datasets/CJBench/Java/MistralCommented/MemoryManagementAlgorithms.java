
import java.util.ArrayList;
import java.util.Scanner;

// Main class for the memory allocation problem solution
public abstract class Main {
    // Abstract method to find the best fit process for given block sizes and process sizes
    public abstract ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses);

    // Constant value for no allocation
    protected static final int NO_ALLOCATION = -255;

    // Main method to read input and call the appropriate algorithm based on user choice
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console

        // Read the number of blocks and store their sizes in an array
        int numBlocks = scanner.nextInt();
        int[] blockSizes = new int[numBlocks];
        for (int i = 0; i < numBlocks; i++) {
            blockSizes[i] = scanner.nextInt(); // Read the size of each block and store it in the array
        }

        // Read the number of processes and store their sizes in an array
        int numProcesses = scanner.nextInt();
        int[] processSizes = new int[numProcesses];
        for (int i = 0; i < numProcesses; i++) {
            processSizes[i] = scanner.nextInt(); // Read the size of each process and store it in the array
        }

        // Read the user choice for the memory allocation algorithm
        int choice = scanner.nextInt();

        // Initialize the appropriate algorithm object based on the user choice
        Main algorithm;
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
                System.out.println("Invalid choice."); // Print an error message for invalid user choice
                scanner.close();
                return;
        }

        // Call the fitProcess method of the algorithm object to find the memory allocation for each process
        ArrayList<Integer> allocations = algorithm.fitProcess(blockSizes, processSizes);

        // Print the memory allocation results
        System.out.println("Memory Allocation Results:");
        for (int i = 0; i < allocations.size(); i++) {
            if (allocations.get(i) != NO_ALLOCATION) {
                System.out.printf("Process %d -> Block %d\n", i, allocations.get(i));
            } else {
                System.out.printf("Process %d -> No Allocation\n", i);
            }
        }

        // Close the Scanner object
        scanner.close();
    }
}

// BestFitCPU class for the Best Fit algorithm
class BestFitCPU extends Main {
    // Find the index of the block with the best fit for the given process size
    private static int findBestFit(int[] blockSizes, int processSize) {
        int minDiff = Integer.MAX_VALUE;
        int index = NO_ALLOCATION;
        for (int i = 0; i < blockSizes.length; i++) {
            if (blockSizes[i] >= processSize && blockSizes[i] - processSize < minDiff) {
                minDiff = blockSizes[i] - processSize;
                index = i;
            }
        }
        return index;
    }

    // Override the fitProcess method to implement the Best Fit algorithm
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>();
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findBestFit(sizeOfBlocks, processSize);
            memAlloc.add(chosenBlockIdx);
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc;
    }
}

// WorstFitCPU class for the Worst Fit algorithm
class WorstFitCPU extends Main {
    // Find the index of the block with the worst fit for the given process size
    private static int findWorstFit(int[] blockSizes, int processSize) {
        int max = -1;
        int index = NO_ALLOCATION;
        for (int i = 0; i < blockSizes.length; i++) {
            if (blockSizes[i] >= processSize && blockSizes[i] > max) {
                max = blockSizes[i];
                index = i;
            }
        }
        return index;
    }

    // Override the fitProcess method to implement the Worst Fit algorithm
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>();
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findWorstFit(sizeOfBlocks, processSize);
            memAlloc.add(chosenBlockIdx);
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc;
    }
}

// FirstFitCPU class for the First Fit algorithm
class FirstFitCPU extends Main {
    // Find the index of the first available block for the given process size
    private static int findFirstFit(int[] blockSizes, int processSize) {
        for (int i = 0; i < blockSizes.length; i++) {
            if (blockSizes[i] >= processSize) {
                return i;
            }
        }
        return NO_ALLOCATION;
    }

    // Override the fitProcess method to implement the First Fit algorithm
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>();
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findFirstFit(sizeOfBlocks, processSize);
            memAlloc.add(chosenBlockIdx);
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc;
    }
}

// NextFit class for the Next Fit algorithm
class NextFit extends Main {
    // Counter variable to keep track of the index in the blockSizes array
    private int counter = 0;

    // Find the index of the next available block for the given process size
    private int findNextFit(int[] blockSizes, int processSize) {
        int idx = (counter + 1) % blockSizes.length;
        while (idx < blockSizes.length) {
            if (blockSizes[idx] >= processSize) {
                counter = idx;
                return idx;
            }
            idx++;
        }
        return NO_ALLOCATION;
    }

    // Override the fitProcess method to implement the Next Fit algorithm
    @Override
    public ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses) {
        ArrayList<Integer> memAlloc = new ArrayList<>();
        for (int processSize : sizeOfProcesses) {
            int chosenBlockIdx = findNextFit(sizeOfBlocks, processSize);
            memAlloc.add(chosenBlockIdx);
            if (chosenBlockIdx != NO_ALLOCATION) {
                sizeOfBlocks[chosenBlockIdx] -= processSize;
            }
        }
        return memAlloc;
    }
}