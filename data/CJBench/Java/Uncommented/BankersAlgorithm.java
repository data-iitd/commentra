
import java.util.Scanner;
public final class BankersAlgorithm {
    private BankersAlgorithm() {
    }
    static void calculateNeed(int[][] needArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        for (int i = 0; i < totalProcess; i++) {
            for (int j = 0; j < totalResources; j++) {
                needArray[i][j] = maxArray[i][j] - allocationArray[i][j];
            }
        }
    }
    static boolean checkSafeSystem(int[] processes, int[] availableArray, int[][] maxArray, int[][] allocationArray, int totalProcess, int totalResources) {
        int[][] needArray = new int[totalProcess][totalResources];
        calculateNeed(needArray, maxArray, allocationArray, totalProcess, totalResources);
        boolean[] finishProcesses = new boolean[totalProcess];
        int[] safeSequenceArray = new int[totalProcess];
        int[] workArray = new int[totalResources];
        System.arraycopy(availableArray, 0, workArray, 0, totalResources);
        int count = 0;
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
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfProcesses = sc.nextInt();
        int numberOfResources = sc.nextInt();
        int[] processes = new int[numberOfProcesses];
        for (int i = 0; i < numberOfProcesses; i++) {
            processes[i] = i;
        }
        int[] availableArray = new int[numberOfResources];
        for (int i = 0; i < numberOfResources; i++) {
            availableArray[i] = sc.nextInt();
        }
        int[][] maxArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                maxArray[i][j] = sc.nextInt();
            }
        }
        int[][] allocationArray = new int[numberOfProcesses][numberOfResources];
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = 0; j < numberOfResources; j++) {
                allocationArray[i][j] = sc.nextInt();
            }
        }
        checkSafeSystem(processes, availableArray, maxArray, allocationArray, numberOfProcesses, numberOfResources);
        sc.close();
    }
}
