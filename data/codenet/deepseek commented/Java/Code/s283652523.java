import java.io.*;
import java.util.*;
import java.math.BigDecimal;

@SuppressWarnings("unused")
public class Main {
    FastScanner in;
    PrintWriter out;
    final static int MOD = (int)1e9+7; // Define a constant MOD for modulo operations
    
    void solve(){
        int N = in.nextInt(); // Read the number of elements
        int[] A = in.nextIntArray(N); // Read the array of integers
        
        long ans = 0, sum = A[N-1]; // Initialize the answer and sum variables
        for(int i = N - 2; i >= 0; i--){
            ans += (sum * A[i]) % MOD; // Compute the contribution of each element and add to ans
            ans %= MOD; // Ensure ans stays within the bounds defined by MOD
            sum += A[i]; // Update the sum
            sum %= MOD; // Ensure sum stays within the bounds defined by MOD
        }
        out.println(ans); // Print the final answer
    }
    
    public static void main(String[] args) {
        new Main().m(); // Initialize the Main object and call the m method
    }
    
    private void m() {
        in = new FastScanner(System.in); // Initialize the FastScanner with standard input
        out = new PrintWriter(System.out); // Initialize the PrintWriter with standard output
        /*
        try {
            String path = "input.txt";
            out = new PrintWriter(new BufferedWriter(new FileWriter(new File(path))));
        }catch (IOException e){
            e.printStackTrace();
        }
        */
        solve(); // Call the solve method to execute the program logic
        out.flush(); // Flush the output buffer
        in.close(); // Close the FastScanner
        out.close(); // Close the PrintWriter
    }
    
    static class FastScanner {
        private Reader input;
        
        public FastScanner() {this(System.in);}
        public FastScanner(InputStream stream) {this.input = new BufferedReader(new InputStreamReader(stream));}
        public void close() {
            try {
                this.input.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        
        // Methods for reading various types of data...
    }
}