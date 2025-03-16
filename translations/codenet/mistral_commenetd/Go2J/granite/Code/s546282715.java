
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class s546282715{

    public static void main(String[] args) throws IOException {
        // Open the standard input file if the command line argument is provided
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Initialize the scanner and writer
        Scanner scanner = new Scanner(System.in);
        if (args.length > 0) {
            reader = new BufferedReader(new FileReader(args[0]));
        }

        // Read the first two integers from the input
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize an associative array to store the elements
        Map<Integer, Integer> aa = new HashMap<>();
        // Read m elements and store them in the associative array
        for (int i = 0; i < m; i++) {
            aa.put(scanner.nextInt(), 1);
        }

        // Initialize a slice of length n+1 for dynamic programming
        int[] dp = new int[n + 1];
        // Initialize the first element of the slice
        dp[0] = 1;

        // Iterate through the array from index 0 to n-1
        for (int i = 0; i < n; i++) {
            // Iterate through the prefix sum from i to i+2
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                // Skip if the current index and its sum are already present in the associative array
                if (aa.containsKey(i + ii)) {
                    continue;
                }
                // Calculate the dynamic programming value for the current index
                dp[i + ii] += dp[i];
                // Perform modulo operation to keep the value within the range of 10^9+7
                dp[i + ii] %= 1000000007;
            }
        }

        // Print the final answer
        writer.write(String.valueOf(dp[n]));
        writer.newLine();

        // Flush the writer buffer
        writer.flush();
    }
}

