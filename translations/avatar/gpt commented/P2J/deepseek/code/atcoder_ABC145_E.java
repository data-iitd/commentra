import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int T = Integer.parseInt(input[1]);

        // Initialize a list to store time and value pairs, starting with a dummy entry
        List<int[]> timeValue = new ArrayList<>(Collections.nCopies(N + 1, new int[]{-1, -1}));

        // Read the time and value pairs for each item
        for (int i = 1; i <= N; i++) {
            int[] pair = Arrays.stream(reader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            timeValue.set(i, pair);
        }

        // Sort the time_value list based on the value (VAL)
        timeValue.sort(Comparator.comparingInt(a -> a[1]));

        // Initialize a 2D list for dynamic programming, with -1 as default values
        int[][] dp = new int[N + 1][T + 1];

        // Base case: If time is 0, the maximum value is 0 for all items
        for (int t = 0; t <= T; t++) {
            dp[0][t] = 0;
        }

        // Fill the dynamic programming table
        for (int n = 1; n <= N; n++) {
            // Base case: If no time is available, the maximum value is 0
            dp[n][0] = 0;
            for (int t = 1; t <= T; t++) {
                // If the current item's time exceeds the available time, skip the item
                if (timeValue.get(n)[0] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    // Choose the maximum between not taking the item and taking it
                    dp[n][t] = Math.max(dp[n - 1][t], timeValue.get(n)[1] + dp[n - 1][t - timeValue.get(n)[0]]);
                }
            }
        }

        // Initialize the maximum value with the last item's value
        int valAcum = timeValue.get(N)[1];
        int t = T - 1;
        int maxVal = valAcum + dp[N - 1][t];

        // Backtrack to find the maximum value considering previous items
        for (int n = N - 1; n > 0; n--) {
            valAcum += timeValue.get(n)[1];
            t -= timeValue.get(n + 1)[0];

            // If time goes negative, break the loop
            if (t < 0) {
                break;
            } else {
                // Update the maximum value if a better option is found
                maxVal = Math.max(maxVal, valAcum + dp[n - 1][t]);
            }
        }

        // Print the maximum value achievable within the given time
        System.out.println(maxVal);
    }
}
