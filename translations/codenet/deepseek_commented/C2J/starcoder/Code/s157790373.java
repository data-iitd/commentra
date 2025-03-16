import java.util.*;

public class Main
{
  // Function prototype for solve
  static boolean solve(int i, int m);

  // Global variables
  static int n, A[];
  static boolean flag;

  public static void main(String[] args)
  {
    // Variables for input
    int q, M;
    int i, j, k;

    // Read the number of elements in the array
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    // Read the elements of the array
    A = new int[n];
    for(i=0; i<n; i++) A[i] = sc.nextInt();

    // Read the number of queries
    q = sc.nextInt();
    // Iterate over each query
    for(i=0; i<q; i++)
      {
        // Read the target sum for the current query
        M = sc.nextInt();
        // Initialize the flag to FALSE
        flag = false;

        // Call the solve function to find a subset that sums up to M
        solve(-1, M);
        // Print "yes" if a subset is found, otherwise print "no"
        if(flag) System.out.println("yes");
        else System.out.println("no");
      }
  }

  // Recursive function to find a subset that sums up to m
  static boolean solve(int i, int m)
  {
    // Base case: if index i exceeds the number of elements, return FALSE
    if(i > n) return false;
    // If the remaining sum m is negative, return FALSE
    else if(m < 0) return false;
    // If the remaining sum m is zero or the current element A[i] equals m, set flag to TRUE and return TRUE
    else if(m == 0 || m - A[i+1] == 0)
      {
        flag = true;
        return true;
      }
    else
      {
        // Recursive call without using the current element A[i]
        solve(i+1, m);
        // Recursive call using the current element A[i]
        solve(i+1, m-A[i]);
      }
  }
}

