import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Total number of tasks to be assigned
    private final int totalTasks;
    // Dynamic programming table to store results of subproblems
    private final int[][] dp;
    // List to hold the tasks that can be performed by each person
    private final List<List<Integer>> task;
    // Final mask representing all tasks have been assigned
    private final int finalMask;

    // Constructor to initialize the Main class with tasks performed by persons and total tasks
    public Main(List<List<Integer>> taskPerformed, int total) {
        this.totalTasks = total;
        // Initialize dp array with size based on number of persons and total tasks
        this.dp = new int[1 << taskPerformed.size()][total + 1];
        // Fill dp array with -1 to indicate uncomputed states
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        // Initialize task list to hold tasks for each person
        this.task = new ArrayList<>(totalTasks + 1);
        for (int i = 0; i <= totalTasks; i++) {
            this.task.add(new ArrayList<>());
        }
        // Calculate the final mask representing all tasks assigned
        this.finalMask = (1 << taskPerformed.size()) - 1;
        // Populate the task list with tasks each person can perform
        for (int i = 0; i < taskPerformed.size(); i++) {
            for (int j : taskPerformed.get(i)) {
                this.task.get(j).add(i);
            }
        }
    }

    // Recursive method to count the number of ways to assign tasks
    private int countWaysUntil(int mask, int taskNo) {
        // Base case: if all tasks are assigned, return 1
        if (mask == finalMask) {
            return 1;
        }
        // Base case: if all tasks have been considered, return 0
        if (taskNo > totalTasks) {
            return 0;
        }
        // Return the cached result if already computed
        if (dp[mask][taskNo] != -1) {
            return dp[mask][taskNo];
        }
        // Count ways without assigning the current task
        int totalWays = countWaysUntil(mask, taskNo + 1);
        // Iterate through all persons who can perform the current task
        for (int p : task.get(taskNo)) {
            // Skip if the person has already been assigned a task
            if ((mask & (1 << p)) != 0) {
                continue;
            }
            // Count ways by assigning the current task to the person
            totalWays += countWaysUntil(mask | (1 << p), taskNo + 1);
        }
        // Store the computed result in dp table
        dp[mask][taskNo] = totalWays;
        return dp[mask][taskNo];
    }

    // Public method to initiate the counting of ways to assign tasks
    public int countNoOfWays() {
        return countWaysUntil(0, 1);
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of persons and tasks
        int persons = scanner.nextInt();
        int tasks = scanner.nextInt();
        // Initialize list to hold tasks performed by each person
        List<List<Integer>> taskPerformed = new ArrayList<>();
        // Read tasks performed by each person
        for (int i = 0; i < persons; i++) {
            List<Integer> taskList = new ArrayList<>();
            while (true) {
                int task = scanner.nextInt();
                // Break if the input task is -1
                if (task == -1) {
                    break;
                }
                taskList.add(task);
            }
            taskPerformed.add(taskList);
        }
        // Create an instance of Main with the tasks performed and total tasks
        Main assignment = new Main(taskPerformed, tasks);
        // Count the number of ways to assign tasks
        int result = assignment.countNoOfWays();
        // Output the result
        System.out.println("Total number of ways to assign tasks: " + result);
        // Close the scanner to free resources
        scanner.close();
    }
}
