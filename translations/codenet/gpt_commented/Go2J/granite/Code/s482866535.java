
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s482866535{
    public static void main(String[] args) throws IOException {
        // Determine the input source: standard input or a file specified as a command-line argument.
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        if (args.length > 0) {
            reader = new BufferedReader(new FileReader(args[0]));
        }

        // Initialize the scanner for reading input and a writer for output.
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int[][] mm = new int[n + 1][n + 1];
        int[][] dp = new int[n + 1][n + 1];

        // Read the input values into the mm slice.
        for (int i = 0; i < n; i++) {
            mm[i][0] = Integer.parseInt(tokenizer.nextToken());
            mm[i + 1][0] = Integer.parseInt(tokenizer.nextToken());
        }

        // Perform dynamic programming to calculate the minimum cost.
        for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
            for (int i = 1; i <= n - l + 1; i++) { // i is the starting index of the subproblem.
                int j = i + l - 1; // j is the ending index of the subproblem.
                for (int k = i; k <= j - 1; k++) { // k is the partition point.
                    // Calculate the cost of multiplying the matrices.
                    int d = dp[i][k] + dp[k + 1][j] + mm[i - 1][0] * mm[k][0] * mm[j][0];
                    // Update the dp table with the minimum cost found.
                    if (dp[i][j] == 0 || dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        // Output the minimum cost of multiplying the entire sequence of matrices.
        System.out.println(dp[1][n]);
    }
}

