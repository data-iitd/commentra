
/*
 * 2415.java: Sashimi
 */

 import java.util.*;
 
 // Include necessary libraries
 
 public class Main {
   // Define constants
   public static final int MAX_N = 4000;
   public static final long LINF = 1L << 60;
 
   // Define types and aliases (if any)
   public static long wis[] = new long[MAX_N];
   public static long wsums[] = new long[MAX_N + 1];
   public static long dp[][] = new long[MAX_N][MAX_N + 1];
   public static int ks[][] = new int[MAX_N][MAX_N + 1];
 
   // Define subroutines (if any)
 
   /* main */
   public static void main(String[] args) {
     // Read input
     int n;
     Scanner sc = new Scanner(System.in);
     n = sc.nextInt();
 
     // Initialize arrays
     Arrays.fill(wsums, 0);
     for (int i = 0; i < n; i++) {
       wis[i] = sc.nextLong();
       wsums[i + 1] = wsums[i] + wis[i];
     }
 
     // Initialize 2D array dp and 2D array ks with default values
     for (int i = 0; i < n; i++) {
       for (int j = 0; j <= n; j++) dp[i][j] = LINF, ks[i][j] = -1;
       dp[i][i + 1] = 0;
       ks[i][i + 1] = i;
     }
 
     // Calculate dp and ks for all subarrays of size 2 to n
     for (int l = 2; l <= n; l++)
       for (int i = 0, j = l; j <= n; i++, j++) {
         // Initialize variables for current subarray
         long mind = LINF;
         long wsum = wsums[j] - wsums[i];
         int mink = -1;
 
         // Find the minimum cost and index of the previous subarray that can be combined with the current subarray
         for (int k = ks[i][j - 1]; k <= ks[i + 1][j]; k++) {
   // Calculate the cost of combining the current subarray with the previous subarray
   long d = dp[i][k] + dp[k][j] + wsum;
 
   // Update minimum cost and index if found a better combination
   if (mind > d) mind = d, mink = k;
         }
 
         // Update dp and ks for the current subarray
         dp[i][j] = mind;
         ks[i][j] = mink;
       }
 
     // Print the result
     System.out.println(dp[0][n]);
 
     // Terminate the program
     return;
   }
 }

