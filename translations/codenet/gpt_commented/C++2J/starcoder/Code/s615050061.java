import java.util.*;
import java.io.*;

public class Main {
    // Define constants for base and maximum size
    static final int B = 13131;
    static final int N = 500000 + 7;

    // Declare global variables
    static int n; // Length of the input string
    static char[] s = new char[N]; // Input string
    static long[] f = new long[N]; // Array to store computed values based on the input string
    static int[] g = new int[N]; // Array to store the shift values
    static Map<Long, Long> map = new HashMap<Long, Long>(); // Map to count occurrences of computed values
    static long cnt; // Counter for the final result

    // Function to compute power of a number with a given exponent
    static long pow(long a, long k) {
        // Adjust exponent if negative
        if (k < 0) k += (1 << 63) - 1;
        long t = 1; // Initialize result
        // Exponentiation by squaring
        for (; k; a = a * a, k >>= 1)
            if (k & 1) t = t * a; // Multiply result if current bit is set
        return t; // Return computed power
    }

    public static void main(String[] args) {
        // Uncomment the following lines to read from a file
        // try {
        //     BufferedReader br = new BufferedReader(new FileReader("code.in"));
        //     n = Integer.parseInt(br.readLine());
        //     br.close();
        // } catch (IOException e) {
        //     e.printStackTrace();
        //     return;
        // }

        // Read input values: number of operations and the operations string
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
        try {
            BufferedReader br = new BufferedReader(new FileReader("code.in"));
            br.readLine();
            s = br.readLine().toCharArray();
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        // Process each character in the input string
        for (int i = 1; i <= n; ++i) {
            // If the character is '+' or '-', update f and g arrays
            if (s[i] == '+' || s[i] == '-') {
                f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i - 1]);
            } else {
                // If the character is '<' or '>', update f and g arrays accordingly
                f[i] = f[i - 1]; // No change in f
                g[i] = g[i - 1] + (s[i] == '<'? -1 : 1); // Update g based on direction
            }
        }

        // Iterate backwards through the string to count valid combinations
        for (int i = n; i; --i) {
            map.put(f[i], map.getOrDefault(f[i], 0l) + 1); // Increment the count of the current f value
            // Update the counter with the number of valid combinations found
            cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0l);
        }

        // Output the final count of valid combinations
        System.out.println(cnt);
    }
}

