import java.io.*; 
import java.util.*; 

public class Main { 
    // BufferedReader for efficient input reading
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
    // PrintWriter for efficient output writing
    private static final PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); 
    private static StringTokenizer st; 

    // Method to read an integer from input
    private static int readInt() throws IOException { 
        // Ensure that the tokenizer has tokens to read
        while (st == null || !st.hasMoreTokens()) 
            st = new StringTokenizer(br.readLine()); 
        // Parse and return the next integer token
        return Integer.parseInt(st.nextToken()); 
    } 

    public static void main(String[] args) throws IOException { 
        // Solve the problem and print the result
        pw.println(solve()); 
        // Close the PrintWriter to flush the output
        pw.close(); 
    } 

    // Method to solve the main logic of the problem
    private static int solve() throws IOException { 
        // Read the integer K from input
        int K = readInt(); 
        
        // Check if K is even or divisible by 5, return -1 if true
        if (K % 2 == 0 || K % 5 == 0) 
            return -1; 
        
        // If K is divisible by 7, divide it by 7
        if (K % 7 == 0) 
            K /= 7; 
        
        // Multiply K by 9 as part of the calculation
        K *= 9; 
        
        // Initialize the answer counter
        int ans = 1; 
        
        // Calculate the remainder of 10 divided by K
        int remainder = 10 % K; 
        
        // Loop until the remainder is 1
        while (remainder != 1) { 
            // Increment the answer counter
            ans++; 
            // Update the remainder for the next iteration
            remainder = remainder * 10 % K; 
        } 
        
        // Return the final answer
        return ans; 
    } 
}
