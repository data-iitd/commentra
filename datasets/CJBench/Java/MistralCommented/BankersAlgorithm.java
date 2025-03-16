
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    static void calculateNeed(int[][] needArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        // Calculate the need matrix by subtracting the allocation matrix from the maximum matrix
        for (int i = 0; i < totalProcess; i++) {
            for (int j = 0; j < totalResources; j++) {
                needArray[i][j] = maxArray[i][j] - allocationArray[i][j];
                // Update the need matrix element for the current process and resource
            }
        }
        // Set all process finishing status to false initially
    }

    static boolean checkSafeSystem(int[] processes, int[] availableArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        int[][] needArray = new int[totalProcess][totalResources];
        // Initialize the need matrix
        calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources);
        boolean[] finishProcesses = new boolean[totalProcess];
        // Initialize the finish processes array with false values
        int[] safeSequenceArray = new int[totalProcess];
        // Initialize the safe sequence array
        int[] workArray = new int[totalResources];
        // Initialize the work array with the available resources
        System.arraycopy(availableArray, 0, workArray, 0, totalResources);
        int count = 0;
        // Initialize the safe sequence counter
        while (count < totalProcess) {
            boolean foundSafeSystem = false;
            // Initialize the foundSafeSystem flag
            for (int m = 0; m < totalProcess; m++) {
                if (!finishProcesses[m]) {
                    int j;
                    // Initialize the j index
                    for (j = 0; j < totalResources; j++) {
                        if (needArray[m][j] > workArray[j]) {
                            // If the current process needs more resources than available, break the inner loop
                            break;
                        }
                    }
                    if (j == totalResources) {
                        // If the current process can be executed safely, update the work array and safe sequence array
                        for (int k = 0; k < totalResources; k++) {
                            workArray[k] += allocationArray[m][k];
                        }
                        safeSequenceArray[count++] = m;
                        finishProcesses[m] = true;
                        foundSafeSystem = true;
                        // Update the finishProcesses array for the current process
                    }
                }
            }
            if (!foundSafeSystem) {
                // If no safe sequence is found, print the error message and return false
                System.out.println("The system is not in a safe state due to insufficient resources.");
                return false;
            }
        }
        // If a safe sequence is found, print the safe sequence message and return true
        System.out.print("The system is in a safe state. Safe sequence: ");
        for (int i = 0; i < totalProcess; i++) {
            System.out.print("P" + safeSequenceArray[i] + " ");
        }
        System.out.println();
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Initialize the scanner object to read input from the console
        int numberOfProcesses = sc.nextInt();
        // Read the number of processes from the console
        int numberOfResources = sc.nextInt();
        // Read the number of resources from the console
        int[] processes = new int[numberOfProcesses];
        // Initialize the processes array
        for (int i = 0; i < numberOfProcesses; i++) {
            processes[i] = i;
            // Assign each process an index
        }
        int[] availableArray = new int[numberOfResources];
        // Initialize the available resources array
        for (int i = 0; i < numberOfResources; i++) {
            availableArray[i] = sc.nextInt();
            // Read the available resources for each resource from the console
        }
        int[][] maxArray = new int[numberOfProcesses][numberOfResources];
        // Initialize the maximum resources array
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                maxArray[i][j] = sc.nextInt();
                // Read the maximum resources for each process and resource from the console
            }
        }
        int[][] allocationArray = new int[numberOfProcesses][numberOfResources];
        // Initialize the allocation resources array
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                allocationArray[i][j] = sc.nextInt();
                // Read the allocated resources for each process and resource from the console
            }
        }
        checkSafeSystem(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources);
        // Call the checkSafeSystem method with the given input parameters
        sc.close();
        // Close the scanner object
    }
}