import java.util.Scanner;

public class Main {
    static final long MOD = 1000000007; // Constants definition
    static final long INF = 1 << 29;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input section
        long n = scanner.nextLong(); // Number of elements
        long c = scanner.nextLong(); // Capacity

        long[] x = new long[(int) n + 1]; // Declare and initialize array x
        long[] v = new long[(int) n + 1]; // Declare and initialize array v

        for (int i = 1; i <= n; i++) { // Loop through each element in the array
            x[i] = scanner.nextLong(); // Read input values for x[i]
            v[i] = scanner.nextLong(); // Read input values for v[i]
        }

        // Calculate left prefix sums
        long[] lefttotal = new long[(int) n + 1];
        long[] maxlefttotal = new long[(int) n + 1];
        for (int i = 1; i <= n; i++) {
            lefttotal[i] = lefttotal[i - 1] + v[i]; // Calculate prefix sums of vector v
            maxlefttotal[i] = Math.max(maxlefttotal[i - 1], lefttotal[i] - x[i]); // Calculate maximum prefix sums excluding current element
        }

        // Calculate right prefix sums
        long[] righttotal = new long[(int) n + 1];
        long[] maxrighttotal = new long[(int) n + 1];
        for (int i = 1; i <= n; i++) {
            righttotal[i] = righttotal[i - 1] + v[(int) (n - i + 1)]; // Calculate prefix sums of reversed vector v
            maxrighttotal[i] = Math.max(maxrighttotal[i - 1], righttotal[i] - (c - x[(int) (n + 1 - i)])); // Calculate maximum prefix sums excluding current element
        }

        // Calculate answer
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, lefttotal[i] - x[i]); // Calculate maximum sum by including current element in left sum
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[(int) (n - i)]); // Calculate maximum sum by excluding current element in left sum and including it in right sum
            ans = Math.max(ans, righttotal[i] - (c - x[(int) (n + 1 - i)])); // Calculate maximum sum by including current element in right sum
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[(int) (n + 1 - i)]) + maxlefttotal[(int) (n - i)]); // Calculate maximum sum by excluding current element in right sum and including it in left sum
        }

        // Output answer
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
