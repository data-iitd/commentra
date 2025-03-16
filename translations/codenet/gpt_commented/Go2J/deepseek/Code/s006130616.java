import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare variables for the number of participants (n), number of skills (m), and the minimum skill level required (x)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();

        // Initialize a 2D array to hold skill levels and an array for participant points
        int[][] a = new int[n][m];
        int[] p = new int[n];

        // Read participant points and their respective skill levels
        for (int i = 0; i < n; i++) {
            // Read the points for participant i
            p[i] = scanner.nextInt();
            // Read the skill levels for participant i
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        // Initialize the answer to a large number and other variables for tracking total points and skill validation
        int ans = Integer.MAX_VALUE;
        int tot = 0;
        boolean ok = true;

        // Iterate through all possible combinations of participants using bit manipulation
        for (int bits = 0; bits < 1 << n; bits++) {
            // Reset total points and skill validation flag for the current combination
            tot = 0;
            ok = true;
            // Initialize an array to accumulate skill levels for the current combination
            int[] skill = new int[m];

            // Check each participant to see if they are included in the current combination
            for (int i = 0; i < n; i++) {
                if ((bits & (1 << i)) != 0) {
                    // Add the points of the selected participant to the total
                    tot += p[i];
                    // Accumulate the skill levels of the selected participant
                    for (int j = 0; j < m; j++) {
                        skill[j] += a[i][j];
                    }
                }
            }

            // Check if the accumulated skill levels meet the minimum requirement
            for (int v : skill) {
                if (v < x) {
                    ok = false; // If any skill level is below x, mark as not okay
                    break;
                }
            }

            // If the combination is valid (all skills meet the requirement), update the answer if the total points are lower
            if (ok) {
                ans = Math.min(ans, tot);
            }
        }

        // Output the result: the minimum points needed or -1 if no valid combination was found
        if (ans != Integer.MAX_VALUE) {
            System.out.println(ans);
        } else {
            System.out.println("-1");
        }
    }
}
