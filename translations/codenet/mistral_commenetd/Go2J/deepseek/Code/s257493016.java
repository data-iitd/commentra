import java.util.Scanner;

public class Main {

    // Function to find minimum number in a slice
    public static int min(int... n) {
        if (n.length == 0) {
            // Panic if the slice is empty
            throw new IllegalArgumentException("len == 0");
        }
        int r = n[0];
        // Initialize minimum value with first element of the slice
        for (int i = 1; i < n.length; i++) {
            // Compare current element with minimum value and update minimum value if current element is smaller
            if (n[i] <= r) {
                r = n[i];
            }
        }
        // Return the minimum value
        return r;
    }

    // Main function
    public static void main(String[] args) {
        // Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int N = scanner.nextInt();

        // Initialize a array dp of size H+10001 with initial value 2100000000
        int[] dp = new int[H + 10001];
        for (int l = 1; l < H + 10001; l++) {
            dp[l] = 2100000000;
        }

        // Initialize maximum reachable floor amax to 0
        int amax = 0;
        // Iterate through each jump
        for (int i = 0; i < N; i++) {
            // Read floor A and number of floors B that can be jumped from floor A
            int A = scanner.nextInt();
            int B = scanner.nextInt();

            // If the maximum reachable floor is less than A, update maximum reachable floor
            if (A >= amax) {
                amax = A;
            }

            // Update dp[A] with minimum of current dp[A] and B
            dp[A] = min(dp[A], B);

            // Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
            for (int j = A + 1; j <= H + A + 1; j++) {
                dp[j] = min(dp[j], dp[j - A] + B);
            }
        }

        // Print the minimum number of jumps required to reach the last floor
        int[] dpHtoHplusAmax = new int[H + amax + 1];
        System.arraycopy(dp, H, dpHtoHplusAmax, 0, H + amax + 1);
        System.out.println(min(dpHtoHplusAmax));

        // End of code
    }
}
