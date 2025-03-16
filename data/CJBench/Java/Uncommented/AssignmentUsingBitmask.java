
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
public final class AssignmentUsingBitmask {
    private final int totalTasks;
    private final int[][] dp;
    private final List<List<Integer>> task;
    private final int finalMask;
    public AssignmentUsingBitmask(List<List<Integer>> taskPerformed, int total) {
        this.totalTasks = total;
        this.dp = new int[1 << taskPerformed.size()][total + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        this.task = new ArrayList<>(totalTasks + 1);
        for (int i = 0; i <= totalTasks; i++) {
            this.task.add(new ArrayList<>());
        }
        this.finalMask = (1 << taskPerformed.size()) - 1;
        for (int i = 0; i < taskPerformed.size(); i++) {
            for (int j : taskPerformed.get(i)) {
                this.task.get(j).add(i);
            }
        }
    }
    private int countWaysUntil(int mask, int taskNo) {
        if (mask == finalMask) {
            return 1;
        }
        if (taskNo > totalTasks) {
            return 0;
        }
        if (dp[mask][taskNo] != -1) {
            return dp[mask][taskNo];
        }
        int totalWays = countWaysUntil(mask, taskNo + 1);
        for (int p : task.get(taskNo)) {
            if ((mask & (1 << p)) != 0) {
                continue;
            }
            totalWays += countWaysUntil(mask | (1 << p), taskNo + 1);
        }
        dp[mask][taskNo] = totalWays;
        return dp[mask][taskNo];
    }
    public int countNoOfWays() {
        return countWaysUntil(0, 1);
    }
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
        AssignmentUsingBitmask assignment = new AssignmentUsingBitmask(taskPerformed, tasks);
        int result = assignment.countNoOfWays();
        System.out.println("Total number of ways to assign tasks: " + result);
        scanner.close();
    }
}