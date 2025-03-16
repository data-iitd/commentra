import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

// The Main class is defined as final, ensuring it cannot be extended by other classes.
public final class Main {
    // Variable to store the total number of tasks.
    private final int totalTasks;
    // 2D array used for dynamic programming to store the number of ways to assign tasks.
    private final int[][] dp;
    // List of lists to store the tasks each person can perform.
    private final List<List<Integer>> task;
    // Integer representing the final mask used to check if all tasks are assigned.
    private final int finalMask;

    // Constructor to initialize the class variables.
    public Main(List<List<Integer>> taskPerformed, int total) {
        this.totalTasks = total;
        this.dp = new int[1 << taskPerformed.size()][total + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1); // Initialize the dp array with -1 to indicate unvisited states.
        }
        this.task = new ArrayList<>(totalTasks + 1);
        for (int i = 0; i <= totalTasks; i++) {
            this.task.add(new ArrayList<>()); // Initialize the task list with empty lists for each task.
        }
        this.finalMask = (1 << taskPerformed.size()) - 1; // Calculate the final mask.
        for (int i = 0; i < taskPerformed.size(); i++) {
            for (int j : taskPerformed.get(i)) {
                this.task.get(j).add(i); // Populate the task list with the tasks each person can perform.
            }
        }
    }

    // Recursively counts the number of ways to assign tasks using dynamic programming.
    private int countWaysUntil(int mask, int taskNo) {
        if (mask == finalMask) { // If all tasks are assigned, return 1.
            return 1;
        }
        if (taskNo > totalTasks) { // If all tasks are considered, return 0.
            return 0;
        }
        if (dp[mask][taskNo] != -1) { // If the state is already computed, return the stored value.
            return dp[mask][taskNo];
        }
        int totalWays = countWaysUntil(mask, taskNo + 1); // Skip the current task.
        for (int p : task.get(taskNo)) {
            if ((mask & (1 << p)) != 0) { // If the task is already assigned, skip it.
                continue;
            }
            totalWays += countWaysUntil(mask | (1 << p), taskNo + 1); // Assign the task to someone.
        }
        dp[mask][taskNo] = totalWays; // Store the computed value in dp array.
        return dp[mask][taskNo];
    }

    // Calls the recursive method to count the number of ways to assign tasks starting with an empty mask and task number 1.
    public int countNoOfWays() {
        return countWaysUntil(0, 1);
    }

    // Main method to read input, create an instance of Main, and print the total number of ways to assign tasks.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int persons = scanner.nextInt();
        int tasks = scanner.nextInt();
        List<List<Integer>> taskPerformed = new ArrayList<>();
        for (int i = 0; i < persons; i++) {
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
        Main assignment = new Main(taskPerformed, tasks);
        int result = assignment.countNoOfWays();
        System.out.println("Total number of ways to assign tasks: " + result);
        scanner.close();
    }
}
