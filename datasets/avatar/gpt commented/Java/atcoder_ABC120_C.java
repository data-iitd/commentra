import java.io.OutputStream; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.Vector; 
import java.util.StringTokenizer; 
import java.io.IOException; 
import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.util.Stack; 
import java.io.InputStream; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        InputReader in = new InputReader(inputStream); 
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of TaskB and solve the problem
        TaskB solver = new TaskB(); 
        solver.solve(1, in, out); 
        
        // Close the output stream
        out.close(); 
    } 
    
    static class TaskB { 
        public void solve(int testNumber, InputReader in, PrintWriter out) { 
            // Read the input string
            String x = in.next(); 
            Stack<Character> s = new Stack<>(); 
            int c = 0; // Counter for pairs of '0' and '1'
            
            // Iterate through each character in the input string
            for (int i = 0; i < x.length(); i++) { 
                // Push the current character onto the stack
                s.push(x.charAt(i)); 
                
                // Process the stack while there are at least two characters
                while (s.size() > 1) { 
                    Character p = s.pop(); // Pop the top character
                    Character q = s.pop(); // Pop the next character
                    
                    // Check if the characters form a pair of '0' and '1'
                    if ((p == '1' && q == '0') || (p == '0' && q == '1')) { 
                        c++; // Increment the counter for valid pairs
                        continue; // Continue to check for more pairs
                    } else { 
                        // If not a valid pair, push the characters back onto the stack
                        s.push(q); 
                        s.push(p); 
                        break; // Exit the while loop
                    } 
                } 
            } 
            // Output the result, which is twice the count of pairs found
            out.println(c * 2); 
        } 
    } 
    
    static class InputReader { 
        public BufferedReader reader; 
        public StringTokenizer tokenizer; 
        
        public InputReader(InputStream stream) { 
            // Initialize the BufferedReader and StringTokenizer
            reader = new BufferedReader(new InputStreamReader(stream), 32768); 
            tokenizer = null; 
        } 
        
        public String next() { 
            // Read the next token from the input
            while (tokenizer == null || !tokenizer.hasMoreTokens()) { 
                try { 
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) { 
                    throw new RuntimeException(e); 
                } 
            } 
            return tokenizer.nextToken(); 
        } 
    } 
}
