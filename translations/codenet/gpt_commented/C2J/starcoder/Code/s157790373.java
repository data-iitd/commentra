import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    int n, q, M; // n for the number of elements, q for the number of queries, M for the target sum
    int i, j, k;
    int[] A; // Array of elements
    boolean flag; // Flag to indicate if a solution is found

    // Read the number of elements in the array
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    // Read the elements into the array A
    A = new int[n];
    for(i=0; i<n; i++) A[i] = sc.nextInt();

    // Read the number of queries
    q = sc.nextInt();
    // Process each query
    for(i=0; i<q; i++)
      {
        // Read the target sum for the current query
        M = sc.nextInt();
        flag = false; // Reset flag for each query

        // Call the solve function to check if a subset sums to M
        solve(A, -1, M);
        // Output the result based on the flag
        if(flag == true) System.out.println("yes");
        else System.out.println("no");
      }
  }

  // Recursive function to determine if a subset of A can sum to m
  public static void solve(int[] A, int i, int m)
  {
    // Base case: if index exceeds the number of elements
    if(i > A.length - 1) return;
    // Base case: if the remaining sum is negative
    else if(m < 0) return;
    // Base case: if the remaining sum is zero (solution found)
    else if(m == 0 || m - A[i + 1] == 0)
      {
        flag = true; // Set flag to TRUE indicating a solution is found
        return; // Return
      }
    else
      {
        // Recursive case: do not use the current element A[i]
        solve(A, i + 1, m);
        // Recursive case: use the current element A[i]
        solve(A, i + 1, m - A[i]);
      }
  }
}

