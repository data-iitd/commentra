
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

class s521372598 {
    public static void main(String[] args) {
        // s521372598 function
        solve(); // Call the solve function
    }

    static void solve() {
        // Function to solve the problem
        Scanner scanner = new Scanner(System.in); // Create a new Scanner with standard input as the source
        int n = scanner.nextInt(); // Read the number of elements in the array
        int[] as = new int[n]; // Initialize an array as of size n
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt(); // Read the array elements and assign them to the corresponding indices in the array
        }
        int[] xs = new int[n]; // Initialize an array xs of size n
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1; // Assign the value xs[i] = as[i] - i + 1
        }
        Arrays.sort(xs); // Sort the array xs in ascending order
        int b = xs[n / 2]; // Assign the middle element of the sorted array xs to variable b
        int ans = 0; // Initialize variable ans with 0
        for (int x : xs) {
            ans += Math.abs(x - b); // Calculate the absolute difference between each element and b and add it to ans
        }
        System.out.println(ans); // Print the answer
    }
}

// -----------------------------------------

class FastScanner {
    // Class to read input from standard input
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        // Check if there is a byte available in the buffer
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

    private int readByte() {
        // Read a byte from the input stream
        if (hasNextByte()) {
            return buffer[ptr++];
        } else {
            return -1;
        }
    }

    private static boolean isPrintableChar(int c) {
        // Check if a character is printable
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        // Check if there is a next token available
        while (hasNextByte() &&!isPrintableChar(buffer[ptr])) {
            ptr++;
        }
        return hasNextByte();
    }

    public String next() {
        // Read the next token from the input stream
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        // Read a long value from the input stream
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
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
            } else if (b == -1 ||!isPrintableChar(b)) {
                return minus? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        // Read an integer value from the input stream
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
            throw new NumberFormatException();
        }
        return (int) nl;
    }

    public double nextDouble() {
        // Read a double value from the input stream
        return Double.parseDouble(next());
    }
}

// -----------------------------------------

class FastWriter {
    // Class to write output to standard output
    private final OutputStream out = System.out;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private static final int AUTO_FLUSH_THRETHOLD = 1 << 17;

    public void flush() {
        // Flush the writer buffer
        try {
            out.write(buffer, 0, ptr);
            out.flush();
            ptr = 0;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void println(String s) {
        // Write a string to the output stream and flush the buffer
        println(s.getBytes());
    }

    public void println(char[] s) {
        // Write a character array to the output stream and flush the buffer
        println(String.valueOf(s));
    }

    public void println(int x) {
        // Write an integer to the output stream and flush the buffer
        println(String.valueOf(x));
    }

    public void println(long x) {
        // Write a long to the output stream and flush the buffer
        println(String.valueOf(x));
    }

    public void println(double x) {
        // Write a double to the output stream and flush the buffer
        println(String.valueOf(x));
    }

    public void println() {
        // Write a new line to the output stream and flush the buffer
        println("");
    }

    public void println(byte[] x) {
        // Write a byte array to the output stream and flush the buffer
        println(String.valueOf(x));
    }

    private void println(String s) {
        // Write a string to the output stream and flush the buffer
        if (s.length() == 0) {
            println();
        } else {
            ptr += s.length();
            System.arraycopy(s.getBytes(), 0, buffer, ptr, s.length());
            ptr += s.length();
            if (ptr == AUTO_FLUSH_THRETHOLD) {
                flush();
            }
            buffer[ptr++] = (byte) '\n';
        }
    }
}