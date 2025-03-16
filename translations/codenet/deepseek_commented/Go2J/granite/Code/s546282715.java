
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
        // Determine the input source based on command-line arguments
        BufferedReader reader = new BufferedReader(new FileReader(args.length > 0? args[0] : "input.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));

        // Create a scanner to read from the determined input source
        Scanner scanner = new Scanner(reader);

        // Create a writer to output the result

        // Read the number of elements (n) and the number of restricted positions (m)
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Create a map to store the restricted positions
        Map<Integer, Integer> aa = new HashMap<>();
        for (int i = 0; i < m; i++) {
            aa.put(scanner.nextInt(), 1);
        }

        // Initialize the dynamic programming array
        int[] dp = new int[n + 1];
        dp[0] = 1;

        // Fill the dynamic programming array based on restricted positions
        for (int i = 0; i < n; i++) {
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                if (aa.containsKey(i + ii)) {
                    continue;
                }
                dp[i + ii] += dp[i];
                dp[i + ii] %= 1000000007;
            }
        }

        // Print the result
        writer.write(String.valueOf(dp[n]));
        writer.newLine();

        // Flush the writer to ensure all data is written to the output
        writer.flush();
    }
}

