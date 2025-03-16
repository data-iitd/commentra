import java.io.*; 
import java.util.*; 

public class Main { 
    // FastReader class to handle fast input
    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
        
        // Constructor initializes BufferedReader for input
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        
        // Method to read the next token from input
        String next() { 
            // Check if there are no more tokens available
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    // Read a new line and tokenize it
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            // Return the next token
            return st.nextToken(); 
        } 
        
        // Method to read the next integer from input
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read the next long from input
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        
        // Method to read the next double from input
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        
        // Method to read the next line from input
        String nextLine() { 
            String str = ""; 
            try { 
                str = br.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
    
    public static void main(String[] args) { 
        // Create an instance of FastReader for input
        FastReader sc = new FastReader(); 
        
        // Read two integers n and m from input
        int n = sc.nextInt(); 
        int m = sc.nextInt(); 
        
        // Reverse the integer m and store the result in t
        int t = reverse(m); 
        
        // Print the sum of t and n
        System.out.println(t + n); 
    } 
    
    // Method to reverse the digits of an integer n
    public static int reverse(int n) { 
        // If n is a single digit, return n multiplied by 10
        if (n < 10) return n * 10; 
        
        int t = n, r = 0; 
        
        // Loop to reverse the digits of n
        while (t > 0) { 
            r = (r * 10) + t % 10; // Add the last digit of t to r
            t = t / 10; // Remove the last digit from t
        } 
        
        // Return the reversed integer
        return r; 
    } 
}
