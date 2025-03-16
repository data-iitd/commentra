import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
    // Constants for buffer sizes and modulo value
    static final int initialBufSize = 10000;
    static final int maxBufSize = 1000000;
    static final double mod = 1e9 + 7;

    // Scanner for reading input
    static Scanner sc = new Scanner(System.in);

    // Main function
    public static void main(String[] args) {
        // Read an integer N from input
        int N = getInt();
        // Calculate the integer square root of N
        int sqrtN = (int) Math.sqrt(N);

        // Initialize min to N, which will hold the minimum value found
        int min = N;
        // Iterate through all possible divisors of N
        for (int i = 1; i <= sqrtN; i++) {
            // If i is not a divisor of N, skip to the next iteration
            if (N % i != 0) {
                continue;
            }

            // Calculate the value based on the divisor and its complement
            int num = i + (N / i) - 2;
            // Update min if the new value is smaller
            if (num < min) {
                min = num;
            }
        }

        // Print the minimum value found
        System.out.println(min);
    }

    // Graph structure to represent a graph with n nodes
    static class Graph {
        int n;
        List<List<Integer>> edges;

        // NewGraph creates a new graph with n nodes
        Graph(int n) {
            this.n = n;
            this.edges = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                this.edges.add(new ArrayList<>());
            }
        }

        // AddEdge adds an undirected edge between nodes u and v
        void addEdge(int u, int v) {
            this.edges.get(u).add(v);
            this.edges.get(v).add(u);
        }

        // Depth-first search (DFS) algorithm to traverse the graph
        void dfs(int c, boolean[] visited) {
            // Mark the current node as visited
            visited[c] = true;

            // Recursively visit all adjacent nodes
            for (int v : this.edges.get(c)) {
                if (visited[v]) {
                    continue;
                }
                dfs(v, visited);
            }
        }
    }

    // Helper function to read an integer from input
    static int getInt() {
        return sc.nextInt();
    }

    // Helper function to read a string from input
    static String getString() {
        return sc.next();
    }

    // Function to return the absolute value of an integer
    static int abs(int a) {
        return Math.abs(a);
    }

    // Function to compute p raised to the power of q
    static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // Function to compute (n^p) % mod using exponentiation by squaring
    static int powMod(int n, int p) {
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            int t = powMod(n, p / 2);
            return (int) ((t * t) % mod);
        } else {
            return (int) ((n * powMod(n, p - 1)) % mod);
        }
    }

    // Function to find the minimum value among a variable number of integers
    static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    // Function to find the maximum value among a variable number of integers
    static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    // Function to check if a string exists in a list of strings
    static boolean strSearch(List<String> a, String b) {
        return a.contains(b);
    }

    // Function to print an integer array in a formatted way
    static void printIntArray(int[] array) {
        System.out.println(Arrays.toString(array));
    }

    // Function to calculate x % mod
    static int calcMod(int x) {
        return x % mod;
    }

    // Function to reverse a string
    static String reverse(String s) {
        char[] chars = s.toCharArray();
        for (int i = 0, j = chars.length - 1; i < j; i++, j--) {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
        }
        return new String(chars);
    }

    // Function to check if a number is prime
    static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }

        // Check for factors from 3 to the square root of n
        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

