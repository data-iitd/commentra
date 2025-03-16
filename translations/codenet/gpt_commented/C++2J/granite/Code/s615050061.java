
import java.io.*;
import java.util.*;

public class s615050061{
    public static void main(String[] args) throws IOException {
        // Uncomment the following lines to read from a file
        // BufferedReader br = new BufferedReader(new FileReader("code.in"));
        // PrintWriter pw = new PrintWriter(new FileWriter("code.out"));

        // Read input values: number of operations and the operations string
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        char[] op = s[1].toCharArray();

        // Process each character in the input string
        long[] f = new long[n + 1];
        int[] g = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            // If the character is '+' or '-', update f and g arrays
            if (op[i - 1] == '+' || op[i - 1] == '-') {
                f[i] = f[i - 1] + (op[i - 1] == '+'? 1 : -1) * (long) Math.pow(13131, g[i] = g[i - 1]);
            } else {
                // If the character is '<' or '>', update f and g arrays accordingly
                f[i] = f[i - 1]; // No change in f
                g[i] = g[i - 1] + (op[i - 1] == '<'? -1 : 1); // Update g based on direction
            }
        }

        // Iterate backwards through the string to count valid combinations
        Map<Long, Long> map = new HashMap<>();
        long cnt = 0; // Counter for the final result
        for (int i = n; i > 0; --i) {
            map.put(f[i], map.getOrDefault(f[i], 0L) + 1); // Increment the count of the current f value
            // Update the counter with the number of valid combinations found
            cnt += map.getOrDefault(f[n] * (long) Math.pow(13131, g[i - 1]) + f[i - 1], 0L);
        }

        // Output the final count of valid combinations
        System.out.println(cnt);

        // Close input and output streams
        br.close();
        // pw.close();
    }
}

