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
        // Initialize input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        // Create an instance of TaskD and solve the problem
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        
        // Close the output stream
        out.close();
    }

    // TaskD class containing the solve method
    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // Read the number of elements and the modulo value
            int n = in.nextInt();
            int m = in.nextInt();
            
            // Read the array of elements
            int[] a = in.nextIntArray(n);
            
            // HashMap to store the frequency of remainders
            HashMap<Integer, Integer> dp = new HashMap<>();
            
            // Initialize the answer and base variable
            long ans = 0;
            int base = 0;
            
            // Iterate through the array to calculate the answer
            for (int i = 0; i < n; i++) {
                // Update the base variable
                base = (base - a[i] % m + m) % m;
                
                // Update the frequency of remainders in the HashMap
                dp.merge((base + a[i]) % m, 1, Integer::sum);
                
                // Add the frequency of the current remainder to the answer
                ans += dp.getOrDefault(base, 0);
            }
            
            // Print the final answer
            out.println(ans);
        }
    }

    // InputReader class to read input efficiently
    static class InputReader {
        private BufferedReader br;
        private StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
            st = new StringTokenizer("");
        }

        // Read the next string from the input
        public String nextString() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return st.nextToken();
        }

        // Read the next integer from the input
        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        // Read the next array of integers from the input
        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }
    }
}
