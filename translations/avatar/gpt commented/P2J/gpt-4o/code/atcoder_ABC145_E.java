import java.util.*;
import java.io.*;

public class Main {
    // Constants to represent indices for time and value
    private static final int TIME = 0;
    private static final int VAL = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(input.readLine());

        // Read the number of items (N) and the maximum time (T)
        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        // Initialize a list to store time and value pairs
        int[][] timeValue = new int[N + 1][2];
        timeValue[0][TIME] = -1; // Dummy entry
        timeValue[0][VAL] = -1;

        // Read the time and value pairs for each item
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(input.readLine());
            timeValue[i][TIME] = Integer.parseInt(st.nextToken());
            timeValue[i][VAL] = Integer.parseInt(st.nextToken());
        }

        // Sort the timeValue array based on the value (VAL)
        Arrays.sort(timeValue, 1, N + 1, Comparator.comparingInt(a -> a[VAL]));

        // Initialize a 2D list for dynamic programming, with -1 as default values
        int[][] dp = new int[N + 1][T];
        for (int n = 0; n <= N; n++) {
            Arrays.fill(dp[n], -1);
        }

        // Base case: If time is 0, the maximum value is 0 for all items
        for (int t = 0; t < T; t++) {
            dp[0][t] = 0;
        }

        // Fill the dynamic programming table
        for (int n = 1; n <= N; n++) {
            // Base case: If no time is available, the maximum value is 0
            dp[n][0] = 0;
            for (int t = 1; t < T; t++) {
                // If the current item's time exceeds the available time, skip the item
                if (timeValue[n][TIME] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    // Choose the maximum between not taking the item and taking it
                    dp[n][t] = Math.max(dp[n - 1][t], timeValue[n][VAL] + dp[n - 1][t - timeValue[n][TIME]]);
                }
            }
        }

        // Initialize the maximum value with the last item's value
        int valAcum = timeValue[N][VAL];
        int t = T - 1;
        int maxVal = valAcum + dp[N - 1][t];

        // Backtrack to find the maximum value considering previous items
        for (int n = N - 1; n > 0; n--) {
            valAcum += timeValue[n][VAL];
            t -= timeValue[n + 1][TIME];

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
// <END-OF-CODE>
