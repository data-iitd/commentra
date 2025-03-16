
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Read two integers A and B from standard input
        int[] AB = sc.nextInts();
        int A = AB[0];
        int B = AB[1];

        // Check if the sum of A and B is even
        if ((A+B)%2 == 0) {
            // If even, print the average of A and B
            System.out.println((A + B) / 2);
            return;
        }
        // If not even, print "IMPOSSIBLE"
        System.out.println("IMPOSSIBLE");
    }

    // Initialize the scanner with default settings
    static Scanner sc = new Scanner(System.in);

    // Scanner type for reading input efficiently
    static class Scanner {
        BufferedReader r;
        StringTokenizer st;

        Scanner(InputStreamReader isr) {
            r = new BufferedReader(isr);
        }

        // Read a line of input and split it into tokens
        void readln() {
            try {
                st = new StringTokenizer(r.readLine());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

        // Check if the current cursor position is beyond the buffer length
        boolean isFull() {
            return st.countTokens() == 0;
        }

        // Reset the cursor position to the beginning of the buffer
        void resetCur() {
            st = new StringTokenizer("");
        }

        // Get the next token from the buffer
        String next() {
            if (st.countTokens() == 0) {
                readln();
            }
            return st.nextToken();
        }

        // Get all remaining tokens as a slice of strings
        String[] nexts() {
            readln();
            resetCur();
            return st.getTokenArray();
        }

        // Get the next token as an integer
        int nextInt() {
            if (st.countTokens() == 0) {
                readln();
            }
            return Integer.parseInt(st.nextToken());
        }

        // Get all remaining tokens as a slice of integers
        int[] nextInts() {
            readln();
            int[] res = new int[st.countTokens()];
            for (int i = 0; i < res.length; i++) {
                res[i] = Integer.parseInt(st.nextToken());
            }
            resetCur();
            return res;
        }

        // Get the next token as a float
        double nextFloat() {
            if (st.countTokens() == 0) {
                readln();
            }
            return Double.parseDouble(st.nextToken());
        }

        // Get all remaining tokens as a slice of floats
        double[] nextFloats() {
            readln();
            double[] res = new double[st.countTokens()];
            for (int i = 0; i < res.length; i++) {
                res[i] = Double.parseDouble(st.nextToken());
            }
            resetCur();
            return res;
        }

        // Calculate the number of digits in an integer
        int digits(int x) {
            return String.valueOf(x).length();
        }

        // Calculate x raised to the power of p
        int powInt(int x, int p) {
            int result = 1;
            for (int i = 0; i < p; i++) {
                result *= x;
            }
            return result;
        }

        // Return the maximum of two integers
        int max(int x, int y) {
            return Math.max(x, y);
        }

        // Return the minimum of two integers
        int min(int x, int y) {
            return Math.min(x, y);
        }

        // Return the absolute value of an integer
        int abs(int x) {
            return Math.abs(x);
        }

        // Print the variable in a debug-friendly format
        void varDump(Object... value) {
            for (Object v : value) {
                System.err.println(v);
            }
        }

        // Print "Yes" to standard output
        void yes() {
            System.out.println("Yes");
        }

        // Print "No" to standard output
        void no() {
            System.out.println("No");
        }

        // Pair struct to hold two integers
        static class Pair {
            int first;
            int second;

            Pair(int first, int second) {
                this.first = first;
                this.second = second;
            }
        }

        // Queue struct to hold a slice of Pairs
        static class Queue {
            Pair[] v;

            Queue(int size) {
                v = new Pair[size];
            }

            // Push a Pair onto the queue
            void push(Pair v) {
                this.v[this.v.length - 1] = v;
            }

            // Pop a Pair from the front of the queue
            Pair pop() {
                Pair r = this.v[0];
                for (int i = 0; i < this.v.length - 1; i++) {
                    this.v[i] = this.v[i + 1];
                }
                return r;
            }

            // Get the front Pair of the queue without removing it
            Pair front() {
                return this.v[0];
            }

            // Check if the queue is empty
            boolean empty() {
                return this.v.length == 0;
            }
        }
    }

    // Print the variable in a debug-friendly format
    static void varDump(Object... value) {
        for (Object v : value) {
            System.err.println(v);
        }
    }

    // Print "Yes" to standard output
    static void yes() {
        System.out.println("Yes");
    }

    // Print "No" to standard output
    static void no() {
        System.out.println("No");
    }

    // Pair struct to hold two integers
    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // Queue struct to hold a slice of Pairs
    static class Queue {
        Pair[] v;

        Queue(int size) {
            v = new Pair[size];
        }

        // Push a Pair onto the queue
        void push(Pair v) {
            this.v[this.v.length - 1] = v;
        }

        // Pop a Pair from the front of the queue
        Pair pop() {
            Pair r = this.v[0];
            for (int i = 0; i < this.v.length - 1; i++) {
                this.v[i] = this.v[i + 1];
            }
            return r;
        }

        // Get the front Pair of the queue without removing it
        Pair front() {
            return this.v[0];
        }

        // Check if the queue is empty
        boolean empty() {
            return this.v.length == 0;
        }
    }
}

