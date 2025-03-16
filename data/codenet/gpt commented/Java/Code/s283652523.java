import java.io.*;
import java.util.*;
import java.math.BigDecimal;

@SuppressWarnings("unused")
public class Main {
    // Scanner for input and PrintWriter for output
    FastScanner in;
    PrintWriter out;
    final static int MOD = (int)1e9+7; // Define a constant for modulo operation
    
    // Method to solve the main problem
    void solve(){
        // Read the number of elements
        int N = in.nextInt();
        // Read the array of integers
        int[] A = in.nextIntArray(N);
        
        long ans = 0; // Variable to store the final answer
        long sum = A[N-1]; // Initialize sum with the last element of the array
        
        // Iterate through the array from the second last element to the first
        for(int i = N - 2; i >= 0; i--){
            // Update the answer with the product of current element and the accumulated sum
            ans += (sum * A[i]) % MOD;
            ans %= MOD; // Ensure the answer stays within the modulo
            sum += A[i]; // Update the sum with the current element
            sum %= MOD; // Ensure the sum stays within the modulo
        }
        
        // Print the final answer
        out.println(ans);
    }
    
    // Main method to start the program
    public static void main(String[] args) {
        new Main().m(); // Create an instance of Main and call method m
    }
    
    // Method to initialize input and output streams and call the solve method
    private void m() {
        in = new FastScanner(System.in); // Initialize FastScanner for standard input
        out = new PrintWriter(System.out); // Initialize PrintWriter for standard output
        
        /*
        // Uncomment this block to write output to a file instead of standard output
        try {
            String path = "input.txt";
            out = new PrintWriter(new BufferedWriter(new FileWriter(new File(path))));
        }catch (IOException e){
            e.printStackTrace();
        }
        */
        
        solve(); // Call the solve method to execute the main logic
        out.flush(); // Flush the output stream to ensure all data is written
        in.close(); // Close the input stream
        out.close(); // Close the output stream
    }
    
    // FastScanner class for efficient input reading
    static class FastScanner {
        private Reader input; // Reader for input
        
        // Constructor to initialize FastScanner with standard input
        public FastScanner() {this(System.in);}
        
        // Constructor to initialize FastScanner with a specific InputStream
        public FastScanner(InputStream stream) {this.input = new BufferedReader(new InputStreamReader(stream));}
        
        // Method to close the input stream
        public void close() {
            try {
                this.input.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        
        // Method to read the next integer from input
        public int nextInt() {
            long nl = nextLong(); // Read a long value
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException(); // Check for integer overflow
            return (int) nl; // Cast to int and return
        }
        
        // Method to read the next long value from input
        public long nextLong() {
            try {
                int sign = 1; // Variable to store the sign of the number
                int b = input.read(); // Read the first character
                // Skip non-digit characters
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                // Determine the sign of the number
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                long ret = b - '0'; // Initialize the result with the first digit
                // Read subsequent digits
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) return ret * sign; // Return the result if a non-digit is encountered
                    ret *= 10; // Shift left
                    ret += b - '0'; // Add the next digit
                }
            } catch (IOException e) {
                e.printStackTrace();
                return -1; // Return -1 in case of an error
            }
        }
        
        // Method to read the next double value from input
        public double nextDouble() {
            try {
                double sign = 1; // Variable to store the sign of the number
                int b = input.read(); // Read the first character
                // Skip non-digit characters
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                // Determine the sign of the number
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                double ret = b - '0'; // Initialize the result with the first digit
                // Read subsequent digits
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) break; // Break if a non-digit is encountered
                    ret *= 10; // Shift left
                    ret += b - '0'; // Add the next digit
                }
                // Check for decimal point
                if (b != '.') return sign * ret; // Return if no decimal point
                double div = 1; // Variable for division
                b = input.read(); // Read the next character
                // Read digits after the decimal point
                while ('0' <= b && b <= '9') {
                    ret *= 10; // Shift left
                    ret += b - '0'; // Add the next digit
                    div *= 10; // Update the divisor
                    b = input.read(); // Read the next character
                }
                return sign * ret / div; // Return the final result
            } catch (IOException e) {
                e.printStackTrace();
                return Double.NaN; // Return NaN in case of an error
            }
        }
        
        // Method to read the next character from input
        public char nextChar() {
            try {
                int b = input.read(); // Read the next character
                // Skip whitespace characters
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                return (char) b; // Return the character
            } catch (IOException e) {
                e.printStackTrace();
                return 0; // Return 0 in case of an error
            }
        }
        
        // Method to read the next string from input
        public String nextStr() {
            try {
                StringBuilder sb = new StringBuilder(); // StringBuilder to construct the string
                int b = input.read(); // Read the first character
                // Skip whitespace characters
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                // Read characters until whitespace is encountered
                while (b != -1 && !Character.isWhitespace(b)) {
                    sb.append((char) b); // Append character to StringBuilder
                    b = input.read(); // Read the next character
                }
                return sb.toString(); // Return the constructed string
            } catch (IOException e) {
                e.printStackTrace();
                return ""; // Return an empty string in case of an error
            }
        }
        
        // Method to read an array of integers from input
        public int[] nextIntArray(int n) {
            int[] res = new int[n]; // Initialize the array
            for (int i = 0; i < n; i++) {
                res[i] = nextInt(); // Fill the array with integers
            }
            return res; // Return the array
        }
        
        // Method to read an array of integers and decrement each by 1
        public int[] nextIntArrayDec(int n) {
            int[] res = new int[n]; // Initialize the array
            for (int i = 0; i < n; i++) {
                res[i] = nextInt() - 1; // Fill the array with decremented integers
            }
            return res; // Return the array
        }
        
        // Method to read an array of integers with 1-based indexing
        public int[] nextIntArray1Index(int n) {
            int[] res = new int[n + 1]; // Initialize the array with an extra space
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextInt(); // Fill the array with integers starting from index 1
            }
            return res; // Return the array
        }
        
        // Method to read an array of long values from input
        public long[] nextLongArray(int n) {
            long[] res = new long[n]; // Initialize the array
            for (int i = 0; i < n; i++) {
                res[i] = nextLong(); // Fill the array with long values
            }
            return res; // Return the array
        }
        
        // Method to read an array of long values and decrement each by 1
        public long[] nextLongArrayDec(int n) {
            long[] res = new long[n]; // Initialize the array
            for (int i = 0; i < n; i++) {
                res[i] = nextLong() - 1; // Fill the array with decremented long values
            }
            return res; // Return the array
        }
        
        // Method to read an array of long values with 1-based indexing
        public long[] nextLongArray1Index(int n) {
            long[] res = new long[n + 1]; // Initialize the array with an extra space
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextLong(); // Fill the array with long values starting from index 1
            }
            return res; // Return the array
        }
        
        // Method to read an array of double values from input
        public double[] nextDoubleArray(int n) {
            double[] res = new double[n]; // Initialize the array
            for (int i = 0; i < n; i++) {
                res[i] = nextDouble(); // Fill the array with double values
            }
            return res; // Return the array
        }
    }
}
