
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Declare instance variables
    private final int totalTasks;
    private final int[][] dp;
    private final List<List<Integer>> task;
    private final int finalMask;

    // Constructor
    public Main(List<List<Integer>> taskPerformed, int total) {
        // Initialize instance variables
        this.totalTasks = total;
        this.dp = new int[1 << taskPerformed.size()][total + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1); // Initialize dp matrix with -1
        }
        this.task = new ArrayList<>(totalTasks + 1);
        for (int i = 0; i <= totalTasks; i++) {
            this.task.add(new ArrayList<>()); // Initialize task list with empty list
        }
        this.finalMask = (1 << taskPerformed.size()) - 1; // Calculate finalMask
        for (int i = 0; i < taskPerformed.size(); i++) {
            for (int j : taskPerformed.get(i)) {
                this.task.get(j).add(i); // Add index of task i to the list of tasks that can be performed by person j
            }
        }
    }

    // Recursive helper method to count ways to reach current state
    private int countWaysUntil(int mask, int taskNo) {
        // Base case: if mask represents all tasks performed, return 1
        if (mask == finalMask) {
            return 1;
        }
        // Base case: if taskNo exceeds total number of tasks, return 0
        if (taskNo > totalTasks) {
            return 0;
        }
        // Memoization: if dp[mask][taskNo] is already calculated, return it
        if (dp[mask][taskNo] != -1) {
            return dp[mask][taskNo];
        }
        // Recursive call: count ways to reach next state
        int totalWays = 0;
        for (int p : task.get(taskNo)) {
            if ((mask & (1 << p)) != 0) { // Skip if task p is already performed
                continue;
            }
            totalWays += countWaysUntil(mask | (1 << p), taskNo + 1); // Recursively call with next state
        }
        // Memoization: store the result in dp[mask][taskNo] and return it
        dp[mask][taskNo] = totalWays;
        return dp[mask][taskNo];
    }

    // Method to count total number of ways to assign tasks
    public int countNoOfWays() {
        return countWaysUntil(0, 1);
    }

    // Main method to read input and call countNoOfWays()
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int persons = scanner.nextInt(); // Read number of persons
        int tasks = scanner.nextInt(); // Read number of tasks
        List<List<Integer>> taskPerformed = new ArrayList<>(); // Initialize taskPerformed list
        for (int i = 0; i < persons; i++) { // Read tasks performed by each person
            List<Integer> taskList = new ArrayList<>();
            while (true) {
                int task = scanner.nextInt();
                if (task == -1) {
                    break;
                }
                taskList.add(task);
            }
            taskPerformed.add(taskList);
        }
        Main assignment = new Main(taskPerformed, tasks); // Create Main object with given input
        int result = assignment.countNoOfWays(); // Call countNoOfWays() and store result in result
        System.out.println("Total number of ways to assign tasks: " + result); // Print result
        scanner.close(); // Close scanner
    }
}