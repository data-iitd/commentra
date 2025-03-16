
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        // Set the input source to standard input; if a file is provided as an argument, open that file.
        BufferedReader fp = new BufferedReader(new InputStreamReader(System.in));
        if (args.length > 0) {
            fp = new BufferedReader(new InputStreamReader(Main.class.getResourceAsStream(args[0])));
        }

        // Create a new scanner to read from the input source and configure it to split input into words.
        String[] nextWord = new String[1];
        fp.readLine();
        fp.readLine();
        Map<Integer, Integer> aa = new HashMap<>();
        for (int i = 0; i < Integer.parseInt(fp.readLine()); i++) {
            // Read each blocked position and mark it in the map.
            aa.put(Integer.parseInt(fp.readLine()), 1);
        }

        // Create a dynamic programming array to store the number of ways to reach each position.
        int[] dp = new int[Integer.parseInt(fp.readLine()) + 1];
        dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

        // Iterate through each position from 0 to n.
        for (int i = 0; i < dp.length - 1; i++) {
            // Check the next two positions (i+1 and i+2) to see if they can be reached.
            for (int ii = 1; ii <= 2 && i + ii < dp.length; ii++) {
                if (aa.containsKey(i + ii)) {
                    continue; // If blocked, skip to the next iteration.
                }
                // Update the number of ways to reach position i+ii based on the current position i.
                dp[i + ii] += dp[i];
                dp[i + ii] %= 1000000007; // Ensure the result stays within the modulo limit.
            }
        }

        // Output the total number of ways to reach position n.
        System.out.println(dp[dp.length - 1]);
    }
}

