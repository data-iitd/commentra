import java.util.*;
import java.io.*;

public class Main {
    // Define the modulo constant
    public static final long MOD = 1000000007;

    public static void main(String[] args) {
        // Initialize the FastScanner for fast input reading
        FastScanner sc = new FastScanner();
        // Initialize the PrintWriter for efficient output
        PrintWriter out = new PrintWriter(System.out);
        
        // Declare variables for various types
        Integer i, j, k, n = 0, m = 0, h = 0, w = 0, ans = 0;
        long a = 0, b = 0, c = 0, d = 0, x = 0, y = 0, z = 0;
        List<Integer> l = new ArrayList<>();
        List<String> s = new ArrayList<>();
        List<Pair> p = new ArrayList<>();

        // Read the number of elements
        n = sc.nextInt();

        // Read n integers into the list l
        for (i = 0; i < n; i++) {
            l.add(sc.nextInt());
        }

        // Sort the list l in ascending order
        Collections.sort(l);

        // Calculate and print the difference between the middle elements of the sorted list
        print(l.get(n / 2) - l.get(n / 2 - 1));

        // Flush the output to ensure all data is written to the standard output
        out.flush();
    }

    // Utility method to print any object to the standard output
    private static void print(Object o) {
        System.out.println(o.toString());
    }

    // Method to calculate the least common multiple of two numbers
    private static long lcm(long m, long n) {
        return m * n / gcd(m, n);
    }

    // Method to calculate the greatest common divisor of two numbers using the Euclidean algorithm
    private static long gcd(long m, long n) {
        if (m < n) return gcd(n, m);
        if (n == 0) return m;
        return gcd(n, m % n);
    }

    // Simple class to represent key-value pairs
    private static class Pair {
        private int key;
        private int value;

        public Pair(int key, int value) {
            this.key = key;
            this.value = value;
        }

        public int getValue() {
            return this.value;
        }

        public int getKey() {
            return this.key;
        }
    }
}

// FastScanner class for fast input reading
class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    // Check if there is a next byte to read
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    // Read the next byte
    private int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    // Check if the given character is printable
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    // Check if there is a next input
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    // Read the next string
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    // Read the next long integer
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    // Read the next integer
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }

    // Read the next double
    public double nextDouble() {
        return Double.parseDouble(next());
    }
}
