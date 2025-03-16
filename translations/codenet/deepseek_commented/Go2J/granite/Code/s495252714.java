
import java.util.*;
import java.io.*;

public class s495252714{
    //=====I/O=====

    // Initialize buffered reader and writer for efficient I/O operations.
    static Scanner sc = new Scanner(System.in);
    static PrintWriter wr = new PrintWriter(System.out);

    // Function to scan an integer from input.
    static int scanInt() {
        return Integer.parseInt(sc.next());
    }

    // Function to scan a 64-bit integer from input.
    static long scanInt64() {
        return Long.parseLong(sc.next());
    }

    // Function to scan a list of integers from input.
    static int[] scanInts(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) { res[i] = scanInt(); }
        return res;
    }

    // Function to scan a single line of text from input.
    static String scanText() {
        return sc.nextLine();
    }

    // Function to print a list of integers, separated by spaces.
    static void printInts(int[] a) {
        for (int i = 0; i < a.length; i++) {
            wr.print(a[i]);
            if (i!= a.length - 1) { wr.print(" "); }
        }
        wr.println();
        wr.flush();
    }

    //=====main=====

    // The main function of the program.
    public static void main(String[] args) {
        // Read the number of elements.
        int n = scanInt();

        // Read n integers into a list.
        int[] c = scanInts(n);

        // Initialize the answer variable.
        long ans = 0;

        // Sort the list of integers.
        Arrays.sort(c);

        // Calculate the answer based on the sorted list.
        for (int i = 0; i < n; i++) {
            ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
        }

        // Print the final answer, multiplied by 4^(n-1) modulo mod.
        wr.println(ans * modpow(4, n - 1) % mod);
    }

    // Define the constant for modular arithmetic.
    static final int mod = 1000000007;

    // Function to perform modular exponentiation.
    static int modpow(int a, int n) {
        int res = 1;
        for (; n > 0; n >>= 1) {
            if (n % 2 == 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
        }
        return res;
    }
}

// End of code.