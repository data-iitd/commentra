package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Determine the input source based on command-line arguments
        InputStream fp = System.in;
        if (args.length > 0) {
            fp = new FileInputStream(args[0]);
        }

        // Create a new scanner to read from the determined input source
        Scanner scanner = new Scanner(fp);

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
        System.out.println(dp[n]);
    }
}

