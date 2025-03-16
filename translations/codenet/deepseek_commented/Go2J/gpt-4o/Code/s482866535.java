import java.io.*;
import java.util.*;

public class MatrixMultiplication {

    // Method to read the next integer from the input.
    private static int getNextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    public static void main(String[] args) throws IOException {
        // Use standard input or a file if provided as an argument.
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }
        Scanner scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(System.out);

        // Read the number of matrices.
        int n = getNextInt(scanner);

        // Initialize arrays for matrix dimensions and dynamic programming.
        int[] mm = new int[n + 1];
        int[][] dp = new int[n + 1][n + 1];

        // Read matrix dimensions into the mm array.
        for (int i = 0; i < n; i++) {
            mm[i] = getNextInt(scanner);
            mm[i + 1] = getNextInt(scanner);
        }

        // Use dynamic programming to compute the minimum number of multiplications.
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = Integer.MAX_VALUE; // Initialize to a large value
                for (int k = i; k <= j - 1; k++) {
                    int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                    if (dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        // Print the result to the standard output.
        writer.println(dp[1][n]);

        // Flush the writer to ensure all data is written to the output.
        writer.flush();
        scanner.close();
    }
}

// <END-OF-CODE>
