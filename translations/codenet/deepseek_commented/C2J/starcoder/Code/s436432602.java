import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Read the number of elements (n) and the target value (k)
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    
    // Declare an array to store the elements
    int[] a = new int[n];
    
    // Declare loop variables
    int i, j;
    
    // Read n elements into the array a
    for (i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    
    // Allocate memory for the dynamic programming array dp
    int[] dp = new int[k + 1];
    
    // Iterate from 1 to k to fill the dp array
    for (i = 1; i <= k; i++) {
      // Initialize the win flag to 0
      int win = 0;
      
      // Check each element in the array a to see if it can be subtracted from i
      for (j = 0; j < n && a[j] <= i; j++) {
        if (dp[i - a[j]] == 0) {
          // If the resulting value is zero, set win to 1
          win = 1;
        }
      }
      
      // Set dp[i] to the win flag
      dp[i] = win;
    }
    
    // Print the result based on the value of dp[k]
    System.out.println(dp[k]? "First" : "Second");
  }
}

