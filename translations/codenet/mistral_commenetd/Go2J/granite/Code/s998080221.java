
// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

// bufio.NewReader is used for reading lines from os.Stdin
class bufReader {
    BufferedReader r;
    StringTokenizer st;

    // Constructor to initialize bufReader with os.Stdin
    bufReader() {
        r = new BufferedReader(new InputStreamReader(System.in));
    }

    // Function next returns the next token (i.e., a word or a number) from the input
    String next() {
        // If the tokenizer st has more tokens, return the next token
        if (st.hasMoreTokens()) {
            return st.nextToken();
        }
        // Read a line from the input and initialize the tokenizer st with the line
        try {
            st = new StringTokenizer(r.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
        // Return the next token
        return st.nextToken();
    }

    // Function nextInt returns the next integer from the input
    int nextInt() {
        // Return the integer value of the next token
        return Integer.parseInt(next());
    }

    // Function nextLine returns the next line from the input
    String nextLine() {
        // Read a line from the input and return it
        try {
            return r.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        // Return an empty string if an error occurs
        return "";
    }
}

// bufio.PrintWriter is used for writing lines to os.Stdout
class bufWriter {
    PrintWriter w;

    // Constructor to initialize bufWriter with os.Stdout
    bufWriter() {
        w = new PrintWriter(System.out);
    }

    // Function println is used for writing a line to the output
    void println(String s) {
        // Write the line to the output
        w.println(s);
        // Flush the output to ensure it is written immediately
        w.flush();
    }
}

// Function main is the entry point of the program
public class s998080221{
    //bufReader and bufWriter are instances of bufReader and bufWriter classes
    static bufReader reader = new bufReader();
    static bufWriter writer = new bufWriter();

    // Function main reads input from the input, processes it, and writes the output to the output
    public static void main(String[] args) {
        // Call the solve function to solve the problem
        solve();
    }

    // Function solve reads input from the input, processes it, and writes the output to the output
    static void solve() {
        // Read two integers N and K from the input
        int N = reader.nextInt();
        int K = reader.nextInt();
        // Initialize an array A of size N
        int[] A = new int[N];
        // Read N integers from the input and store them in the array A
        for (int i = 0; i < N; i++) {
            A[i] = reader.nextInt();
        }
        // Initialize variables maxProfit, maxCnt, and maxA
        int maxProfit = 0;
        int maxCnt = 0;
        int maxA = A[N - 1];
        // Iterate through the array A from the last index to the first index
        for (int i = N - 2; i >= 0; i--) {
            // Calculate the profit of the current transaction
            int profit = Math.max(0, maxA - A[i]);
            // If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
            if (maxProfit < profit) {
                maxProfit = profit;
                maxCnt = 1;
            } else if (maxProfit == profit) {
                maxCnt++;
            }
            // Update maxA with the maximum of the current element and maxA
            maxA = Math.max(maxA, A[i]);
        }
        // Write the output to the output
        writer.println(maxCnt);
    }
}

