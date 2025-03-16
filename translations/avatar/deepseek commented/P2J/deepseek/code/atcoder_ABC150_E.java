public class Main {
    public static void main(String[] args) {
        final int mod = (int) Math.pow(10, 9) + 7;
        // Define the modulo value as \(10^9 + 7\)

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        // Read the integer input `n`

        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
        }
        // Read the list of integers `c` and convert them to an array

        java.util.Arrays.sort(c);
        // Sort the array `c` in ascending order

        int b = (int) Math.pow((int) Math.pow(2, 2 * n - 2) % mod, mod);
        // Calculate `b` using the power function with base 2, exponent \(2 * n - 2\), and modulo `mod`

        int a = 2 * b % mod;
        // Calculate `a` as twice `b` modulo `mod`

        int ans = 0;
        // Initialize `ans` to 0

        for (int i = 0; i < n; i++) {
            // Loop through each element in the range `n`
            ans += c[i] * (a + i * b);
            // Update `ans` with the sum of the product of `c[i]` and `(a + i * b)`
            ans %= mod;
            // Take modulo `mod` at each step to prevent overflow
        }

        System.out.println(ans);
        // Print the final result `ans`
    }
}
