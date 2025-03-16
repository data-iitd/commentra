import java.util.*;
import java.io.*;

class Main {
    // Array to keep track of the counter values for each node
    static int[] counter;
    // Adjacency list representation of the graph
    static List<List<Integer>> graph;

    public static void main(String[] args) {
        // Initialize FastScanner for input reading
        FastScanner fs = new FastScanner();
        // Read the number of nodes (n) and the number of queries (q)
        int n = fs.nextInt();
        int q = fs.nextInt();
        
        // Initialize the graph with n empty lists
        graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new LinkedList<>());

        // Initialize the counter array to store values for each node
        counter = new int[n];
        Integer a, b;

        // Read the edges of the graph and populate the adjacency list
        for (int i = 0; i < n - 1; i++) {
            a = fs.nextInt() - 1; // Read node a (0-indexed)
            b = fs.nextInt() - 1; // Read node b (0-indexed)
            graph.get(a).add(b);  // Add edge from a to b
            graph.get(b).add(a);  // Add edge from b to a (undirected graph)
        }

        // Process each query to update the counter for specific nodes
        for (int i = 0; i < q; i++) {
            counter[fs.nextInt() - 1] += fs.nextInt(); // Update the counter for the specified node
        }

        // Perform DFS to propagate the counter values through the graph
        dfs(0, -1, 0);

        // Prepare the output as a space-separated string of counter values
        StringJoiner sj = new StringJoiner(" ");
        for (int i = 0; i < n; i++) {
            sj.add(String.valueOf(counter[i])); // Add each counter value to the output
        }
        // Print the final counter values for each node
        System.out.println(sj.toString());
    }

    // Depth-First Search (DFS) to propagate values from parent to child nodes
    static void dfs(int v, int par, long val) {
        // Iterate through each adjacent node
        for (Integer i : graph.get(v)) {
            // Avoid traversing back to the parent node
            if (i != par) {
                // Recursive DFS call with updated value
                dfs(i, v, val + counter[v]);
            }
        }
        // Update the counter for the current node
        counter[v] += val;
    }

    // FastScanner class for efficient input reading
    static class FastScanner {
        private final InputStream in = System.in; // Input stream
        private final byte[] buffer = new byte[1024]; // Buffer for reading input
        private int ptr = 0; // Pointer for the current position in the buffer
        private int buflen = 0; // Length of the buffer

        // Check if there is a next byte available in the buffer
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true; // There are bytes available
            } else {
                ptr = 0; // Reset pointer
                try {
                    buflen = in.read(buffer); // Read new bytes into the buffer
                } catch (IOException e) {
                    e.printStackTrace();
                }
                return buflen > 0; // Return true if bytes were read
            }
        }

        // Read the next byte from the buffer
        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1; // Return -1 if no more bytes are available
        }

        // Check if a character is printable
        private boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126; // ASCII range for printable characters
        }

        // Check if there is a next printable character
        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; // Skip non-printable characters
            return hasNextByte(); // Return true if there is a next printable character
        }

        // Read the next string from the input
        public String next() {
            if (!hasNext()) throw new NoSuchElementException(); // Throw exception if no next element
            StringBuilder sb = new StringBuilder(); // StringBuilder for constructing the string
            int b = readByte(); // Read the first byte
            while (isPrintableChar(b)) { // Continue reading while the character is printable
                sb.appendCodePoint(b); // Append the character to the StringBuilder
                b = readByte(); // Read the next byte
            }
            return sb.toString(); // Return the constructed string
        }

        // Read the next long integer from the input
        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException(); // Throw exception if no next element
            long n = 0; // Initialize the number
            boolean minus = false; // Flag for negative numbers
            int b = readByte(); // Read the first byte
            if (b == '-') { // Check for negative sign
                minus = true; // Set the flag
                b = readByte(); // Read the next byte
            }
            // Validate the first character
            if (b < '0' || '9' < b) {
                throw new NumberFormatException(); // Throw exception if not a valid number
            }
            // Read the number
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10; // Shift left
                    n += b - '0'; // Add the digit
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n; // Return the number with sign
                } else {
                    throw new NumberFormatException(); // Throw exception for invalid number
                }
                b = readByte(); // Read the next byte
            }
        }

        // Read the next integer from the input
        public int nextInt() {
            long nl = nextLong(); // Read long and cast to int
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException(); // Validate range
            return (int) nl; // Return the integer
        }

        // Read the next double from the input
        public double nextDouble() {
            return Double.parseDouble(next()); // Parse and return the double
        }
    }
}
