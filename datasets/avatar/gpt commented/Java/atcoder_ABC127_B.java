import java.io.*; 
import java.nio.CharBuffer; 
import java.util.NoSuchElementException; 

public class Main { 
    public static void main(String[] args) { 
        // Create a SimpleScanner instance to read input from the standard input stream
        SimpleScanner scanner = new SimpleScanner(System.in); 
        
        // Create a PrintWriter instance to output results to the standard output stream
        PrintWriter writer = new PrintWriter(System.out); 
        
        // Read integer values for r and d, and a long value for x from the input
        int r = scanner.nextInt(); 
        int d = scanner.nextInt(); 
        long x = scanner.nextLong(); 
        
        // Perform the calculation and output the result 10 times
        for (int i = 0; i < 10; ++i) { 
            // Update x according to the formula x = r * x - d
            x = r * x - d; 
            // Print the updated value of x
            writer.println(x); 
        } 
        
        // Close the PrintWriter to release resources
        writer.close(); 
    } 
    
    // A custom scanner class to read input efficiently
    private static class SimpleScanner { 
        // Define a buffer size for reading input
        private static final int BUFFER_SIZE = 10240; 
        
        // Declare variables for input stream, character buffer, and end-of-file flag
        private Readable in; 
        private CharBuffer buffer; 
        private boolean eof; 
        
        // Constructor to initialize the scanner with an InputStream
        SimpleScanner(InputStream in) { 
            // Wrap the input stream in a BufferedReader for efficient reading
            this.in = new BufferedReader(new InputStreamReader(in)); 
            buffer = CharBuffer.allocate(BUFFER_SIZE); 
            buffer.limit(0); 
            eof = false; 
        } 
        
        // Method to read a single character from the input
        private char read() { 
            // If the buffer is empty, refill it
            if (!buffer.hasRemaining()) { 
                buffer.clear(); 
                int n; 
                try { 
                    n = in.read(buffer); 
                } catch (IOException e) { 
                    n = -1; 
                } 
                // If no characters were read, set eof flag and return null character
                if (n <= 0) { 
                    eof = true; 
                    return '\0'; 
                } 
                buffer.flip(); 
            } 
            // Return the next character from the buffer
            return buffer.get(); 
        } 
        
        // Method to check if the end of the input has been reached
        void checkEof() { 
            if (eof) throw new NoSuchElementException(); 
        } 
        
        // Method to read the next character, ensuring EOF is checked
        char nextChar() { 
            checkEof(); 
            char b = read(); 
            checkEof(); 
            return b; 
        } 
        
        // Method to read the next token as a String
        String next() { 
            char b; 
            // Skip any whitespace characters
            do { 
                b = read(); 
                checkEof(); 
            } while (Character.isWhitespace(b)); 
            
            StringBuilder sb = new StringBuilder(); 
            // Append characters until a whitespace or EOF is encountered
            do { 
                sb.append(b); 
                b = read(); 
            } while (!eof && !Character.isWhitespace(b)); 
            
            return sb.toString(); 
        } 
        
        // Method to read the next integer from the input
        int nextInt() { 
            return Integer.valueOf(next()); 
        } 
        
        // Method to read the next long value from the input
        long nextLong() { 
            return Long.valueOf(next()); 
        } 
        
        // Method to read the next double value from the input
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
    } 
}
