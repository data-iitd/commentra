import java.util.*;
import java.io.*;

public class Main {
    //=====I/O=====
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    // Function to read an integer from input.
    static int readInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    // Function to read a 64-bit integer from input.
    static long readLong() throws IOException {
        return Long.parseLong(br.readLine());
    }

    // Function to read a list of integers from input.
    static int[] readInts(int n) throws IOException {
        int[] res = new int[n];
        String[] tokens = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            res[i] = Integer.parseInt(tokens[i]);
        }
        return res;
    }

    // Function to read a single line of text from input.
    static String readText() throws IOException {
        return br.readLine();
    }

    // Function to print a list of integers, separated by spaces.
    static void printInts(int... a) {
        for (int i = 0; i < a.length; i++) {
            pw.print(a[i]);
            if (i != a.length - 1) {
                pw.print(" ");
            }
        }
        pw.println();
        pw.flush();
    }

    //=====main=====

    // The main function of the program.
    public static void main(String[] args) throws IOException {
        // Read the number of elements.
        int n = readInt();

        // Read n integers into an array.
        int[] c = readInts(n);

        // Initialize the answer variable.
        long ans = 0;

        // Sort the array of integers.
        Arrays.sort(c);

        // Calculate the answer based on the sorted array.
        for (int i = 0; i < n; i++) {
            ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
        }

        // Print the final answer, multiplied by 4^(n-1) modulo mod.
        pw.println(ans * modPow(4, n - 1) % mod);
        pw.flush();
    }

    // Define the constant for modular arithmetic.
    static final int mod = 1000000007;

    // Function to perform modular exponentiation.
    static long modPow(int a, int n) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * a % mod;
            }
            a = (int) ((long) a * a % mod);
            n >>= 1;
        }
        return res;
    }
}
