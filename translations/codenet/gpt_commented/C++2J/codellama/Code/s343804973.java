// Declare global variables
int n, m, mod, C[][], pre[][], f[][];

public static void main(String[] args) {
    // Read input values for n, m, and mod
    Scanner sc = new Scanner(System.in);
    n = sc.nextLong();
    m = sc.nextLong();
    mod = sc.nextLong();

    // Initialize the binomial coefficient array C
    C = new int[n + 1][n + 1];
    C[0][0] = 1; // Base case: C(0, 0) = 1
    for(int i = 1; i <= n; i++) {
        C[i][0] = C[i][i] = 1; // C(i, 0) = C(i, i) = 1 for all i
        for(int j = 1; j < i; j++)
            // Calculate C(i, j) using the recursive relation
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }

    // Initialize the first row of f and pre arrays
    f = new int[n + 2][m + 1];
    pre = new int[n + 2][m + 1];
    for(int i = 0; i <= m; i++)
        f[1][i] = 1, pre[1][i] = m - i + 1; // Base case for f and pre

    // Fill the f and pre arrays for dynamic programming
    for(int i = 2; i <= n + 1; i++) {
        for(int j = 0; j <= m; j++) {
            // Calculate f[i][j] based on previous values
            for(int k = 1; k < i; k++)
                (f[i][j] += f[i - k][j] * pre[k][j + 1] % mod * C[i - 2][k - 1]) %= mod;
        }
        // Update the pre array for the current row
        for(int j = m; j >= 0; j--)
            pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod;
    }

    // Output the result which is f[n + 1][0]
    System.out.println(f[n + 1][0]);
}

