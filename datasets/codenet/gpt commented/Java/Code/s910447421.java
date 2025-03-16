import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static int ans = 100; // Variable to store the minimum answer found
    static int[][] balls; // 2D array to store the coordinates of the balls
    static int N; // Number of balls
    static boolean[] taken; // Array to track which balls have been taken

    public static void main(String[] args) {
        // Initialize input and output handlers
        FastScanner I = new FastScanner(); // Input
        OutPut O = new OutPut(); // Output

        // Read the number of balls
        N = I.nextInt();
        ans = N; // Initialize ans to N, the maximum possible value

        // Read the coordinates of the balls
        balls = new int[N][2];
        for (int i = 0; i < N; i++) {
            balls[i][0] = I.nextInt(); // Read x-coordinate
            balls[i][1] = I.nextInt(); // Read y-coordinate
        }

        // Sort the balls based on their x-coordinates
        Arrays.sort(balls, (a, b) -> Integer.compare(a[0], b[0]));
        
        // Solve the problem with the original coordinates
        solve();

        // Swap x and y coordinates for the next check
        for (int i = 0; i < N; i++) {
            int x = balls[i][0];
            int y = balls[i][1];
            balls[i][0] = y; // Set x to y
            balls[i][1] = x; // Set y to x
        }

        // Sort the balls again based on the new x-coordinates
        Arrays.sort(balls, (a, b) -> Integer.compare(a[0], b[0]));

        // Solve the problem with the swapped coordinates
        solve();

        // Output the minimum answer found
        O.pln(ans);
    }

    // Method to solve the problem by checking possible p and q values
    public static void solve() {
        // Iterate through possible differences
        for (int add = 1; add < N; add++) {
            taken = new boolean[N]; // Reset taken array for each new p, q pair
            int p = balls[add][0] - balls[0][0]; // Calculate difference in x-coordinates
            int q = balls[add][1] - balls[0][1]; // Calculate difference in y-coordinates
            ans = min(ans, check(p, q)); // Update ans with the minimum found
        }
    }

    // Method to check how many balls can be connected with given p and q
    public static int check(int p, int q) {
        int ret = 0; // Counter for connected balls
        while (true) {
            boolean added = false; // Flag to check if a ball was added
            int start = 0; // Starting index for the next ball to connect
            int x = -1; // Next x-coordinate to check
            int y = -1; // Next y-coordinate to check

            // Find the first ball that hasn't been taken
            for (int i = 0; i < N; i++) {
                if (!taken[i]) {
                    added = true; // A ball has been added
                    ret++; // Increment the count of connected balls
                    start = i; // Store the starting index
                    taken[i] = true; // Mark this ball as taken
                    x = balls[i][0] + p; // Calculate the next x-coordinate
                    y = balls[i][1] + q; // Calculate the next y-coordinate
                    break; // Exit the loop after finding the first ball
                }
            }
            if (!added) break; // If no ball was added, exit the loop

            // Check for additional balls that can be connected
            for (int i = start + 1; i < N; i++) {
                if (balls[i][0] == x && balls[i][1] == y) {
                    taken[i] = true; // Mark this ball as taken
                    x += p; // Move to the next x-coordinate
                    y += q; // Move to the next y-coordinate
                }
            }
        }
        return ret; // Return the total count of connected balls
    }

    // Utility methods for mathematical operations
    public static double max(double a, double b) { return Math.max(a, b); }
    public static double min(double a, double b) { return Math.min(a, b); }
    public static long min(long a, long b) { return Math.min(a, b); }
    public static long max(long a, long b) { return Math.max(a, b); }
    public static int min(int a, int b) { return Math.min(a, b); }
    public static int max(int a, int b) { return Math.max(a, b); }
    public static long abs(long x) { return Math.abs(x); }
    
    // Method to calculate the ceiling of a division
    public static long ceil(long num, long den) {
        long ans = num / den; 
        if (num % den != 0) ans++; // Increment if there's a remainder
        return ans;
    }

    // Method to calculate the GCD of two numbers
    public static long GCD(long a, long b) {
        if (a == 0 || b == 0) return max(a, b);
        return GCD(min(a, b), max(a, b) % min(a, b));
    }

    // Method for fast exponentiation
    public static long FastExp(long base, long exp, long mod) {
        long ans = 1;
        while (exp > 0) {
            if (exp % 2 == 1) ans *= base; // If exp is odd, multiply base
            exp /= 2; // Divide exp by 2
            base *= base; // Square the base
            base %= mod; // Take mod
            ans %= mod; // Take mod
        }
        return ans; // Return the result
    }

    // Method to calculate modular inverse
    public static long ModInv(long num, long mod) {
        return FastExp(num, mod - 2, mod); // Using Fermat's little theorem
    }

    // Method to count the number of bits set in a number
    public static int pop(long x) {
        int cnt = 0; // Counter for bits
        while (x > 0) {
            if (x % 2 == 1) cnt++; // Increment if the last bit is set
            x /= 2; // Right shift
        }
        return cnt; // Return the count of set bits
    }

    // FastScanner class for efficient input reading
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        // Method to get the next token
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        // Methods to read different types of input
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
    }

    // OutPut class for efficient output writing
    static class OutPut {
        PrintWriter w = new PrintWriter(System.out);

        // Methods to print different types of output
        void pln(double x) { w.println(x); w.flush(); }
        void pln(boolean x) { w.println(x); w.flush(); }
        void pln(int x) { w.println(x); w.flush(); }
        void pln(long x) { w.println(x); w.flush(); }
        void pln(String x) { w.println(x); w.flush(); }
        void pln(char x) { w.println(x); w.flush(); }
        void pln(StringBuilder x) { w.println(x); w.flush(); }
        void pln(BigInteger x) { w.println(x); w.flush(); }
        void p(int x) { w.print(x); w.flush(); }
        void p(long x) { w.print(x); w.flush(); }
        void p(String x) { w.print(x); w.flush(); }
        void p(char x) { w.print(x); w.flush(); }
        void p(StringBuilder x) { w.print(x); w.flush(); }
        void p(BigInteger x) { w.print(x); w.flush(); }
        void p(double x) { w.print(x); w.flush(); }
        void p(boolean x) { w.print(x); w.flush(); }
    }
}
