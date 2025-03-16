import java.util.* ; 
import java.io.* ; 

public class Main { 
    static TreeSet<Long> set; 

    public static void main(String[] args) { 
        Scanner in = new Scanner(System.in); 
        PrintWriter pw = new PrintWriter(System.out); 

        // Step 4: Read input values
        int n = in.nextInt(); 
        long[] a = new long[n]; 
        for (int i = 0; i < n; i++) { 
            a[i] = in.nextLong(); 
        } 

        // Step 5: Initialize a dynamic programming array
        long[] dp = new long[n + 1]; 
        Arrays.fill(dp, -1); 

        // Step 6: Fill the dynamic programming array
        dp[n - 1] = a[n - 1]; 
        for (int i = n - 1; i >= 0; i--) { 
            dp[i] = Math.max(dp[i + 1], a[i]); 
        } 

        // Step 7: Calculate the result
        for (int i = 0; i < n; i++) { 
            if (a[i] > dp[i + 1]) { 
                pw.print(0 + " "); 
            } else { 
                pw.print((dp[i + 1] - a[i] + 1) + " "); 
            } 
        } 

        // Step 8: Print the result
        pw.println(); 
        pw.close(); 
    } 

    // Step 9: Debugging (optional)
    static void debug(Object... obj) { 
        System.err.println(Arrays.deepToString(obj)); 
    } 
}