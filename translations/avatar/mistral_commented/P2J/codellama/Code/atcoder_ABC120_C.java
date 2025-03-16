// Import necessary libraries and modules
import java.util.*;
import java.io.*;
import java.math.*;

// Set up input reading functions
static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
static StringTokenizer st;
static String next() throws IOException {
    while (st == null || !st.hasMoreTokens())
        st = new StringTokenizer(br.readLine());
    return st.nextToken();
}
static int nextInt() throws IOException {
    return Integer.parseInt(next());
}
static long nextLong() throws IOException {
    return Long.parseLong(next());
}
static double nextDouble() throws IOException {
    return Double.parseDouble(next());
}

// Define constants
static final int INF = Integer.MAX_VALUE;
static final int MOD = 1000000007;

// Define main function
public static void main(String[] args) throws IOException {
    // Read input string
    String s = next();

    // Check if all characters in the string are the same
    if (s.length() == 1) {
        // If so, print 0 and exit
        System.out.println(0);
        return;
    }

    // Count the occurrences of each character in the string
    Map<Character, Integer> a = new HashMap<>();
    for (char c : s.toCharArray()) {
        if (a.containsKey(c)) {
            a.put(c, a.get(c) + 1);
        } else {
            a.put(c, 1);
        }
    }

    // Calculate the answer
    int ans = INF;
    for (int v : a.values()) {
        ans = Math.min(ans, v * 2);
    }

    // Print the answer
    System.out.println(ans);
}
