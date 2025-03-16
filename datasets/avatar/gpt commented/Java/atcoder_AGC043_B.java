import java.io.*; 
import java.util.*; 

public class Main {
    
    // Method to calculate a specific value based on the input string and character
    private int cal(String s, char c) {
        int n = s.length(); // Get the length of the string
        int m = n - 1; // Calculate the last index of the string
        int ans = 0; // Initialize the answer variable
        
        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            // Check if the current character matches 'c' and if the bitwise AND of m and i equals i
            if (s.charAt(i) == c && (m & i) == i) {
                ans ^= 1; // Toggle the answer using XOR operation
            }
        }
        return ans; // Return the final calculated answer
    }

    // Main logic to solve the problem
    private void solve() {
        int n = sc.nextInt(); // Read the integer input for the length of the string
        String s = sc.next(); // Read the string input
        StringBuilder sb = new StringBuilder(); // Initialize a StringBuilder to build the new string
        
        // Build a new string based on the absolute differences between adjacent characters
        for (int i = 1; i < n; i++) {
            sb.append(Math.abs(s.charAt(i) - s.charAt(i - 1))); // Append the absolute difference
        }
        
        // Special case when the length of the string is 2
        if (n == 2) {
            out.println(sb.charAt(0)); // Print the first character of the new string
            return; // Exit the method
        }
        
        // Convert the StringBuilder to a string
        s = sb.toString(); 
        
        // Check if the new string contains the character '1'
        if (s.contains("1")) {
            out.println(cal(s, '1')); // Calculate and print the result for character '1'
        } else {
            out.println(cal(s, '2') * 2); // Calculate and print the result for character '2', multiplied by 2
        }
    }

    // Static variables for output and input handling
    private static PrintWriter out; 
    private static MyScanner sc; 

    // Custom scanner class for input handling
    private static class MyScanner {
        BufferedReader br; // BufferedReader for reading input
        StringTokenizer st; // StringTokenizer for parsing input
        
        // Constructor to initialize BufferedReader
        private MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        // Method to read the next token from input
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine()); // Read a new line and tokenize it
                } catch (IOException e) {
                    e.printStackTrace(); // Handle any IO exceptions
                }
            }
            return st.nextToken(); // Return the next token
        }
        
        // Method to read the next integer from input
        int nextInt() {
            return Integer.parseInt(next()); // Parse and return the next token as an integer
        }
        
        // Method to read the next long from input
        long nextLong() {
            return Long.parseLong(next()); // Parse and return the next token as a long
        }
        
        // Method to read the next double from input
        double nextDouble() {
            return Double.parseDouble(next()); // Parse and return the next token as a double
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        out = new PrintWriter(new BufferedOutputStream(System.out)); // Initialize PrintWriter for output
        sc = new MyScanner(); // Initialize the custom scanner
        new Main().solve(); // Create an instance of Main and call the solve method
        out.close(); // Close the PrintWriter
    }
}
