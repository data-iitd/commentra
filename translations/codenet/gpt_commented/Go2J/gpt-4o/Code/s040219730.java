import java.io.*;
import java.util.*;

public class Main {
    // Constants used throughout the program
    private static final int MOD = 1000000000 + 7; // Modulus value for calculations
    private static final int ALPHABET_NUM = 26; // Number of letters in the alphabet
    private static final long INF_INT64 = Long.MAX_VALUE; // Maximum int64 value
    private static final int INF_INT32 = Integer.MAX_VALUE; // Maximum int32 value

    static int n, q; // Number of elements and number of queries
    static int[] C; // Array to hold the input values
    static Query[] Q; // Array to hold the queries
    static int[] P = new int[500000 + 50]; // Array to track the last position of each value
    static int[] Answers = new int[500000 + 50]; // Array to hold the answers for each query

    // Query class to hold the details of each query
    static class Query {
        int idx, l, r; // Index, left, and right bounds of the query

        Query(int idx, int l, int r) {
            this.idx = idx;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // Read the number of elements and queries
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        C = new int[n]; // Initialize the array for input values

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            C[i] = Integer.parseInt(st.nextToken()); // Read the slice of integers
        }

        // Initialize the position array with -1 (indicating unvisited)
        Arrays.fill(P, -1);

        // Read each query and store it in the Q array
        Q = new Query[q];
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            Q[i] = new Query(i, l, r); // Create a new query
        }

        // Sort the queries based on the right bound
        Arrays.sort(Q, Comparator.comparingInt(query -> query.r));
        FenwickTree ft = new FenwickTree(500000 + 50); // Initialize a Fenwick Tree for range queries

        int k = 0; // Pointer to track the current position in the input array
        // Process each query
        for (Query query : Q) {
            // Update the Fenwick Tree for all elements up to the right bound of the current query
            while (k < query.r) {
                if (P[C[k]] != -1) { // If the current value has been seen before
                    ft.add(P[C[k]] + 1, -1); // Remove its previous occurrence from the Fenwick Tree
                }
                P[C[k]] = k; // Update the last position of the current value
                ft.add(k + 1, 1); // Add the current value to the Fenwick Tree

                k++; // Move to the next position
            }
            // Calculate the answer for the current query using the Fenwick Tree
            Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
        }

        // Output the answers for all queries
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            sb.append(Answers[i]).append("\n"); // Append each answer
        }
        System.out.print(sb); // Output the answers
    }

    // Fenwick Tree structure for efficient range queries
    static class FenwickTree {
        private int[] dat; // Array to store the tree data
        private int n; // Number of elements

        // Constructor to initialize a new Fenwick Tree
        FenwickTree(int n) {
            this.dat = new int[n + 1]; // Create the data array
            this.n = n; // Set the number of elements
        }

        // Sum calculates the prefix sum from 1 to i (1-based)
        int sum(int i) {
            int s = 0; // Variable to hold the sum
            // Traverse the tree to calculate the sum
            while (i > 0) {
                s += dat[i]; // Add the current index value to the sum
                i -= i & (-i); // Move to the parent index
            }
            return s; // Return the calculated sum
        }

        // Add updates the Fenwick Tree by adding x to the index i (1-based)
        void add(int i, int x) {
            // Update the tree for the given index
            while (i <= n) {
                dat[i] += x; // Add x to the current index
                i += i & (-i); // Move to the next index
            }
        }
    }
}
// <END-OF-CODE>
