import java.util.*;
import java.io.*;

public class Main {
    // Initialize FastScanner object for reading input
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        
        // Read the number of elements in the array 'a' from the input
        int n = fs.nextInt();
        
        // Allocate memory for the array 'a' of size 'n'
        int[] a = new int[n];
        
        // Read 'n' integers from the input and store them in the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }
        
        // Sort the array 'a' in ascending order using Arrays.sort() method
        Arrays.sort(a);
        
        // Initialize variables 'sum' and 'count'
        long sum = 0;
        int count = 0;
        
        // Iterate through the array 'a' from index 0 to n-2
        for(int i=0;i<n-1;i++){
            // Add the current element to the sum
            sum+=a[i];
            
            // Check if the next element is less than or equal to 2 times the sum
            if(a[i+1]<=2*sum){
                // If yes, increment the count
                count++;
            }else{
                // If no, reset the count to 0
                count = 0;
            }
        }
        
        // Print the final answer
        System.out.println(count+1);
    }

    // Custom FastScanner class for reading input efficiently
    static class FastScanner {
        // Initialize input stream and buffer
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        
        // Check if there is a next byte to read
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            }else{
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
        
        // Read a single byte
        private int readByte() {
            if (hasNextByte()) return buffer[ptr++]; else return -1;
        }
        
        // Check if the current byte is printable
        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }
        
        // Check if there is a next token (string) to read
        public boolean hasNext() {
            while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
        }
        
        // Read a string token
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        
        // Read a long integer
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
            while(true){
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                }else if(b == -1 || !isPrintableChar(b)){
                    return minus ? -n : n;
                }else{
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }
        
        // Read an integer
        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }
        
        // Read a double
        public double nextDouble() { return Double.parseDouble(next());}
    }
}