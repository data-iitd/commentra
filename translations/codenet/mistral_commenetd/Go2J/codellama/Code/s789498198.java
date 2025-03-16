
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    // Initialize scanner and read the first line
    static {
        sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        sc.readln(); // Read the first line
    }

    // Main function
    public static void main(String[] args) {
        // Read the first two integers from the input
        int[] AB = sc.nextInts();
        int A = AB[0];
        int B = AB[1];

        // Check if the sum of A and B is even
        if ((A + B) % 2 == 0) {
            // If it is, print the result (the average)
            System.out.println((A + B) / 2);
            return;
        }
        // If the sum is odd, print "IMPOSSIBLE"
        System.out.println("IMPOSSIBLE");
    }

    // Scanner class
    public static class Scanner {

        // Fields
        private String[] buf;
        private int cur;
        private BufferedReader r;

        // Constructor
        public Scanner(BufferedReader r) {
            this.r = r;
        }

        // Function to read a line
        public void readln() {
            String rbuf = "";
            try {
                while (true) {
                    String line = r.readLine();
                    if (line == null) {
                        break;
                    }
                    rbuf += line;
                    if (!line.endsWith("\n")) {
                        break;
                    }
                }
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
            cur = 0;
            buf = rbuf.split(" ");
        }

        // Function to check if the scanner is full
        public boolean isFull() {
            return cur == buf.length;
        }

        // Function to reset the current index
        public void resetCur() {
            cur = 0;
        }

        // Function to read next string
        public String next() {
            if (cur == 0) {
                readln();
            }
            String res = buf[cur];
            cur++;
            if (isFull()) {
                resetCur();
            }
            return res;
        }

        // Function to read next integers
        public int[] nextInts() {
            readln();
            int[] res = new int[buf.length];
            for (int i = 0; i < buf.length; i++) {
                res[i] = Integer.parseInt(buf[i]);
            }
            resetCur();
            return res;
        }

        // Function to calculate the number of digits in an integer
        public int digits(int x) {
            return String.valueOf(x).length();
        }

        // Function to calculate the power of a number
        public int powInt(int x, int p) {
            int result = 1;
            for (int i = 0; i < p; i++) {
                result *= x;
            }
            return result;
        }

        // Function to find the maximum of two integers
        public int max(int x, int y) {
            return Math.max(x, y);
        }

        // Function to find the minimum of two integers
        public int min(int x, int y) {
            return Math.min(x, y);
        }

        // Function to calculate the absolute value of an integer
        public int abs(int x) {
            return Math.abs(x);
        }

        // Function to print the values of variables
        public void varDump(Object... value) {
            for (Object v : value) {
                System.err.println(v);
            }
        }

        // Function to print "Yes"
        public void yes() {
            System.out.println("Yes");
        }

        // Function to print "No"
        public void no() {
            System.out.println("No");
        }

        // Pair class
        public static class Pair {

            // Fields
            public int first;
            public int second;

            // Constructor
            public Pair(int first, int second) {
                this.first = first;
                this.second = second;
            }
        }

        // Queue class
        public static class Queue {

            // Fields
            public Pair[] v;

            // Constructor
            public Queue() {
                v = new Pair[0];
            }

            // Function to push a pair into the queue
            public void push(Pair v) {
                this.v = append(this.v, v);
            }

            // Function to pop a pair from the queue
            public Pair pop() {
                Pair r = v[0];
                v = remove(v, 0);
                return r;
            }

            // Function to get the front pair from the queue
            public Pair front() {
                return v[0];
            }

            // Function to check if the queue is empty
            public boolean empty() {
                return v.length == 0;
            }

            // Function to append a pair to an array
            public static Pair[] append(Pair[] v, Pair p) {
                Pair[] res = new Pair[v.length + 1];
                for (int i = 0; i < v.length; i++) {
                    res[i] = v[i];
                }
                res[v.length] = p;
                return res;
            }

            // Function to remove a pair from an array
            public static Pair[] remove(Pair[] v, int i) {
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
    }
}

