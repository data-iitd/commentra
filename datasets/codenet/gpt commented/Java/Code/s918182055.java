import java.util.*;
import java.io.*;
import java.awt.Point;

public class Main {
  
    public static void main(String[] args) {
        // Create a writer to output results
        MyWriter out = new MyWriter(System.out);
        
        // Create a scanner to read input
        MyScanner sc = new MyScanner(System.in);
        
        // Read the number of nodes (N) and the maximum index (M)
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        // Initialize an array of linked lists to store edges
        LinkedList<Integer>[] list = new LinkedList[100001];

        // Read N pairs of integers representing edges
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt(); // Read the first node of the edge
            int b = sc.nextInt(); // Read the second node of the edge
            
            // Initialize the linked list for node 'a' if it is null
            if (list[a] == null) {
                list[a] = new LinkedList<Integer>();
            }
            // Add node 'b' to the adjacency list of node 'a'
            list[a].add(b);
        }
        
        // Variable to store the result of the sum of the largest elements
        int res = 0;
        
        // Priority queue to store the edges in descending order
        PriorityQueue<Integer> pqueue = new PriorityQueue<Integer>(Collections.reverseOrder());
        
        // Iterate through each node from 1 to M
        for (int i = 1; i <= M; i++) {
            // If there are edges for the current node, add them to the priority queue
            if (list[i] != null) {
                pqueue.addAll(list[i]);
            }
            // If the priority queue is not empty, poll the largest element and add it to the result
            if (!pqueue.isEmpty())
                res += pqueue.poll();
        }
        
        // Output the final result
        out.println(res);
        out.flush();
    }
  
    // Custom scanner class for efficient input reading
    static final class MyScanner {
        static final int BUFFER_SIZE = 8192; // Buffer size for reading input
        private final InputStream in; // Input stream
        private final byte[] buffer = new byte[BUFFER_SIZE]; // Buffer to hold bytes
        private int point; // Current position in the buffer
        private int readLength; // Number of bytes read
        
        // Constructor to initialize the scanner with an input stream
        MyScanner(InputStream in) {
            this.in = in;
        }
        
        // Method to read a single byte from the input stream
        private int readByte() {
            if (point < readLength) {
                int result = buffer[point];
                point += 1;
                return result;
            }
            try {
                readLength = in.read(buffer); // Read bytes into the buffer
            } catch (IOException e) {
                throw new AssertionError(null, e);
            }
            if (readLength == -1) {
                return -1; // End of stream
            }
            point = 1; // Reset point for the new buffer
            return buffer[0];
        }
        
        // Method to check if a character is printable (excluding space)
        private static boolean isPrintableCharExceptSpace(int c) {
            return 33 <= c && c <= 126;
        }
        
        // Method to read the next string from the input
        String next() {
            int c = readByte();
            while (!(c == -1 || isPrintableCharExceptSpace(c))) {
                c = readByte(); // Skip non-printable characters
            }
            if (c == -1) {
                throw new NoSuchElementException(); // No more elements
            }
            StringBuilder b = new StringBuilder();
            do {
                b.appendCodePoint(c); // Append the character to the string builder
                c = readByte();
            } while (c != -1 && isPrintableCharExceptSpace(c));
            return b.toString(); // Return the constructed string
        }
        
        // Method to read the next long integer from the input
        long nextLong() {
            int c = readByte();
            while (!(c == -1 || isPrintableCharExceptSpace(c))) {
                c = readByte(); // Skip non-printable characters
            }
            if (c == -1) {
                throw new NoSuchElementException(); // No more elements
            }
            boolean minus = false;
            if (c == '-') {
                minus = true; // Check for negative sign
                c = readByte();
            }
            long result = 0L;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException(); // Invalid input
                }
                result = result * 10L + (c - '0'); // Construct the long value
                c = readByte();
            } while (c != -1 && isPrintableCharExceptSpace(c));
            return minus ? -result : result; // Return the result with sign
        }
        
        // Method to read the next integer from the input
        int nextInt() {
            long n = nextLong(); // Read a long and cast to int
            if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE) {
                throw new InputMismatchException(); // Check for integer overflow
            }
            return (int)n; // Return the integer value
        }
        
        // Method to read the next double from the input
        double nextDouble() {
            return Double.parseDouble(next()); // Parse and return the double value
        }
        
        // Method to read an array of integers from the input
        int[] nextIntArray(int n) {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = nextInt(); // Read each integer into the array
            }
            return result; // Return the array of integers
        }
        
        // Method to check if all arrays have the same length
        private static boolean allSameLength(int[] a, int[] b, int[]... c) {
            if (a.length != b.length) {
                return false; // Check length of first two arrays
            }
            for (int[] element : c) {
                if (a.length != element.length) {
                    return false; // Check length of additional arrays
                }
            }
            return true; // All arrays have the same length
        }
        
        // Overloaded method to check if all char arrays have the same length
        private static boolean allSameLength(char[] a, char[] b, char[]... c) {
            if (a.length != b.length) {
                return false; // Check length of first two arrays
            }
            for (char[] element : c) {
                if (a.length != element.length) {
                    return false; // Check length of additional arrays
                }
            }
            return true; // All arrays have the same length
        }
        
        // Method to read vertical arrays of integers from the input
        void nextVerticalIntArrays(int[] a, int[] b, int[]... c) {
            if (!allSameLength(a, b, c)) {
                throw new IllegalArgumentException(); // Check for consistent lengths
            }
            for (int i = 0; i < a.length; i++) {
                a[i] = nextInt(); // Read integers into the first array
                b[i] = nextInt(); // Read integers into the second array
                for (int[] d : c) {
                    d[i] = nextInt(); // Read integers into additional arrays
                }
            }
        }
        
        // Method to read an array of long integers from the input
        long[] nextLongArray(int n) {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = nextLong(); // Read each long into the array
            }
            return result; // Return the array of long integers
        }
        
        // Method to read the next character from the input
        char nextChar() {
            int c = readByte();
            while (!(c == -1 || isPrintableCharExceptSpace(c))) {
                c = readByte(); // Skip non-printable characters
            }
            if (c == -1) {
                throw new NoSuchElementException(); // No more elements
            }
            return (char)c; // Return the character
        }
        
        // Method to read an array of characters from the input
        char[] nextCharArray(int n) {
            char[] result = new char[n];
            for (int i = 0; i < n; i++) {
                result[i] = nextChar(); // Read each character into the array
            }
            return result; // Return the array of characters
        }
        
        // Method to read a 2D array of characters from the input
        char[][] next2dCharArray(int n, int m) {
            char[][] result = new char[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    result[i][j] = nextChar(); // Read characters into the 2D array
                }
            }
            return result; // Return the 2D array of characters
        }
        
        // Method to read vertical arrays of characters from the input
        void nextVerticalCharArrays(char[] a, char[] b, char[]... c) {
            if (!allSameLength(a, b, c)) {
                throw new IllegalArgumentException(); // Check for consistent lengths
            }
            for (int i = 0; i < a.length; i++) {
                a[i] = nextChar(); // Read characters into the first array
                b[i] = nextChar(); // Read characters into the second array
                for (char[] d : c) {
                    d[i] = nextChar(); // Read characters into additional arrays
                }
            }
        }
    }
    
    // Custom writer class for efficient output
    static final class MyWriter extends PrintWriter {
        MyWriter(OutputStream out) {
            super(out); // Initialize the writer with an output stream
        }
        
        // Method to join and print an array of integers
        void joinAndPrintln(int[] x) {
            joinAndPrintln(x, " "); // Default delimiter is a space
        }
        
        // Method to join and print an array of integers with a specified delimiter
        void joinAndPrintln(int[] x, String delimiter) {
            StringBuilder b = new StringBuilder();
            if (x.length > 0) {
                b.append(x[0]); // Append the first element
                for (int i = 1; i < x.length; i++) {
                    b.append(delimiter).append(x[i]); // Append subsequent elements with delimiter
                }
            }
            println(b.toString()); // Print the joined string
        }
        
        // Method to join and print an array of long integers
        void joinAndPrintln(long[] x) {
            joinAndPrintln(x, " "); // Default delimiter is a space
        }
        
        // Method to join and print an array of long integers with a specified delimiter
        void joinAndPrintln(long[] x, String delimiter) {
            StringBuilder b = new StringBuilder();
            if (x.length > 0) {
                b.append(x[0]); // Append the first element
                for (int i = 1; i < x.length; i++) {
                    b.append(delimiter).append(x[i]); // Append subsequent elements with delimiter
                }
            }
            println(b.toString()); // Print the joined string
        }
        
        // Method to join and print an iterable collection
        void joinAndPrintln(Iterable<?> iterable) {
            joinAndPrintln(iterable, " "); // Default delimiter is a space
        }
        
        // Method to join and print an iterable collection with a specified delimiter
        void joinAndPrintln(Iterable<?> iterable, String delimiter) {
            StringBuilder b = new StringBuilder();
            for (Iterator<?> i = iterable.iterator(); i.hasNext();) {
                b.append(i.next()); // Append each element
                while (i.hasNext()) {
                    b.append(delimiter).append(i.next()); // Append subsequent elements with delimiter
                }
            }
            println(b.toString()); // Print the joined string
        }
    }
}
