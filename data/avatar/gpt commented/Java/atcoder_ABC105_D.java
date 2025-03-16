import java.io.OutputStream; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.StringTokenizer; 
import java.util.HashMap; 
import java.io.IOException; 
import java.util.InputMismatchException; 
import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.io.InputStream; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        
        // Create an InputReader to read input data
        InputReader in = new InputReader(inputStream); 
        
        // Create a PrintWriter to output results
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of TaskD to solve the problem
        TaskD solver = new TaskD(); 
        
        // Solve the problem for the first test case
        solver.solve(1, in, out); 
        
        // Close the output stream
        out.close(); 
    } 
    
    static class TaskD { 
        public void solve(int testNumber, InputReader in, PrintWriter out) { 
            // Read the number of elements and the modulus value
            int n = in.nextInt(); 
            int m = in.nextInt(); 
            
            // Read the array of integers
            int[] a = in.nextIntArray(n); 
            
            // Initialize a HashMap to store counts of remainders
            HashMap<Integer, Integer> dp = new HashMap<>(); 
            long ans = 0; // Variable to store the final answer
            int base = 0; // Variable to track the base remainder
            
            // Iterate through the array to calculate the answer
            for (int i = 0; i < n; i++) { 
                // Update the base remainder
                base = (base - a[i] % m + m) % m; 
                
                // Merge the current remainder into the HashMap
                dp.merge((base + a[i]) % m, 1, Integer::sum); 
                
                // Add the count of occurrences of the current base remainder to the answer
                ans += dp.getOrDefault(base, 0); 
            } 
            
            // Output the final answer
            out.println(ans); 
        } 
    } 
    
    static class InputReader { 
        private BufferedReader br; // BufferedReader for reading input
        private StringTokenizer st; // StringTokenizer for parsing input
        
        public InputReader(InputStream inputStream) { 
            // Initialize BufferedReader and StringTokenizer
            br = new BufferedReader(new InputStreamReader(inputStream)); 
            st = new StringTokenizer(""); 
        } 
        
        // Method to read the next string from input
        public String nextString() { 
            while (!st.hasMoreTokens()) { 
                try { 
                    // Read the next line and tokenize it
                    st = new StringTokenizer(br.readLine(), " "); 
                } catch (IOException e) { 
                    throw new InputMismatchException(); 
                } 
            } 
            return st.nextToken(); 
        } 
        
        // Method to read the next integer from input
        public int nextInt() { 
            return Integer.parseInt(nextString()); 
        } 
        
        // Method to read an array of integers from input
        public int[] nextIntArray(int n) { 
            int[] res = new int[n]; 
            for (int i = 0; i < n; i++) { 
                res[i] = nextInt(); 
            } 
            return res; 
        } 
    } 
}
