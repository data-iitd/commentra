import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Create an instance of FastScanner to read input efficiently
        FastScanner fs = new FastScanner();
        
        // Read the size of the array
        int n = fs.nextInt();
        
        // Initialize the array with the size read
        int[] a = new int[n];
        
        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }
        
        // Sort the array in ascending order
        Arrays.sort(a);
        
        // Initialize sum to accumulate the sum of elements and count to count valid subsequences
        long sum = 0;
        int count = 0;
        
        // Iterate through the array to find valid subsequences
        for(int i=0; i<n-1; i++){
            // Add the current element to the sum
            sum += a[i];
            
            // Check if the next element is less than or equal to twice the sum
            if(a[i+1] <= 2*sum){
                // Increment the count if the condition is met
                count++;
            } else {
                // Reset the count if the condition is not met
                count = 0;
            }
        }
        
        // Print the final count plus one, as the last subsequence is always valid
        System.out.println(count + 1);
    }

    // FastScanner class to read input efficiently
    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        
        // Method to check if there is a next byte to read
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
        
        // Method to read the next byte
        private int readByte() { 
            if (hasNextByte()) 
                return buffer[ptr++]; 
            else 
                return -1;
        }
        
        // Method to check if a character is printable
        private static boolean isPrintableChar(int c) { 
            return 33 <= c && c <= 126;
        }
        
        // Method to check if there is a next element
        public boolean hasNext() { 
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) 
                ptr++; 
            return hasNextByte();
        }
        
        // Method to read the next string
        public String next() {
            if (!hasNext()) 
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        
        // Method to read the next long
        public long nextLong() {
            if (!hasNext()) 
                throw new NoSuchElementException();
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
        
        // Method to read the next int
        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) 
                throw new NumberFormatException();
            return (int) nl;
        }
        
        // Method to read the next double
        public double nextDouble() { 
            return Double.parseDouble(next());
        }
    }
}
