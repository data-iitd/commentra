import java.util.ArrayList;
import java.util.Scanner;

public abstract class Main {
    public abstract ArrayList<Integer> fitProcess(int[] sizeOfBlocks, int[] sizeOfProcesses);
    protected static final int NO_ALLOCATION = -255;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input Reading and Initialization
        int numBlocks = scanner.nextInt();
        int[] blockSizes = new int[numBlocks];
        for (int i = 0; i < numBlocks; i++) {
            blockSizes[i] = scanner.nextInt(); // Reads the size of each block
        }
        int numProcesses = scanner.nextInt();
        int[] processSizes = new int[numProcesses];
        for (int i = 0; i < numProcesses; i++) {
            processSizes[i] = scanner.nextInt(); // Reads the size of each process
        }
        
        // Algorithm Selection
        int choice = scanner.nextInt();
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
                System.out.println("Invalid choice.");
                scanner.close();
                return;
        }
        
        // Memory Allocation
        ArrayList<Integer> allocations = algorithm.fitProcess(blockSizes, processSizes);
        
        // Output Results
        System.out.println("Memory Allocation Results:");
        for (int i = 0; i < allocations.size(); i++) {
            if (allocations.get(i) != NO_ALLOCATION) {
                System.out.printf("Process %d -> Block %d\n", i, allocations.get(i));
            } else {
                System.out.printf("Process %d -> No Allocation\n", i);
            }
        }
        scanner.close();
    }
}

class BestFitCPU extends Main {
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

class WorstFitCPU extends Main {
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

class FirstFitCPU extends Main {
    private static int findFirstFit(int[] blockSizes, int processSize) {
        for (int i = 0; i < blockSizes.length; i++) {
            if (blockSizes[i] >= processSize) {
                return i;
            }
        }
        return NO_ALLOCATION;
    }
    
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

class NextFit extends Main {
    private int counter = 0;
    private int findNextFit(int[] blockSizes, int processSize) {
        for (int i = 0; i < blockSizes.length; i++) {
            int idx = (counter + i) % blockSizes.length;
            if (blockSizes[idx] >= processSize) {
                counter = idx;
                return idx;
            }
        }
        return NO_ALLOCATION;
    }
    
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
