import java.util.Scanner;

public class Main {
    // Number of processes and machines
    private final int numberProcesses;
    private final int numberMachines;
    
    // Arrays to hold running costs, transfer costs, and total costs
    private final int[][] run;
    private final int[][] transfer;
    private final int[][] cost;

    // Constructor to initialize the number of processes, machines, and cost matrices
    public Main(int numberProcesses, int numberMachines, int[][] run, int[][] transfer) {
        this.numberProcesses = numberProcesses;
        this.numberMachines = numberMachines;
        this.run = run;
        this.transfer = transfer;
        this.cost = new int[numberProcesses][numberMachines]; // Initialize cost matrix
    }

    // Method to execute the cost calculation and display results
    public void execute() {
        this.calculateCost(); // Calculate the costs for each process and machine
        this.showResults();    // Display the calculated costs
    }

    // Method to calculate the total cost for each process on each machine
    private void calculateCost() {
        // Iterate over each process
        for (int i = 0; i < numberProcesses; i++) { 
            // Iterate over each machine
            for (int j = 0; j < numberMachines; j++) { 
                // Calculate the running cost for the current process and machine
                cost[i][j] = runningCost(i, j);
            }
        }
    }

    // Method to calculate the running cost for a specific process on a specific machine
    private int runningCost(int process, int machine) {
        // If it's the first process, return the running cost directly
        if (process == 0) { 
            return run[process][machine];
        } else {
            // Array to hold the running costs for the previous process on all machines
            int[] runningCosts = new int[numberMachines]; 
            // Calculate the cost for the current process on each machine
            for (int k = 0; k < numberMachines; k++) { 
                runningCosts[k] = cost[process - 1][k] + transfer[k][machine] + run[process][machine]; 
            }
            // Return the minimum cost calculated
            return findMin(runningCosts); 
        }
    }

    // Method to find the minimum value in an array of costs
    private int findMin(int[] costArr) {
        int min = 0; // Initialize minimum index
        // Iterate through the array to find the index of the minimum cost
        for (int i = 1; i < costArr.length; i++) {
            if (costArr[i] < costArr[min]) {
                min = i; // Update minimum index if a lower cost is found
            }
        }
        return costArr[min]; // Return the minimum cost
    }

    // Method to display the calculated costs for each process and machine
    private void showResults() {
        // Iterate over each process
        for (int i = 0; i < numberProcesses; i++) {
            // Iterate over each machine
            for (int j = 0; j < numberMachines; j++) {
                System.out.print(cost[i][j]); // Print the cost
                System.out.print(" "); // Print space for formatting
            }
            System.out.println(); // Move to the next line after each process
        }
        System.out.println(); // Print an extra line for better readability
    }

    // Method to get the cost for a specific process and machine
    public int getCost(int process, int machine) {
        return cost[process][machine]; // Return the cost from the cost matrix
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        // Read the number of processes and machines
        int numberProcesses = scanner.nextInt();
        int numberMachines = scanner.nextInt();
        
        // Initialize the running cost matrix
        int[][] run = new int[numberProcesses][numberMachines];
        // Read the running costs from input
        for (int i = 0; i < numberProcesses; i++) {
            for (int j = 0; j < numberMachines; j++) {
                run[i][j] = scanner.nextInt();
            }
        }
        
        // Initialize the transfer cost matrix
        int[][] transfer = new int[numberMachines][numberMachines];
        // Read the transfer costs from input
        for (int i = 0; i < numberMachines; i++) {
            for (int j = 0; j < numberMachines; j++) {
                transfer[i][j] = scanner.nextInt();
            }
        }
        
        // Create an instance of Main with the input data
        Main scheduler = new Main(numberProcesses, numberMachines, run, transfer);
        scheduler.execute(); // Execute the cost calculation and display
        scanner.close(); // Close the scanner
    }
}
