import java.util.Scanner;

public class Main {
    static long n, m, mod;
    static long[][] C = new long[310][310];  // Binomial coefficients
    static long[][] pre = new long[310][310]; // Prefix sums
    static long[][] f = new long[310][310];   // Dynamic programming table

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextLong();  // Read input values
        m = scanner.nextLong();
        mod = scanner.nextLong();

        C[0][0] = 1;  // Initialize the binomial coefficient table
        // Compute binomial coefficients using nested loops
        for (int i = 1; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }

        // Initialize the dynamic programming table
        for (int i = 0; i <= m; i++) {
            f[1][i] = 1;
            pre[1][i] = m - i + 1;
        }

        // Compute the dynamic programming table
        for (int i = 2; i <= n + 1; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k < i; k++) {
                    f[i][j] = (f[i][j] + f[i - k][j] * pre[k][j + 1] % mod * C[i - 2][k - 1]) % mod;
                }
            }
            for (int j = m; j >= 0; j--) {
                pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod;
            }
        }

        // Output the result
        System.out.println(f[n + 1][0]);  // Print the value of f[n+1][0]
        
        scanner.close();
    }
}
// <END-OF-CODE>
