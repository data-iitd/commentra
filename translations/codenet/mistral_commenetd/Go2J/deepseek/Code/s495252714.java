import java.util.*;
import java.io.*;

public class Main {
    //=====I/O=====

    // Initialize scanner and writer
    static Scanner sc = new Scanner(System.in);
    static PrintWriter wr = new PrintWriter(System.out);

    // Function to read an integer from standard input
    static int scanInt() {
        return sc.nextInt();
    }

    // Function to read an integer64 from standard input
    static long scanInt64() {
        return sc.nextLong();
    }

    // Function to read n integers from standard input
    static int[] scanInts(int n) {
        int[] res = new int[n];
        // Read n integers and store them in array res
        for (int i = 0; i < n; i++) { res[i] = scanInt(); }
        return res;
    }

    // Function to print integers to standard output
    static void printInts(int... a) {
        // Iterate through array a and print each integer followed by a space
        for (int i = 0; i < a.length; i++) {
            wr.print(a[i]);
            if (i != a.length - 1) { wr.print(" "); }
        }
        // Print newline character and flush writer buffer
        wr.println();
        wr.flush();
    }

    //=====main=====

    // Set scanner to scan words
    public static void main(String[] args) {
        sc.useDelimiter("\\s+");

        // Read an integer n from standard input
        int n = scanInt();

        // Read n integers c from standard input and store them in an array
        int[] c = scanInts(n);

        // Initialize answer variable to 0
        long ans = 0;

        // Sort array c in ascending order
        Arrays.sort(c);

        // Iterate through array c and calculate answer
        for (int i = 0; i < n; i++) {
            // Calculate contribution of current integer to answer
            ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
        }

        // Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
        System.out.println(ans * modpow(4, n - 1) % mod);
    }

    // Constants
    static final int mod = 1000000007;

    // Function to calculate modular exponentiation
    static long modpow(int a, int n) {
        // Initialize result to 1
        long res = 1;

        // If n is 0, return result
        if (n == 0) { return res; }

        // If n is 1, return a
        if (n == 1) { return a; }

        // If n is odd, multiply result with a multiplied by itself recursively
        if (n % 2 == 1) {
            res = res * a % mod;
            a = a * a % mod;
            n = n / 2;
            res = res * modpow(a, n) % mod;
        }

        // If n is even, square result and recursively call function for n/2
        else {
            a = a * a % mod;
            n = n / 2;
            res = modpow(a, n) % mod;
        }

        // Return result
        return res;
    }
}
