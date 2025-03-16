import java.util.*;

class Main {
    // Create a Scanner object for input
    final Scanner sc = new Scanner(System.in);
    // Define a constant for the divisor to avoid overflow
    final long DEVISOR = 1000000000 + 7;

    public static void main(String[] args) {
        // Create an instance of Main and run the program
        new Main().run();
    }

    private void run() {
        // Read two long integers n and k from input
        long n = sc.nextLong();
        long k = sc.nextLong();

        // Initialize the answer variable to accumulate results
        long ans = 0;

        // Iterate from k to n+1 to calculate the contribution of each i
        for (long i = k; i <= n + 1; i++) {
            // Calculate the maximum sum for the current i
            long max = i * (2 * n - i + 1) / 2;
            // Calculate the minimum sum for the current i
            long min = i * (i - 1) / 2;
            // Update the answer with the count of valid sums for the current i
            ans += (max - min + 1) % DEVISOR;
        }

        // Output the final answer modulo DEVISOR
        System.out.println(ans % DEVISOR);
    }
}
