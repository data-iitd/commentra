import java.util.*; 
import java.lang.*; 
import java.io.*; 

public class Main { 

    // FastReader class to handle fast input
    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
        
        // Constructor to initialize BufferedReader
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        
        // Method to read the next token from input
        String next() { 
            // Check if there are no tokens left to read
            while (st == null || !st.hasMoreElements()) { 
                try { 
                    // Read a new line and tokenize it
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
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
            } catch (Exception e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 

    // Method to compute (x^y) % mod using modular exponentiation
    static int modPower(int x, int y, int mod) { 
        int res = 1; 
        x %= mod; // Reduce x modulo mod
        if (x == 0) return 0; // If x is 0, return 0
        
        // Loop until y becomes 0
        while (y > 0) { 
            // If y is odd, multiply x with result
            if (y % 2 == 1) { 
                res = (res * x) % mod; 
            } 
            y = y >> 1; // Divide y by 2
            x = (x * x) % mod; // Square x
        } 
        return res; // Return the final result
    } 

    // Pair class to hold two related values
    static class pair<T1, T2> { 
        T1 first; 
        T2 second; 
        
        // Constructor to initialize the pair
        pair(T1 first, T2 second) { 
            this.first = first; 
            this.second = second; 
        } 
    } 

    // Main method to execute the program
    public static void main(String[] args) throws java.lang.Exception { 
        FastReader in = new FastReader(); // Create an instance of FastReader
        long[] a = new long[4]; // Array to hold four long integers
        
        // Read four long integers from input
        for (int i = 0; i < 4; i++) 
            a[i] = in.nextLong(); 
        
        // Calculate and print the maximum product of pairs from the array
        System.out.println(Math.max(a[0] * a[2], 
            Math.max(a[1] * a[3], 
            Math.max(a[0] * a[3], a[1] * a[2])))); 
    } 
}
