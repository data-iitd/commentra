
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s482866535{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        // Open the file provided as an argument and use it as the input stream
        if (args.length > 0) {
            br = new BufferedReader(new FileReader(args[0]));
        }

        // Read the number of test cases from the input
        int n = Integer.parseInt(br.readLine());

        // Initialize a slice to store the prefix sum of squares of elements
        int[] mm = new int[n + 1];

        // Initialize a 2D slice to store the dynamic programming table
        int[][] dp = new int[n + 1][n + 1];

        // Read the elements and their prefix sum of squares from the input
        for (int i = 0; i < n; i++) {
            // Read the next integer as the current element
            mm[i + 1] = Integer.parseInt(br.readLine());
            // Read the next integer as the next element's prefix sum of square
            mm[i + 1] += mm[i] * mm[i];
        }

        // Process the dynamic programming table for all subarrays of given size
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                // Iterate through all subarrays of the current subarray
                for (int k = i; k <= j - 1; k++) {
                    // Calculate the sum of squares of elements in the current subarray
                    int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                    // Update the dynamic programming table if a larger sum is found
                    if (dp[i][j] == 0 || dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        // Print the result for the given input
        out.println(dp[1][n]);

        // Flush the writer to print the result
        out.flush();

        // End of the code
    }
}
