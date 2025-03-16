import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Initialize FastScanner to read input efficiently
        FastScanner fs = new FastScanner();
        
        // Read the number of elements
        int n = fs.nextInt();
        int[] a = new int[n];
        
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }
        
        // Sort the array in ascending order
        Arrays.sort(a);
        
        // Initialize variables to calculate the sum and count of valid elements
        long sum = 0;
        int count = 0;
        
        // Iterate through the sorted array to find the count of valid elements
        for(int i = 0; i < n - 1; i++) {
            // Accumulate the sum of elements
            sum += a[i];
            
            // Check if the next element is less than or equal to twice the current sum
            if(a[i + 1] <= 2 * sum) {
                count++; // Increment count if condition is met
            } else {
                count = 0; // Reset count if condition is not met
            }
        }
        
        // Output the result, adding 1 to count to include the last element
        System.out.println(count + 1);
    }

    // FastScanner class for efficient input reading
    static class FastScanner {
        private final InputStream in = System.in; // Input stream
        private final byte[] buffer = new byte[1024]; // Buffer for reading input
        private int ptr = 0; // Pointer for current position in buffer
        private int buflen = 0; // Length of the buffer
        
        // Check if there are more bytes to read
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true; // Return true if there are bytes left
            } else {
                ptr = 0; // Reset pointer
                try {
                    buflen = in.read(buffer); // Read new bytes into buffer
                } catch (IOException e) {
                    e.printStackTrace(); // Handle IOException
                }
                if (buflen <= 0) {
                    return false; // Return false if no bytes were read
                }
            }
            return true; // Return true if bytes are available
        }
        
        // Read the next byte from the buffer
        private int readByte() { 
            if (hasNextByte()) return buffer[ptr++]; 
            else return -1; // Return -1 if no more bytes
        }
        
        // Check if a character is printable
        private static boolean isPrintableChar(int c) { 
            return 33 <= c && c <= 126; 
        }
        
        // Check if there are more printable characters
        public boolean hasNext() { 
            while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; 
            return hasNextByte(); 
        }
        
        // Read the next string from input
        public String next() {
            if (!hasNext()) throw new NoSuchElementException(); // Handle no more elements
            StringBuilder sb = new StringBuilder(); // StringBuilder to construct the string
            int b = readByte(); // Read the first byte
            while(isPrintableChar(b)) { // Continue while the byte is printable
                sb.appendCodePoint(b); // Append the byte to the StringBuilder
                b = readByte(); // Read the next byte
            }
            return sb.toString(); // Return the constructed string
        }
        
        // Read the next long integer from input
        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException(); // Handle no more elements
            long n = 0; // Initialize number
            boolean minus = false; // Flag for negative numbers
            int b = readByte(); // Read the first byte
            if (b == '-') { // Check for negative sign
                minus = true; // Set flag for negative
                b = readByte(); // Read the next byte
            }
            if (b < '0' || '9' < b) { // Validate the first character
                throw new NumberFormatException(); // Handle invalid number format
            }
            while(true) {
                if ('0' <= b && b <= '9') { // Check if the byte is a digit
                    n *= 10; // Multiply current number by 10
                    n += b - '0'; // Add the digit to the number
                } else if(b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n; // Return the number, negating if necessary
                } else {
                    throw new NumberFormatException(); // Handle invalid number format
                }
                b = readByte(); // Read the next byte
            }
        }
        
        // Read the next integer from input
        public int nextInt() {
            long nl = nextLong(); // Read long and cast to int
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException(); // Validate range
            return (int) nl; // Return the integer value
        }
        
        // Read the next double from input
        public double nextDouble() { 
            return Double.parseDouble(next()); // Parse and return the next double
        }
    }
}
