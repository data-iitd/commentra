
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to calculate the need matrix for each process
    static void calculateNeed(int[][] needArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        for (int i = 0; i < totalProcess; i++) {
            for (int j = 0; j < totalResources; j++) {
                needArray[i][j] = maxArray[i][j] - allocationArray[i][j];
            }
        }
    }

    // Method to check if the system is in a safe state
    static boolean checkSafeSystem(int[] processes, int[] availableArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        // Initialize the need array
        int[][] needArray = new int[totalProcess][totalResources];
        calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources);

        // Array to keep track of finished processes
        boolean[] finishProcesses = new boolean[totalProcess];

        // Array to store the safe sequence
        int[] safeSequenceArray = new int[totalProcess];

        // Array to represent the available resources
        int[] workArray = new int[totalResources];
        System.arraycopy(availableArray, 0, workArray, 0, totalResources);

        // Counter for the number of processes that have been processed
        int count = 0;

        // Loop until all processes are processed
        while (count < totalProcess) {
            boolean foundSafeSystem = false;
            for (int m = 0; m < totalProcess; m++) {
                if (!finishProcesses[m]) {
                    int j;
                    for (j = 0; j < totalResources; j++) {
                        if (needArray[m][j] > workArray[j]) {
                            break;
                        }
                    }
                    if (j == totalResources) {
                        for (int k = 0; k < totalResources; k++) {
                            workArray[k] += allocationArray[m][k];
                        }
                        safeSequenceArray[count++] = m;
                        finishProcesses[m] = true;
                        foundSafeSystem = true;
                    }
                }
            }
            if (!foundSafeSystem) {
                System.out.println("The system is not in a safe state due to insufficient resources.");
                return false;
            }
        }
        System.out.print("The system is in a safe state. Safe sequence: ");
        for (int i = 0; i < totalProcess; i++) {
            System.out.print("P" + safeSequenceArray[i] + " ");
        }
        System.out.println();
        return true;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfProcesses = sc.nextInt();
        int numberOfResources = sc.nextInt();

        // Array to store process IDs
        int[] processes = new int[numberOfProcesses];
        for (int i = 0; i < numberOfProcesses; i++) {
            processes[i] = i;
        }

        // Array to store the available resources
        int[] availableArray = new int[numberOfResources];
        for (int i = 0; i < numberOfResources; i++) {
            availableArray[i] = sc.nextInt();
        }

        // Matrix to store the maximum resource requirements for each process
        int[][] maxArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                maxArray[i][j] = sc.nextInt();
            }
        }

        // Matrix to store the current resource allocations for each process
        int[][] allocationArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                allocationArray[i][j] = sc.nextInt();
            }
        }

        // Check if the system is in a safe state and print the result
        checkSafeSystem(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources);
        sc.close();
    }
}
