
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Determine the input source based on command-line arguments
        Scanner scanner = new Scanner(System.in);
        if (args.length > 0) {
            try {
                scanner = new Scanner(new BufferedReader(new InputStreamReader(new java.io.FileInputStream(args[0]))));
            } catch (java.io.FileNotFoundException e) {
                System.out.println("File not found");
                System.exit(1);
            }
        }

        // Create a writer to output the result
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

        // Read the number of elements (n) and the number of restricted positions (m)
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Create a map to store the restricted positions
        Map<Integer, Integer> aa = new HashMap<Integer, Integer>();
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
        writer.println(dp[n]);

        // Flush the writer to ensure all data is written to the output
        writer.flush();

        // Close the writer
        writer.close();
    }
}

