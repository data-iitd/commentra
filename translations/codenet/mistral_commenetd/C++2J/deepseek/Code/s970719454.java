import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initializing arrays
        int[] here = new int[100001];
        int[] dp1 = new int[100001];
        int[] dp2 = new int[100001];

        // Initializing all elements of the arrays to zero
        for (int i = 0; i < 100001; i++) {
            here[i] = dp1[i] = dp2[i] = 0;
        }

        // Reading input
        while (true) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (n == 0) break;

            // Resetting the arrays for new input
            for (int i = 0; i < 100001; i++) {
                here[i] = dp1[i] = dp2[i] = 0;
            }

            // Reading queries
            boolean dpflg = false;
            for (int i = 0; i < m; i++) {
                int a = scanner.nextInt();
                // Setting the corresponding element of 'here' array to 1
                here[a] = 1;
                // If a query is to find the maximum length of a subsequence without any house, then setting 'dpflg' to true
                if (a == 0) dpflg = true;
            }

            // Calculating the maximum length of a subsequence without any house
            int maxi1 = 0;
            for (int i = 1; i <= n; i++) {
                if (here[i] == 1) dp1[i] = dp1[i - 1] + 1;
                maxi1 = Math.max(dp1[i], maxi1);
            }

            // Calculating the maximum length of a subsequence with at least one house
            int maxi2 = 0;
            for (int i = 1; i <= n; i++) {
                if (here[i] == 1) dp2[i] = dp2[i - 1] + 1;
                else dp2[i] = dp1[i - 1] + 1;
                maxi2 = Math.max(dp2[i], maxi2);
            }

            // Printing the result
            if (!dpflg) {
                System.out.println(maxi1);
            } else {
                System.out.println(maxi2);
            }
        }
    }
}
