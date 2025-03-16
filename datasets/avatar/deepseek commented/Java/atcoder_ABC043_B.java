
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        // Step 1: Define the input stream and output stream
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        
        // Step 2: Create a LightScanner instance for reading input efficiently
        LightScanner in = new LightScanner(inputStream);
        
        // Step 3: Create a PrintWriter instance for writing output
        PrintWriter out = new PrintWriter(outputStream);
        
        // Step 4: Create an instance of the problem solver
        BUnhappyHackingABCEdit solver = new BUnhappyHackingABCEdit();
        
        // Step 5: Solve the problem
        solver.solve(1, in, out);
        
        // Close the output writer
        out.close();
    }
    
    // Helper class for solving the problem
    static class BUnhappyHackingABCEdit {
        public void solve(int testNumber, LightScanner in, PrintWriter out) {
            // Read the input string
            String s = in.string();
            
            // StringBuilder to build the result
            StringBuilder d = new StringBuilder();
            
            // Iterate over each character in the input string
            for (char c : s.toCharArray()) {
                switch (c) {
                    case '0':
                        // Append '0' to the result
                        d.append("0");
                        break;
                    case '1':
                        // Append '1' to the result
                        d.append("1");
                        break;
                    case 'B':
                        // Remove the last character if the result is not empty
                        if (d.length() > 0) {
                            d.setLength(d.length() - 1);
                            d.trimToSize();
                        }
                        break;
                }
            }
            
            // Print the result
            out.println(d);
        }
    }
    
    // LightScanner class for reading input efficiently
    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;
        
        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }
        
        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }
    }
}

