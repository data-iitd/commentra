import java.io.*; 
import java.util.*; 

public class Main {
    // Define a constant for the maximum size of the arrays
    static int N = 200 + 10; 
    // Array to store the failure function values
    static int f[] = new int[N]; 
    // Array to store the concatenated strings
    static char b[] = new char[N]; 

    // Function to compute the failure function for the KMP algorithm
    static void getFail(char b[], int m) {
        int j = 0; // Initialize j to track the length of the previous longest prefix suffix
        f[0] = f[1] = 0; // Base cases for the failure function

        // Loop through the string to fill the failure function
        for (int i = 2; i <= m; i++) {
            // Adjust j until we find a match or j becomes 0
            while (j > 0 && b[j + 1] != b[i]) 
                j = f[j]; 
            // If there is a match, increment j
            if (b[j + 1] == b[i]) 
                j++; 
            // Set the failure function value for the current position
            f[i] = j; 
        }
    }

    public static void main(String[] args) {
        // Create an input reader and output writer
        InputReader in = new InputReader(System.in); 
        PrintWriter out = new PrintWriter(System.out); 

        // Read the length of the strings
        int n = in.nextInt(); 
        // Read the two strings
        String s1 = in.next(), str = in.next(); 
        int cnt = 0; 

        // Concatenate the second string into the character array
        for (int i = 0; i < n; i++) 
            b[++cnt] = str.charAt(i); 
        // Concatenate the first string into the character array
        for (int i = 0; i < n; i++) 
            b[++cnt] = s1.charAt(i); 

        // Compute the failure function for the concatenated strings
        getFail(b, cnt); 

        // Calculate the length of the longest prefix which is also a suffix
        int len = Math.min(f[cnt], Math.min(n, n)); 
        // Output the result based on the calculated length
        out.println(2 * n - len); 
        out.flush(); // Ensure all output is written
    }

    // Class to handle input reading
    static class InputReader {
        public BufferedReader reader; // BufferedReader for efficient input
        public StringTokenizer tokenizer; // Tokenizer to split input into tokens

        // Constructor to initialize the input reader
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768); 
            tokenizer = null; 
        }

        // Method to read the next token from input
        public String next() {
            // Read a new line if the tokenizer is null or has no more tokens
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) {
                    throw new RuntimeException(e); 
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }

        // Method to read the next integer from input
        public int nextInt() {
            return Integer.parseInt(next()); // Parse and return the next token as an integer
        }
    }
}
