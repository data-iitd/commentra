
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // Read the number of dishes
        int T = sc.nextInt(); // Read the time limit for eating dishes

        // Initialize the array to store dishes with their time and value
        int[][] AB = new int[N][2];
        for (int i = 0; i < N; i++) {
            AB[i][0] = sc.nextInt(); // Read the time for each dish
            AB[i][1] = sc.nextInt(); // Read the value for each dish
        }

        // Sort the dishes based on their eating time
        Arrays.sort(AB, Comparator.comparingInt(a -> a[0]));

        // Initialize the DP table with dimensions (N+1) x 6001
        int[][] dp = new int[N + 1][6001];

        // Fill the DP table
        for (int i = 1; i <= N; i++) {
            for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
                // Inherit the maximum value from the previous dish
                dp[i][timeAfterEat] = Math.max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);

                // Get the time and value of the current dish
                int time = AB[i - 1][0];
                int value = AB[i - 1][1];

                // If the dish can be eaten after the given time, update the DP table
                if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                    dp[i][timeAfterEat] = Math.max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
                }
            }
        }

        // Print the maximum value that can be obtained within the time limit
        System.out.println(Arrays.stream(dp[N]).max().getAsInt());
    }
}

