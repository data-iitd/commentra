public class Main {
    public static void main(String[] args) {
        // Step 2: Read input values
        long n, k;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextLong();
        k = scanner.nextLong();
        long MOD = 1000000007;

        // Step 3: Calculate the maximum and minimum sums
        long mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
        long mn = k * (k - 1) / 2;

        // Step 4: Initialize variables
        long res = 0;

        // Step 5: Loop through possible lengths
        for (int i = (int) k; i <= n + 1; ++i) {
            // Update res, mx, and mn in each iteration
            res += mx - mn + 1;
            mx += n - i;
            mn += i;
            res %= MOD;
        }

        // Step 6: Output the result
        System.out.println(res);
    }
}
