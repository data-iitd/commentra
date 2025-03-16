
import java.util.Scanner;

/**
 * This file contains an implementation of BANKER'S ALGORITHM Wikipedia:
 * https://en.wikipedia.org/wiki/Banker%27s_algorithm
 *
 * The algorithm for finding out whether or not a system is in a safe state can
 * be described as follows:
 * 1. Let Work and Finish be vectors of length ‘m’ and ‘n’ respectively. Initialize:
 *    Work = Available
 *    Finish[i] = false; for i = 1, 2, ..., n
 * 2. Find an i such that both
 *    a) Finish[i] = false
 *    b) Need_i <= Work
 *
 *    If no such i exists, go to step (4).
 * 3. Work = Work + Allocation_i
 *    Finish[i] = true
 *    Go to step (2).
 * 4. If Finish[i] = true for all i, then the system is in a safe state.
 *
 * Time Complexity: O(n*n*m)
 * Space Complexity: O(n*m)
 * where n = number of processes and m = number of resources.
 */
public final class BankersAlgorithm {
    private BankersAlgorithm() {
    }

    /**
     * This method calculates the need matrix for each process.
     */
    static void calculateNeed(int[][] needArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        for (int i = 0; i < totalProcess; i++) {
            for (int j = 0; j < totalResources; j++) {
                needArray[i][j] = maxArray[i][j] - allocationArray[i][j];
            }
        }
    }

    /**
     * This method checks if the system is in a safe state.
     */
    static boolean checkSafeSystem(int[] processes, int[] availableArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        int[][] needArray = new int[totalProcess][totalResources];

        calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources);

        boolean[] finishProcesses = new boolean[totalProcess];

        int[] safeSequenceArray = new int[totalProcess];

        int[] workArray = new int[totalResources];
        System.arraycopy(availableArray, 0, workArray, 0, totalResources);

        int count = 0;

        // While all processes are not finished or system is not in a safe state.
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

            // If we could not find a next process in the safe sequence.
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

    /**
     * Main method for executing the Banker's Algorithm.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of processes and resources
        int numberOfProcesses = sc.nextInt();
        int numberOfResources = sc.nextInt();

        int[] processes = new int[numberOfProcesses];
        for (int i = 0; i < numberOfProcesses; i++) {
            processes[i] = i;
        }

        // Input availability of resources
        int[] availableArray = new int[numberOfResources];
        for (int i = 0; i < numberOfResources; i++) {
            availableArray[i] = sc.nextInt();
        }

        // Input maximum resource matrix
        int[][] maxArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                maxArray[i][j] = sc.nextInt();
            }
        }

        // Input allocation matrix
        int[][] allocationArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                allocationArray[i][j] = sc.nextInt();
            }
        }

        // Check if the system is in a safe state.
        checkSafeSystem(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources);

        sc.close();
    }
}
