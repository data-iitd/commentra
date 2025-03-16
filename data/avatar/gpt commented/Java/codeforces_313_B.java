import java.io.*; 
import java.util.StringTokenizer; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Create a BufferedReader to read input from the standard input stream
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Create a PrintWriter to output results to the standard output stream
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out)); 
        
        // Create an instance of the Fast class to process the input
        Fast f = new Fast(); 
        
        // Call the solution method to handle the input and produce output
        f.sol(br, pw); 
        
        // Close the PrintWriter to flush the output
        pw.close(); 
    } 
} 

class Fast { 
    public void sol(BufferedReader br, PrintWriter pw) throws IOException { 
        // Read the first line of input and tokenize it to get the string
        StringTokenizer st = new StringTokenizer(br.readLine()); 
        String s = st.nextToken(); 
        
        // Initialize a cumulative array to count consecutive characters
        Integer cum[] = new Integer[s.length() + 1]; 
        cum[0] = cum[s.length()] = 0; 
        
        // Fill the cumulative array with counts of consecutive characters
        for (int i = 1; i < s.length(); i++) { 
            if (s.charAt(i) == s.charAt(i - 1)) 
                cum[i] = cum[i - 1] + 1; // Increment count if the current character is the same as the previous
            else 
                cum[i] = cum[i - 1]; // Carry forward the previous count if different
        } 
        
        // Read the number of queries from the input
        st = new StringTokenizer(br.readLine()); 
        Integer q = Integer.parseInt(st.nextToken()); 
        
        // Process each query
        while (q-- != 0) { 
            // Read the range for the query
            st = new StringTokenizer(br.readLine()); 
            Integer l = Integer.parseInt(st.nextToken()), r = Integer.parseInt(st.nextToken()) - 1; 
            
            // Calculate and print the result for the current query
            pw.println(cum[r] - cum[l - 1]); 
        } 
    } 
}
