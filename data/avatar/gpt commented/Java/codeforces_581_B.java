import java.util.*; 
import java.io.*; 

public class Main { 
    // Declare a static TreeSet to hold long values (not used in this code)
    static TreeSet<Long> set; 

    public static void main(String[] args) { 
        // Create a Scanner object for input and PrintWriter for output
        Scanner in = new Scanner(System.in); 
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read the number of elements
        int n = in.nextInt(); 
        
        // Initialize an array to hold the input values
        long[] a = new long[n]; 
        
        // Populate the array with input values
        for (int i = 0; i < n; i++) 
            a[i] = in.nextLong(); 
        
        // Initialize a dp array to store the maximum values
        long[] dp = new long[n + 1]; 
        
        // Fill the dp array with -1 to indicate uninitialized values
        Arrays.fill(dp, -1); 
        
        // Set the last element of dp to the last element of a
        dp[n - 1] = a[n - 1]; 
        
        // Fill the dp array with the maximum values from the end to the beginning
        for (int i = n - 1; i >= 0; i--) { 
            dp[i] = Math.max(dp[i + 1], a[i]); 
        } 
        
        // Iterate through the original array to calculate the output
        for (int i = 0; i < n; i++) { 
            // If the current element is greater than the next maximum, print 0
            if (a[i] > dp[i + 1]) 
                pw.print(0 + " "); 
            // Otherwise, calculate and print the difference to the next maximum
            else 
                pw.print((dp[i + 1] - a[i] + 1) + " "); 
        } 
        
        // Print a new line after all outputs
        pw.println(); 
        
        // Close the PrintWriter
        pw.close(); 
    } 
    
    // Debugging utility to print objects
    static void debug(Object... obj) { 
        System.err.println(Arrays.deepToString(obj)); 
    } 
}
