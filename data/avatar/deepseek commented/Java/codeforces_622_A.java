import java.io.*; 
import java.util.*; 

public class Main { 
    public static final int BUFFERSIZE = 512000; 
    
    // Step 2: Define the Scanner and PrintWriter for input and output operations.
    private static Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in), BUFFERSIZE)); 
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out, BUFFERSIZE)); 
    
    // Step 3: Implement the solve method to find the position of a given value in a sequence.
    public static void solve() { 
        long position = sc.nextLong(); 
        long nrstSeqStartIndx = 1; 
        
        // Step 4: Find the starting index of the sequence where the position might be located.
        while (getValueAtIndex(nrstSeqStartIndx * 2) < position) { 
            nrstSeqStartIndx *= 2; 
        } 
        
        // Step 4: Find the exact position within the sequence.
        while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) { 
            nrstSeqStartIndx++; 
        } 
        
        long startIndex = getValueAtIndex(nrstSeqStartIndx); 
        out.println((position - startIndex) + 1); 
    } 
    
    // Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
    public static long getValueAtIndex(long index) { 
        return 1 + ((index - 1) * index / 2); 
    } 
    
    // Step 5: Implement the main method to initialize the input and call the solve method.
    public static void main(String args[]) throws Exception { 
        // Step 7: Initialize the input reader for the in class.
        in.init(System.in); 
        solve(); 
        out.close(); 
    } 
    
    // Step 7: Implement the in class to handle input operations.
    public static class in { 
        static BufferedReader reader; 
        static StringTokenizer tokenizer; 
        
        static void init(InputStream input) { 
            reader = new BufferedReader(new InputStreamReader(input), BUFFERSIZE); 
            tokenizer = new StringTokenizer(""); 
        } 
        
        static String next() throws IOException { 
            while (!tokenizer.hasMoreTokens()) { 
                tokenizer = new StringTokenizer(reader.readLine()); 
            } 
            return tokenizer.nextToken(); 
        } 
        
        static int nextInt() throws IOException { 
            return Integer.parseInt(next()); 
        } 
        
        static double nextDouble() throws IOException { 
            return Double.parseDouble(next()); 
        } 
        
        static long nextLong() throws IOException { 
            return Long.parseLong(next()); 
        } 
    } 
}
