import java.io.*;
import java.util.*;

public class Main {
    // Method to read the next integer from the input.
    private static int getNextInt(Scanner scanner) {
        return scanner.nextInt(); // Read the next integer from the scanner.
    }

    public static void main(String[] args) throws IOException {
        // Determine the input source: standard input or a file specified as a command-line argument.
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]); // Open the file if a filename is provided.
        }
        Scanner scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(System.out);

        // Read the number of elements.
        int n = getNextInt(scanner);
        int[] mm = new int[n + 1]; // Create an array to hold the input values.
        int[][] dp = new int[n + 1][n + 1]; // Create a 2D array for dynamic programming.

        // Read the input values into the mm array.
        for (int i = 0; i < n; i++) {
            mm[i] = getNextInt(scanner); // Read the first value.
            mm[i + 1] = getNextInt(scanner); // Read the second value.
        }

        // Perform dynamic programming to calculate the minimum cost.
        for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
            for (int i = 1; i <= n - l + 1; i++) { // i is the starting index of the subproblem.
                int j = i + l - 1; // j is the ending index of the subproblem.
                for (int k = i; k <= j - 1; k++) { // k is the partition point.
                    // Calculate the cost of multiplying the matrices.
                    int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                    // Update the dp table with the minimum cost found.
                    if (dp[i][j] == 0 || dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        // Output the minimum cost of multiplying the entire sequence of matrices.
        writer.println(dp[1][n]);

        // Flush the writer to ensure all output is written.
        writer.flush();
        scanner.close();
    }
}

// <END-OF-CODE>
