import java.util.Scanner;

public class Main {
    static long INF = 1001001001001001L;
    static int inf = 1000000007;
    static long MOD = 1000000007L;
    static double PI = 3.1415926535897932;

    // Method to calculate the minimum of two values
    static void chmin(long[] a, long b) {
        if (a[0] > b) a[0] = b; // Set 'a' to the minimum of 'a' and 'b'
    }

    // Method to calculate the maximum of two values
    static void chmax(long[] a, long b) {
        if (a[0] < b) a[0] = b; // Set 'a' to the maximum of 'a' and 'b'
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array 'a'
        int n = scanner.nextInt();

        // Initialize an array 'a' of size 'n'
        long[] a = new long[n];

        // Initialize an array 'acc' of size 'n+1' with zero as initial value
        long[] acc = new long[n + 1];

        // Read the elements of the array 'a' and calculate the cumulative sum
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();

            // Update the cumulative sum 'acc' for the current index 'i+1'
            acc[i + 1] = (acc[i] + a[i]) % MOD;
        }

        // Initialize the answer 'ans' to zero
        long ans = 0;

        // Calculate the answer using the formula
        for (int i = 0; i < n; i++) {
            // Calculate the contribution of the current element 'a[i]' to the answer
            long temp = (a[i] % MOD * (MOD + acc[n] - acc[i + 1]) % MOD) % MOD;

            // Add the contribution to the answer
            ans = (ans + temp) % MOD;
        }

        // Print the answer
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
