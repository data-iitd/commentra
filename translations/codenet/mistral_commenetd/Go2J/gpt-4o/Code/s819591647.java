// ProblemB.java
// This is the main file for problem B solution

import java.io.*;
import java.util.*;

public class ProblemB {

    private static final int constMod = (int) (1e9 + 7); // Constants definition
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Standard input reader
    private static PrintWriter wr = new PrintWriter(System.out); // Standard output writer

    // -----------------------------------------

    // Function definitions

    private static int getInt() throws IOException { // Function to read an integer from standard input
        return Integer.parseInt(br.readLine());
    }

    private static int[] getIntArray(int n) throws IOException { // Function to read n integers and return an array
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    // -----------------------------------------

    // Mathematical functions

    private static int numAbs(int x) { // Function to get absolute value of an integer
        return x < 0 ? -x : x;
    }

    private static int numGcd(int a, int b) { // Function to calculate the greatest common divisor of a and b
        return b == 0 ? a : numGcd(b, a % b);
    }

    // -----------------------------------------

    // Main function

    private static void solve() throws IOException { // Function to solve the problem
        int n = getInt();
        int m = getInt();
        int[] a = getIntArray(n);

        int sum = 0;
        for (int v : a) {
            sum += v;
        }

        int count = 0;
        double rate = (double) sum / (4 * m);
        for (int v : a) {
            if ((double) v >= rate) {
                count++;
            }
        }

        if (count >= m) {
            wr.println("Yes");
        } else {
            wr.println("No");
        }
    }

    // -----------------------------------------

    public static void main(String[] args) throws IOException { // Main function
        solve();
        wr.flush();
    }
}

// <END-OF-CODE>
