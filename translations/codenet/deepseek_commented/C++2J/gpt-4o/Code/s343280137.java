import java.util.Scanner;

public class Main {
    static final long MOD = 1000000007;
    static final long INF = 1 << 29;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Input Reading
        long n = scanner.nextLong();
        long c = scanner.nextLong();

        // Step 2: Array Initialization
        long[] x = new long[(int) n + 1];
        long[] v = new long[(int) n + 1];

        // Step 3: Reading Positions and Values
        for (int i = 1; i <= n; i++) {
            x[i] = scanner.nextLong();
            v[i] = scanner.nextLong();
        }

        // Step 4: Calculate Total Value Moving Left
        long[] lefttotal = new long[(int) n + 1];
        long[] maxlefttotal = new long[(int) n + 1];
        for (int i = 1; i <= n; i++) {
            lefttotal[i] = lefttotal[i - 1] + v[i];
        }

        // Step 5: Calculate Maximum Value Left
        for (int i = 1; i <= n; i++) {
            maxlefttotal[i] = Math.max(maxlefttotal[i - 1], lefttotal[i] - x[i]);
        }

        // Step 6: Calculate Total Value Moving Right
        long[] righttotal = new long[(int) n + 1];
        long[] maxrighttotal = new long[(int) n + 1];
        for (int i = 1; i <= n; i++) {
            righttotal[i] = righttotal[i - 1] + v[(int) (n - i + 1)];
        }

        // Step 7: Calculate Maximum Value Right
        for (int i = 1; i <= n; i++) {
            maxrighttotal[i] = Math.max(maxrighttotal[i - 1], righttotal[i] - (c - x[(int) (n + 1 - i)]));
        }

        // Step 8: Calculate the Maximum Value
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = Math.max(ans, lefttotal[i] - x[i]);
            ans = Math.max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[(int) (n - i)]);
            ans = Math.max(ans, righttotal[i] - (c - x[(int) (n + 1 - i)]));
            ans = Math.max(ans, righttotal[i] - 2 * (c - x[(int) (n + 1 - i)]) + maxlefttotal[(int) (n - i)]);
        }

        // Step 9: Output the Result
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
