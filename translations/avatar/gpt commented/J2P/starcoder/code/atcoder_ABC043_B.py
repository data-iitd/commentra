import java.io.OutputStream; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.io.UncheckedIOException; 
import java.util.StringTokenizer; 
import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.io.InputStream; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        
        // Initialize the LightScanner for reading input
        LightScanner in = new LightScanner(inputStream); 
        
        // Initialize PrintWriter for output
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of the problem solver
        BUnhappyHackingABCEdit solver = new BUnhappyHackingABCEdit(); 
        
        // Solve the problem for the first test case
        solver.solve(1, in, out); 
        
        // Close the output stream
        out.close(); 
    } 

    // Class to solve the B Unhappy Hacking problem
    static class BUnhappyHackingABCEdit { 
        public void solve(int testNumber, LightScanner in, PrintWriter out) { 
            // Read the input string
            String s = in.string(); 
            // StringBuilder to construct the output string
            StringBuilder d = new StringBuilder(); 
            
            // Process each character in the input string
            for (char c : s.toCharArray()) { 
                switch (c) { 
                    case '0': 
                        // Append '0' to the output
                        d.append("0"); 
                        break; 
                    case '1': 
                        // Append '1' to the output
                        d.append("1"); 
                        break; 
                    case 'B': 
                        // Handle the 'B' character by removing the last character if possible
                        if (d.length() > 0) { 
                            d.setLength(d.length() - 1); // Remove the last character
                            d.trimToSize(); // Adjust the size of the StringBuilder
                        } 
                        break; 
                } 
            } 
            // Output the final result
            out.println(d); 
        } 
    } 

    // Class for reading input efficiently
    static class LightScanner { 
        private BufferedReader reader = None; 
        private StringTokenizer tokenizer = None; 
        
        // Constructor to initialize the BufferedReader
        public LightScanner(InputStream in) { 
            reader = new BufferedReader(new InputStreamReader(in)); 
        } 
        
        // Method to read the next string token from input
        public String string() { 
            // Check if there are more tokens to read
            if (tokenizer == None ||!tokenizer.hasMoreTokens()) { 
                try { 
                    // Read a new line and create a new StringTokenizer
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) { 
                    // Handle IOException by throwing an unchecked exception
                    throw new UncheckedIOException(e); 
                } 
            } 
            // Return the next token
            return tokenizer.nextToken(); 
        } 
    } 
}
