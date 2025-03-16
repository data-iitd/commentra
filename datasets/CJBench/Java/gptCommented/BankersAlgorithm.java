import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to calculate the need matrix based on max and allocation matrices
    static void calculateNeed(int[][] needArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        // Iterate through each process and resource to calculate the need
        for (int i = 0; i < totalProcess; i++) {
            for (int j = 0; j < totalResources; j++) {
                // Need is calculated as maximum demand minus current allocation
                needArray[i][j] = maxArray[i][j] - allocationArray[i][j];
            }
        }
    }

    // Method to check if the system is in a safe state
    static boolean checkSafeSystem(int[] processes, int[] availableArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        // Create a need array to hold the remaining resource needs for each process
        int[][] needArray = new int[totalProcess][totalResources];
        // Calculate the need for each process
        calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources);
        
        // Array to track which processes have finished
        boolean[] finishProcesses = new boolean[totalProcess];
        // Array to store the safe sequence of processes
        int[] safeSequenceArray = new int[totalProcess];
        // Work array to keep track of available resources
        int[] workArray = new int[totalResources];
        // Initialize work array with available resources
        System.arraycopy(availableArray, 0, workArray, 0, totalResources);
        
        int count = 0; // Count of processes that have finished
        // Loop until all processes are finished
        while (count < totalProcess) {
            boolean foundSafeSystem = false; // Flag to check if a safe process was found
            // Check each process to see if it can finish
            for (int m = 0; m < totalProcess; m++) {
                // If the process has not finished yet
                if (!finishProcesses[m]) {
                    int j;
                    // Check if the process can be satisfied with the current work array
                    for (j = 0; j < totalResources; j++) {
                        if (needArray[m][j] > workArray[j]) {
                            break; // Process cannot be satisfied
                        }
                    }
                    // If all resource needs are satisfied
                    if (j == totalResources) {
                        // Simulate the allocation of resources to the process
                        for (int k = 0; k < totalResources; k++) {
                            workArray[k] += allocationArray[m][k];
                        }
                        // Add the process to the safe sequence
                        safeSequenceArray[count++] = m;
                        finishProcesses[m] = true; // Mark process as finished
                        foundSafeSystem = true; // A safe process was found
                    }
                }
            }
            // If no process could be found to finish, the system is not in a safe state
            if (!foundSafeSystem) {
                System.out.println("The system is not in a safe state due to insufficient resources.");
                return false; // Return false indicating unsafe state
            }
        }
        // If the system is in a safe state, print the safe sequence
        System.out.print("The system is in a safe state. Safe sequence: ");
        for (int i = 0; i < totalProcess; i++) {
            System.out.print("P" + safeSequenceArray[i] + " "); // Print each process in the safe sequence
        }
        System.out.println(); // New line after printing the safe sequence
        return true; // Return true indicating safe state
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input
        // Read the number of processes and resources
        int numberOfProcesses = sc.nextInt();
        int numberOfResources = sc.nextInt();
        
        // Initialize the processes array
        int[] processes = new int[numberOfProcesses];
        for (int i = 0; i < numberOfProcesses; i++) {
            processes[i] = i; // Assign process IDs
        }
        
        // Initialize the available resources array
        int[] availableArray = new int[numberOfResources];
        for (int i = 0; i < numberOfResources; i++) {
            availableArray[i] = sc.nextInt(); // Read available resources
        }
        
        // Initialize the maximum resources array for each process
        int[][] maxArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                maxArray[i][j] = sc.nextInt(); // Read maximum resources needed by each process
            }
        }
        
        // Initialize the allocation array for each process
        int[][] allocationArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                allocationArray[i][j] = sc.nextInt(); // Read currently allocated resources for each process
            }
        }
        
        // Check if the system is in a safe state
        checkSafeSystem(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources);
        sc.close(); // Close the scanner
    }
}
