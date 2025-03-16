import java.util.*;
import java.io.*;

public class Main {
    // Constant for modulo operation
    public static final long MOD = 1000000007;

    public static void main(String[] args) {
        // Initialize FastScanner for input reading and PrintWriter for output
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        // Variable declarations
        Integer i, j, k, n = 0, m = 0, h = 0, w = 0, ans = 0;
        long a = 0, b = 0, c = 0, d = 0, x = 0, y = 0, z = 0;
        
        // Lists to store integers, strings, and pairs
        List<Integer> l = new ArrayList<>();
        List<String> s = new ArrayList<>();
        List<Pair> p = new ArrayList<>();

        // Read the number of elements
        n = sc.nextInt();

        // Read n integers from input and add them to the list
        for (i = 0; i < n; i++) {
            l.add(sc.nextInt());
        }

        // Sort the list of integers
        Collections.sort(l);

        // Print the difference between the two middle elements in the sorted list
        print(l.get(n / 2) - l.get(n / 2 - 1));

        // Flush the output
        out.flush();
    }

    // Method to print an object to the console
    private static void print(Object o) {
        System.out.println(o.toString());
    }

    // Method to calculate the least common multiple (LCM) of two numbers
    private static long lcm(long m, long n) {
        return m * n / gcd(m, n);
    }

    // Method to calculate the greatest common divisor (GCD) of two numbers
    private static long gcd(long m, long n) {
        if (m < n) return gcd(n, m); // Ensure m is greater than n
        if (n == 0) return m; // Base case for recursion
        return gcd(n, m % n); // Recursive call
    }

    // Pair class to hold key-value pairs
    private static class Pair {
        private int key; // Key of the pair
        private int value; // Value of the pair

        // Constructor to initialize key and value
        public Pair(int key, int value) {
            this.key = key;
            this.value = value;
        }

        // Getter for value
        public int getValue() {
            return this.value;
        }

        // Getter for key
        public int getKey() {
            return this.key;
        }
    }
}

// FastScanner class for efficient input reading
class FastScanner {
    private final InputStream in = System.in; // Input stream
    private final byte[] buffer = new byte[1024]; // Buffer for reading input
    private int ptr = 0; // Pointer for current position in buffer
    private int buflen = 0; // Length of the buffer

    // Check if there is a next byte to read
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true; // There are bytes left in the buffer
        } else {
            ptr = 0; // Reset pointer
            try {
                buflen = in.read(buffer); // Read new bytes into buffer
            } catch (IOException e) {
                e.printStackTrace(); // Handle IO exceptions
            }
            if (buflen <= 0) {
                return false; // No more bytes to read
            }
        }
        return true; // Bytes available
    }

    // Read a single byte from the buffer
    private int readByte() {
        if (hasNextByte()) return buffer[ptr++]; // Return byte and increment pointer
        else return -1; // No byte available
    }

    // Check if a character is printable
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126; // ASCII range for printable characters
    }

    // Check if there is a next printable character
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; // Skip non-printable characters
        return hasNextByte(); // Return if there is a next printable character
    }

    // Read the next string from input
    public String next() {
        if (!hasNext()) throw new NoSuchElementException(); // Check for next element
        StringBuilder sb = new StringBuilder(); // StringBuilder for building the string
        int b = readByte(); // Read first byte
        while (isPrintableChar(b)) { // While the byte is printable
            sb.appendCodePoint(b); // Append byte to StringBuilder
            b = readByte(); // Read next byte
        }
        return sb.toString(); // Return the constructed string
    }

    // Read the next long value from input
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException(); // Check for next element
        long n = 0; // Initialize number
        boolean minus = false; // Flag for negative numbers
        int b = readByte(); // Read first byte
        if (b == '-') { // Check for negative sign
            minus = true; // Set negative flag
            b = readByte(); // Read next byte
        }
        if (b < '0' || '9' < b) { // Check if the byte is a digit
            throw new NumberFormatException(); // Throw exception if not a digit
        }
        while (true) {
            if ('0' <= b && b <= '9') { // While the byte is a digit
                n *= 10; // Multiply current number by 10
                n += b - '0'; // Add digit to number
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n; // Return the number, negated if necessary
            } else {
                throw new NumberFormatException(); // Throw exception for invalid input
            }
            b = readByte(); // Read next byte
        }
    }

    // Read the next integer value from input
    public int nextInt() {
        long nl = nextLong(); // Read long value
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException(); // Check range
        return (int) nl; // Cast to int and return
    }

    // Read the next double value from input
    public double nextDouble() {
        return Double.parseDouble(next()); // Parse and return double
    }
}
