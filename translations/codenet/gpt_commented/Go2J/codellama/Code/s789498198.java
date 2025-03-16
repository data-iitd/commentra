
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Read two integers from input
        int[] AB = sc.nextInts();
        int A = AB[0];
        int B = AB[1];

        // Check if the sum of A and B is even
        if ((A+B)%2 == 0) {
            // If even, print the average
            System.out.println((A + B) / 2);
            return;
        }
        // If odd, print "IMPOSSIBLE"
        System.out.println("IMPOSSIBLE");
    }

    static class sc {
        static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer st = new StringTokenizer("");

        static String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(r.readLine());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        static int nextInt() {
            return Integer.parseInt(next());
        }

        static int[] nextInts() {
            String[] s = next().split(" ");
            int[] res = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                res[i] = Integer.parseInt(s[i]);
            }
            return res;
        }
    }

    // digits returns the number of digits in an integer
    static int digits(int x) {
        return String.valueOf(x).length();
    }

    // powInt calculates x raised to the power of p
    static int powInt(int x, int p) {
        int result = 1;
        for (int i = 0; i < p; i++) {
            result *= x;
        }
        return result;
    }

    // max returns the maximum of two integers
    static int max(int x, int y) {
        return Math.max(x, y);
    }

    // min returns the minimum of two integers
    static int min(int x, int y) {
        return Math.min(x, y);
    }

    // abs returns the absolute value of an integer
    static int abs(int x) {
        return Math.abs(x);
    }

    // varDump prints the values of variables for debugging
    static void varDump(Object... value) {
        for (Object v : value) {
            System.err.println(v);
        }
    }

    // yes prints "Yes" to the output
    static void yes() {
        System.out.println("Yes");
    }

    // no prints "No" to the output
    static void no() {
        System.out.println("No");
    }

    // Pair struct to hold a pair of integers
    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // Queue struct to implement a queue of pairs
    static class Queue {
        Pair[] v;

        Queue() {
            v = new Pair[0];
        }

        void push(Pair v) {
            this.v = append(this.v, v);
        }

        Pair pop() {
            Pair r = v[0];
            v = remove(v, 0);
            return r;
        }

        Pair front() {
            return v[0];
        }

        boolean empty() {
            return v.length == 0;
        }

        private Pair[] append(Pair[] v, Pair p) {
            Pair[] res = new Pair[v.length + 1];
            for (int i = 0; i < v.length; i++) {
                res[i] = v[i];
            }
            res[v.length] = p;
            return res;
        }

        private Pair[] remove(Pair[] v, int i) {
            Pair[] res = new Pair[v.length - 1];
            for (int j = 0; j < i; j++) {
                res[j] = v[j];
            }
            for (int j = i + 1; j < v.length; j++) {
                res[j - 1] = v[j];
            }
            return res;
        }
    }

    // END-OF-CODE
}