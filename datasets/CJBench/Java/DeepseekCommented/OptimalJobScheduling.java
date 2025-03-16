import java.util.Scanner;
public class Main {
    private final int numberProcesses; // Number of processes
    private final int numberMachines; // Number of machines
    private final int[][] run; // Running cost matrix
    private final int[][] transfer; // Transfer cost matrix
    private final int[][] cost; // Cost matrix to store the calculated costs

    // Constructor to initialize the class variables
    public Main(int numberProcesses, int numberMachines, int[][] run, int[][] transfer) {
        this.numberProcesses = numberProcesses;
        this.numberMachines = numberMachines;
        this.run = run;
        this.transfer = transfer;
        this.cost = new int[numberProcesses][numberMachines]; // Initialize cost matrix
    }

    // Main method to execute the scheduling algorithm
    public void execute() {
        this.calculateCost(); // Calculate the cost for each process and machine
        this.showResults(); // Display the calculated costs
    }

    // Method to calculate the cost for each process and machine
    private void calculateCost() {
        for (int i = 0; i < numberProcesses; i++) { 
            for (int j = 0; j < numberMachines; j++) { 
                cost[i][j] = runningCost(i, j); // Calculate cost for each process and machine
            }
        }
    }

    // Method to calculate the running cost of a process on a machine
    private int runningCost(int process, int machine) {
        if (process == 0) { 
            return run[process][machine]; // Base case: cost is the running cost of the first process
        } else {
            int[] runningCosts = new int[numberMachines]; 
            for (int k = 0; k < numberMachines; k++) { 
                runningCosts[k] = cost[process - 1][k] + transfer[k][machine] + run[process][machine]; 
            }
            return findMin(runningCosts); // Find the minimum cost among all machines
        }
    }

    // Method to find the minimum cost from an array of costs
    private int findMin(int[] costArr) {
        int min = 0;
        for (int i = 1; i < costArr.length; i++) {
            if (costArr[i] < costArr[min]) {
                min = i;
            }
        }
        return costArr[min];
    }

    // Method to display the calculated costs
    private void showResults() {
        for (int i = 0; i < numberProcesses; i++) {
            for (int j = 0; j < numberMachines; j++) {
                System.out.print(cost[i][j]); // Print the cost
                System.out.print(" "); // Space between costs
            }
            System.out.println(); // New line after each process's costs
        }
        System.out.println(); // New line after all costs
    }

    // Method to get the cost of a specific process on a specific machine
    public int getCost(int process, int machine) {
        return cost[process][machine];
    }

    // Main method to read input and execute the scheduling algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberProcesses = scanner.nextInt(); // Read number of processes
        int numberMachines = scanner.nextInt(); // Read number of machines
        int[][] run = new int[numberProcesses][numberMachines];
        for (int i = 0; i < numberProcesses; i++) {
            for (int j = 0; j < numberMachines; j++) {
                run[i][j] = scanner.nextInt(); // Read running cost matrix
            }
        }
        int[][] transfer = new int[numberMachines][numberMachines];
        for (int i = 0; i < numberMachines; i++) {
            for (int j = 0; j < numberMachines; j++) {
                transfer[i][j] = scanner.nextInt(); // Read transfer cost matrix
            }
        }
        Main scheduler = new Main(numberProcesses, numberMachines, run, transfer);
        scheduler.execute(); // Execute the scheduling algorithm
        scanner.close(); // Close the scanner
    }
}
