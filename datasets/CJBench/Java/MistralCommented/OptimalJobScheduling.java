
import java.util.Scanner;

public class Main {
    // Declare instance variables
    private final int numberProcesses;
    private final int numberMachines;
    private final int[][] run;
    private final int[][] transfer;
    private final int[][] cost;

    // Constructor
    public Main(int numberProcesses, int numberMachines, int[][] run, int[][] transfer) {
        this.numberProcesses = numberProcesses;
        this.numberMachines = numberMachines;
        this.run = run;
        this.transfer = transfer;
        this.cost = new int[numberProcesses][numberMachines];
    }

    // Method to execute the scheduling algorithm
    public void execute() {
        calculateCost();
        showResults();
    }

    // Method to calculate the cost of each process on each machine
    private void calculateCost() {
        for (int process = 0; process < numberProcesses; process++) { // Iterate through all processes
            for (int machine = 0; machine < numberMachines; machine++) { // Iterate through all machines
                cost[process][machine] = runningCost(process, machine);
            }
        }
    }

    // Method to calculate the cost of a single process on a machine
    private int runningCost(int process, int machine) {
        if (process == 0) { // Base case: no previous process
            return run[process][machine];
        } else { // Recursive case: there is a previous process
            int[] runningCosts = new int[numberMachines]; // Initialize an array to store the running costs of the next machine for each machine

            for (int nextMachine = 0; nextMachine < numberMachines; nextMachine++) { // Iterate through all machines
                runningCosts[nextMachine] = cost[process - 1][nextMachine] + transfer[nextMachine][machine] + run[process][machine]; // Calculate the running cost of the next machine
            }

            return findMin(runningCosts); // Find the minimum running cost among all machines
        }
    }

    // Method to find the minimum value in an array
    private int findMin(int[] costArr) {
        int min = 0;
        for (int i = 1; i < costArr.length; i++) {
            if (costArr[i] < costArr[min]) {
                min = i;
            }
        }
        return costArr[min];
    }

    // Method to show the results
    private void showResults() {
        for (int process = 0; process < numberProcesses; process++) { // Iterate through all processes
            for (int machine = 0; machine < numberMachines; machine++) { // Iterate through all machines
                System.out.print(cost[process][machine]); // Print the cost
                System.out.print(" "); // Print a space
            }
            System.out.println(); // Move to the next line after printing the costs of a process
        }
        System.out.println(); // Print an empty line after printing all costs
    }

    // Method to get the cost of a specific process and machine
    public int getCost(int process, int machine) {
        return cost[process][machine];
    }

    // Main method to read input and start the scheduling algorithm
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner to read input

        int numberProcesses = scanner.nextInt(); // Read the number of processes
        int numberMachines = scanner.nextInt(); // Read the number of machines

        int[][] run = new int[numberProcesses][numberMachines]; // Initialize a 2D array to store the run data
        for (int process = 0; process < numberProcesses; process++) { // Iterate through all processes
            for (int machine = 0; machine < numberMachines; machine++) { // Iterate through all machines
                run[process][machine] = scanner.nextInt(); // Read and store the run data
            }
        }

        int[][] transfer = new int[numberMachines][numberMachines]; // Initialize a 2D array to store the transfer data
        for (int machine1 = 0; machine1 < numberMachines; machine1++) { // Iterate through all machines
            for (int machine2 = 0; machine2 < numberMachines; machine2++) { // Iterate through all machines
                transfer[machine1][machine2] = scanner.nextInt(); // Read and store the transfer data
            }
        }

        Main scheduler = new Main(numberProcesses, numberMachines, run, transfer); // Create a new instance of the Main class with the input data
        scheduler.execute(); // Execute the scheduling algorithm

        scanner.close(); // Close the Scanner
    }
}