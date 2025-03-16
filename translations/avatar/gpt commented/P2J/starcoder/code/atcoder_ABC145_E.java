import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of items (N) and the maximum time (T)
        int N = sc.nextInt();
        int T = sc.nextInt();

        // Initialize a list to store time and value pairs, starting with a dummy entry
        List<int[]> time_value = new ArrayList<int[]>();
        time_value.add(new int[]{-1, -1});

        // Read the time and value pairs for each item
        for (int i = 0; i < N; i++) {
            int[] pair = new int[2];
            pair[0] = sc.nextInt();
            pair[1] = sc.nextInt();
            time_value.add(pair);
        }

        // Sort the time_value list based on the value (VAL)
        Collections.sort(time_value, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });

        // Initialize a 2D list for dynamic programming, with -1 as default values
        int[][] dp = new int[N + 1][T + 1];
        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < T + 1; j++) {
                dp[i][j] = -1;
            }
        }

        // Base case: If time is 0, the maximum value is 0 for all items
        for (int t = 0; t < T + 1; t++) {
            dp[0][t] = 0;
        }

        // Fill the dynamic programming table
        for (int n = 1; n < N + 1; n++) {
            // Base case: If no time is available, the maximum value is 0
            dp[n][0] = 0;
            for (int t = 1; t < T + 1; t++) {
                // If the current item's time exceeds the available time, skip the item
                if (time_value.get(n)[0] > t) {
                    dp[n][t] = dp[n - 1][t];
                } else {
                    // Choose the maximum between not taking the item and taking it
                    dp[n][t] = Math.max(dp[n - 1][t], time_value.get(n)[1] + dp[n - 1][t - time_value.get(n)[0]]);
                }
            }
        }

        // Initialize the maximum value with the last item's value
        int val_acum = time_value.get(N)[1];
        int t = T - 1;
        int max_val = val_acum + dp[N - 1][t];

        // Backtrack to find the maximum value considering previous items
        for (int n = N - 1; n > 0; n--) {
            val_acum += time_value.get(n)[1];
            t -= time_value.get(n + 1)[0];

            // If time goes negative, break the loop
            if (t < 0) {
                break;
            } else {
                // Update the maximum value if a better option is found
                max_val = Math.max(max_val, val_acum + dp[n - 1][t]);
            }
        }

        // Print the maximum value achievable within the given time
        System.out.println(max_val);
    }
}

