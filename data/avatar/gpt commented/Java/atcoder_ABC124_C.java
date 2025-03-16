import java.io.OutputStream; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.StringTokenizer; 
import java.io.BufferedReader; 
import java.io.InputStreamReader; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        
        // Create an InputReader to read input from the input stream
        InputReader in = new InputReader(inputStream); 
        
        // Create a PrintWriter to write output to the output stream
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Instantiate the solver class for the problem
        CColoringColorfully solver = new CColoringColorfully(); 
        
        // Solve the problem for the first test case
        solver.solve(1, in, out); 
        
        // Close the output stream
        out.close(); 
    } 
    
    static class CColoringColorfully { 
        public void solve(int testNumber, InputReader in, PrintWriter out) { 
            // Read the input string
            String x = in.next(); 
            
            // Create two StringBuilders to manipulate the string
            StringBuilder a = new StringBuilder(x); 
            StringBuilder b = new StringBuilder(x); 
            
            // Initialize counters for the number of changes made
            int a1 = 0; 
            int a2 = 0; 
            
            // First pass: modify 'a' from left to right
            for (int i = 1; i < x.length(); i++) { 
                // Check if the current character is the same as the previous one
                if (a.charAt(i) == a.charAt(i - 1)) { 
                    // Change the character to the opposite value
                    if (a.charAt(i) == '1') 
                        a.setCharAt(i, '0'); 
                    else 
                        a.setCharAt(i, '1'); 
                    
                    // Increment the change counter
                    a1++; 
                } 
            } 
            
            // Second pass: modify 'b' from right to left
            for (int i = x.length() - 1; i > 0; i--) { 
                // Check if the current character is the same as the previous one
                if (b.charAt(i) == b.charAt(i - 1)) { 
                    // Change the previous character to the opposite value
                    if (b.charAt(i - 1) == '1') 
                        b.setCharAt(i - 1, '0'); 
                    else 
                        b.setCharAt(i - 1, '1'); 
                    
                    // Increment the change counter
                    a2++; 
                } 
            } 
            
            // Output the minimum number of changes made in either pass
            out.println(Math.min(a1, a2)); 
        } 
    } 
    
    static class InputReader { 
        public BufferedReader reader; 
        public StringTokenizer tokenizer; 
        
        // Constructor to initialize the InputReader with an InputStream
        public InputReader(InputStream stream) { 
            reader = new BufferedReader(new InputStreamReader(stream), 32768); 
            tokenizer = null; 
        } 
        
        // Method to read the next token from input
        public String next() { 
            // Ensure there are tokens available to read
            while (tokenizer == null || !tokenizer.hasMoreTokens()) { 
                try { 
                    // Read a new line and tokenize it
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) { 
                    throw new RuntimeException(e); 
                } 
            } 
            // Return the next token
            return tokenizer.nextToken(); 
        } 
    } 
}
