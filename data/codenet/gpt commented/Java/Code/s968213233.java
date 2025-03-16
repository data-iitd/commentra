import java.util.*;
import java.io.*;

public class Main {

    // Constructor for the Main class that processes input and computes the result
    public Main(FastScanner in, PrintWriter out, int test) {
        // Read the number of elements
        int N = in.nextInt();
        int[] A = new int[N];
        
        // Read the elements into the array A
        for (int i = 0; i < N; i++)
            A[i] = in.nextInt();
        
        // Sort the array A in ascending order
        Arrays.sort(A);

        // Initialize the result variable to accumulate the final result
        long res = 0;

        // Create a priority queue to manage pairs of integers
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt((int[] e) -> Math.min(e[0], e[1])).reversed());
        
        // Add the largest element as a pair to the priority queue
        q.add(new int[]{A[N - 1], A[N - 1]});

        // Iterate through the sorted array from the second largest element to the smallest
        for (int i = N - 2; i >= 0; i--) {
            int a = A[i];
            // Remove the pair with the minimum value from the priority queue
            int[] place = q.remove();
            
            // Add the minimum of the removed pair to the result
            res += Math.min(place[0], place[1]);
            
            // Add new pairs to the priority queue with the current element
            q.add(new int[]{place[0], a});
            q.add(new int[]{a, place[1]});
        }
        
        // Output the final result
        out.println(res);
    }

    // Main method to run the program
    public static void main(String[] args) {
        // Create a PrintWriter to output results
        PrintWriter out = new PrintWriter(System.out);
        
        // Initialize FastScanner for input
        FastScanner in = new FastScanner(System.in);

        // Loop for the number of test cases (currently set to 1)
        for (int t = 1; t <= 1; t++) {
            // Create an instance of Main to process the input
            Main sol = new Main(in, out, t);
        }

        // Close the PrintWriter
        out.close();
    }
}

// FastScanner class for efficient input reading
class FastScanner {
    private InputStream stream; // Input stream for reading data
    private byte[] buf = new byte[1024]; // Buffer for reading data
    private int curChar; // Current character index in the buffer
    private int numChars; // Number of characters read into the buffer

    // Constructor for FastScanner
    public FastScanner(InputStream stream) {
        this.stream = stream;
    }

    // Method to read a single byte from the input stream
    int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf); // Read data into the buffer
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1; // End of stream
        }
        return buf[curChar++]; // Return the current byte
    }

    // Check if the character is a space character
    boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    // Check if the character is an endline character
    boolean isEndline(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }

    // Method to read the next integer from the input
    int nextInt() {
        return Integer.parseInt(next());
    }

    // Method to read the next long from the input
    long nextLong() {
        return Long.parseLong(next());
    }

    // Method to read the next double from the input
    double nextDouble() {
        return Double.parseDouble(next());
    }

    // Method to read the next token as a string
    String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read(); // Skip space characters
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c); // Append the character to the result
            c = read();
        } while (!isSpaceChar(c)); // Continue until a space character is found
        return res.toString(); // Return the accumulated string
    }

    // Method to read the next line as a string
    String nextLine() {
        int c = read();
        while (isEndline(c))
            c = read(); // Skip endline characters
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c); // Append the character to the result
            c = read();
        } while (!isEndline(c)); // Continue until an endline character is found
        return res.toString(); // Return the accumulated string
    }
}
