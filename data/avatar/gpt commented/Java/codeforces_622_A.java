import java.io.*; 
import java.util.*; 

public class Main {
    // Define a constant for the buffer size used in input and output operations
    public static final int BUFFERSIZE = 512000; 
    
    // Initialize a Scanner for reading input with a buffered reader for efficiency
    private static Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in), BUFFERSIZE)); 
    
    // Initialize a PrintWriter for output with a buffered output stream for efficiency
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out, BUFFERSIZE)); 
    
    // Method to solve the main problem
    public static void solve() {
        // Read the position from input
        long position = sc.nextLong(); 
        
        // Initialize the nearest sequence start index
        long nrstSeqStartIndx = 1; 
        
        // Find the nearest sequence start index such that its value is less than the position
        while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
            nrstSeqStartIndx *= 2; 
        }
        
        // Increment the nearest sequence start index until its value exceeds the position
        while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
            nrstSeqStartIndx++; 
        }
        
        // Get the starting index value for the nearest sequence
        long startIndex = getValueAtIndex(nrstSeqStartIndx); 
        
        // Output the result, which is the difference between the position and the start index plus one
        out.println((position - startIndex) + 1); 
    } 
    
    // Method to calculate the value at a given index based on a specific formula
    public static long getValueAtIndex(long index) {
        return 1 + ((index - 1) * index / 2); 
    } 
    
    // Main method to execute the program
    public static void main(String args[]) throws Exception {
        // Initialize the input reader
        in.init(System.in); 
        
        // Call the solve method to process the input and produce output
        solve(); 
        
        // Close the output stream
        out.close(); 
    } 
    
    // Static inner class for handling input operations
    public static class in {
        static BufferedReader reader; // BufferedReader for reading input
        static StringTokenizer tokenizer; // Tokenizer for parsing input
        
        // Method to initialize the input reader
        static void init(InputStream input) {
            reader = new BufferedReader(new InputStreamReader(input), BUFFERSIZE); 
            tokenizer = new StringTokenizer(""); 
        } 
        
        // Method to get the next token from input
        static String next() throws IOException {
            // Ensure there are tokens available to read
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine()); 
            }
            return tokenizer.nextToken(); 
        } 
        
        // Method to get the next integer from input
        static int nextInt() throws IOException {
            return Integer.parseInt(next()); 
        } 
        
        // Method to get the next double from input
        static double nextDouble() throws IOException {
            return Double.parseDouble(next()); 
        } 
        
        // Method to get the next long from input
        static long nextLong() throws IOException {
            return Long.parseLong(next()); 
        } 
    }
}
