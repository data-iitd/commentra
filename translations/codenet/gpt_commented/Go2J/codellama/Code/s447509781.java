
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    public static void main(String[] args) {
        // Initialize input reader with a buffer size of 1,000,000 bytes
        Input input = new Input(new BufferedReader(new InputStreamReader(System.in), 1000000));
        
        // Read the number of elements and the array of integers from input
        int n = input.nextInt();
        int[] s = input.nextIntArray();
        
        // Create a boolean array to track used indices
        boolean[] u = new boolean[n];
        
        // Initialize variables to store the maximum sum and a temporary sum
        long m = 0, f = 0;
        
        // Iterate through possible values of c from 1 to n-2
        for (int c = 1; c < n-1; c++) {
            f = 0; // Reset the temporary sum for each c
            
            // Iterate to find pairs of indices based on the current value of c
            for (int k = 0; c < n-1-k*c; k++) {
                u[k*c] = true; // Mark the current index as used
                
                // Break if the corresponding index is already used
                if (u[n-1-k*c]) { break; }
                
                // Calculate the sum of the elements at the current indices
                f += s[n-1-k*c] + s[k*c];
                
                // Update the maximum sum if the current sum is greater
                if (m < f) { m = f; }
            }
            
            // Reset the used indices for the next iteration of c
            for (int k = 0; k*c < n-1; k++) { u[k*c] = false; }
        }
        
        // Print the maximum sum found
        System.out.println(m);
    }
    
    // Input class to handle reading from standard input
    static class Input {
        private BufferedReader reader;
        private StringTokenizer tokenizer;
        
        // Initialize input reader with a buffer size of 1,000,000 bytes
        Input(BufferedReader reader) {
            this.reader = reader;
            this.tokenizer = null;
        }
        
        // Read the next line from input
        public String nextLine() throws Exception {
            String line = reader.readLine();
            if (line == null) { throw new Exception(); }
            return line;
        }
        
        // Read the next integer from input
        public int nextInt() throws Exception {
            String line = nextLine();
            return Integer.parseInt(line);
        }
        
        // Read a line of integers and return them as an array
        public int[] nextIntArray() throws Exception {
            String line = nextLine();
            String[] s = line.split(" ");
            int[] a = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                a[i] = Integer.parseInt(s[i]);
            }
            return a;
        }
    }
}

