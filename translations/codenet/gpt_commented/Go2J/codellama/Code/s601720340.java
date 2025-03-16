
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

    private static final int magic = 1000000007;

    private static int N;
    private static int[] p;

    private static int find(int n) {
        for (int i = 0; i < N; i++) {
            if (n == p[i]) {
                return 0; // Number found
            }
        }
        return 1; // Number not found
    }

    private static void solve() {
        Io io = new Io(); // Create a new IO instance for input/output
        io.nextInt(); // Read an integer
        N = io.nextInt(); // Read the size of the array
        p = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = io.nextInt(); // Read integers into the array p
        }
        for (int i = 0; i <= 100; i++) {
            if (find(N - i) == 1) { // Check N - i
                System.out.println(N - i); // Print the result
                System.exit(0); // Exit the program
            }
            if (find(N + i) == 1) { // Check N + i
                System.out.println(N + i); // Print the result
                System.exit(0); // Exit the program
            }
        }
    }

    public static void main(String[] args) {
        solve(); // Call the solve function
    }

    static class Io {

        private BufferedReader reader;
        private String[] tokens;
        private int nextToken;

        Io() {
            reader = new BufferedReader(new InputStreamReader(System.in)); // Initialize reader
        }

        int nextInt() {
            return Integer.parseInt(next()); // Convert the next token to int
        }

        String next() {
            while (nextToken >= tokens.length) {
                try {
                    tokens = reader.readLine().split(" "); // Read a line
                } catch (IOException e) {
                    e.printStackTrace(); // Log any error
                    System.exit(1); // Exit on error
                }
                nextToken = 0; // Reset token index
            }
            String r = tokens[nextToken]; // Get the next token
            nextToken++; // Move to the next token
            return r; // Return the token
        }
    }

    static class Log {

        static void log(String name, Object value) {
            System.err.printf("%s=%+v\n", name, value); // Log the value to stderr
        }

        static void logf(String format, Object... a) {
            System.err.printf(format, a); // Log formatted output to stderr
        }
    }

    static class Math {

        static int intMin(int a, int b) {
            if (a < b) {
                return a;
            }
            return b;
        }

        static int intMax(int a, int b) {
            if (a > b) {
                return a;
            }
            return b;
        }

        static int combination(int n, int m) {
            if (m > n) {
                return 0; // Not possible to choose more than available
            } else if (m == n || m == 0) {
                return 1; // Only one way to choose all or none
            } else {
                int res = 1;
                for (int i = 0; i < m; i++) {
                    res *= (n - i); // Calculate numerator
                }
                for (int i = 1; i <= m; i++) {
                    res /= i; // Calculate denominator
                }
                return res; // Return the combination result
            }
        }

        static int lucas(int n, int m, int p) {
            int ntemp = n;
            int mtemp = m;
            int res = 1;
            for (int i = 0; i < 100; i++) {
                int nreminder = ntemp % p; // Remainder of n
                ntemp = ntemp / p; // Update n
                int mreminder = mtemp % p; // Remainder of m
                mtemp = mtemp / p; // Update m
                res = res * (combination(nreminder, mreminder) % p); // Combine results
                if (ntemp == 0) {
                    break; // Break if n is exhausted
                }
            }
            return res % p; // Return the result modulo p
        }

        static int combMod(int n, int m, int p) {
            return lucas(n, m, p); // Call lucas function
        }
    }

    static class Bfs {

        static void bfs(int start, Map<Integer, List<Integer>> nodes, Consumer<Integer> fn) {
            Queue<Integer> frontier = new ArrayDeque<>(); // Initialize the frontier with the start node
            Map<Integer, Boolean> visited = new HashMap<>(); // Track visited nodes

            frontier.add(start); // Add the start node to the frontier
            visited.put(start, true); // Mark the start node as visited

            while (!frontier.isEmpty()) {
                int next = frontier.poll(); // Get the next node
                fn.accept(next); // Execute the provided function on the node
                for (int n : bfsFrontier(next, nodes, visited)) {
                    if (!visited.containsKey(n)) {
                        frontier.add(n); // Add unvisited neighbors to the frontier
                    }
                }
            }
        }

        static List<Integer> bfsFrontier(int node, Map<Integer, List<Integer>> nodes, Map<Integer, Boolean> visited) {
            List<Integer> next = new ArrayList<>();
            for (int n : nodes.get(node)) {
                if (!visited.containsKey(n)) {
                    next.add(n); // Add unvisited neighbor to the list
                }
            }
            return next; // Return the list of unvisited neighbors
        }
    }

    static class Dfs {

        static void dfs(int start, Map<Integer, List<Integer>> nodes, Consumer<Integer> fn) {
            dfsRecur(start, nodes, new HashMap<>(), fn); // Start the recursive DFS
        }

        static void dfsRecur(int node, Map<Integer, List<Integer>> nodes, Map<Integer, Boolean> visited, Consumer<Integer> fn) {
            visited.put(node, true); // Mark the node as visited
            fn.accept(node); // Execute the provided function on the node
            for (int n : nodes.get(node)) {
                if (!visited.containsKey(n)) {
                    dfsRecur(n, nodes, visited, fn); // Recursively visit unvisited neighbors
                }
            }
        }
    }

    static class Dfs2 {

        static void dfs2(int node, Map<Integer, List<Integer>> nodes, BiConsumer<Integer, Integer> fn1, BiConsumer<Integer, Integer> fn2) {
            dfs2Recur(node, -1, nodes, new HashMap<>(), fn1, fn2); // Start the recursive DFS with parent tracking
        }

        static void dfs2Recur(int node, int parent, Map<Integer, List<Integer>> nodes, Map<Integer, Boolean> visited, BiConsumer<Integer, Integer> fn1, BiConsumer<Integer, Integer> fn2) {
            visited.put(node, true); // Mark the node as visited
            if (fn1 != null) {
                fn1.accept(node, parent); // Execute the first function
            }
            for (int n : nodes.get(node)) {
                if (!visited.containsKey(n)) {
                    dfs2Recur(n, node, nodes, visited, fn1, fn2); // Recursively visit unvisited neighbors
                }
            }
            if (fn2 != null) {
                fn2.accept(node, parent); // Execute the second function
            }
        }
    }

    static class Stack {

        private Element top;
        private int size;

        int len() {
            return size; // Return the size of the stack
        }

        void push(int value) {
            top = new Element(value, top); // Create a new element and set it as the top
            size++; // Increment the size
        }

        int pop() {
            if (size > 0) {
                int value = top.value; // Get the top value
                top = top.next; // Update the top pointer
                size--; // Decrement the size
                return value; // Return the value
            }
            return -1; // Return -1 if the stack is empty
        }

        static class Element {

            int value;
            Element next;

            Element(int value, Element next) {
                this.value = value;
                this.next = next;
            }
        }
    }

    static class Power {

        static int powerInt(int n, int p) {
            int tmp = 1;
            for (int i = 0; i < n; i++) {
                tmp *= p; // Calculate p^n
            }
            return tmp; // Return the result
        }
    }

    static class Divisors {

        static void findDivisors(int n, List<Integer> a) {
            if (n == 1) {
                return; // 1 has no divisors
            }

            int sqrt = (int) Math.sqrt(n); // Calculate the square root of n
            for (int i = 2; i <= sqrt; i++) {
                if (n % i == 0) {
                    a.add(i); // Append divisor i
                    a.add(n / i); // Append corresponding divisor n/i
                }
            }
            a.add(n); // Append n itself as a divisor
        }
    }

    static class RemoveDuplicate {

        static List<Integer> removeDuplicate(List<Integer> a) {
            Map<Integer, Boolean> m = new HashMap<>(); // Create a map to track unique values
            for (int i = 0; i < a.size(); i++) {
                m.put(a.get(i), true); // Mark each value as seen
            }
            List<Integer> res = new ArrayList<>();
            for (int i : m.keySet()) {
                res.add(i); // Append unique values to the result list
            }
            return res; // Return the list of unique values
        }
    }

    static class Abs {

        static int abs(int a) {
            if (a > 0) {
                return a; // Return a if positive
            }
            return -a; // Return -a if negat