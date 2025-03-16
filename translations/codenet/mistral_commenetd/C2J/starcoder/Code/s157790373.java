
import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    int n, A[]=new int[LEN], q, M, i, j, k; // 'n' is the size of the array 'A' and 'A' is the array to be checked, 'q' is the number of queries and 'M' is the length of subsequence to be checked in each query, 'i' is the loop variable, 'j' is the loop variable, 'k' is the loop variable
    boolean flag; // Flag to check if a subsequence of given length'm' is found

    n=sc.nextInt(); // Reading the size of the array 'A'
    for(i=0; i<n; i++)A[i]=sc.nextInt(); // Reading the elements of the array 'A'

    q=sc.nextInt(); // Reading the number of queries
    for(i=0; i<q; i++) // Loop through all the queries
      {
        M=sc.nextInt(); // Reading the length of subsequence to be checked in the current query
        flag=false; // Initializing the flag to false

        solve(0, M); // Calling the function'solve' to check if there is a subsequence of given length 'M' in the array 'A'

        if(flag==true)System.out.println("yes"); // If a subsequence of given length 'M' is found, print 'yes'
        else System.out.println("no"); // If no subsequence of given length 'M' is found, print 'no'
      }
  }

  public static boolean solve(int i, int m)
  {
    // Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
    if(i>n)return false;

    // Base case: If length'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
    else if(m<0)return false;

    // Base case: If length'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to'm', a subsequence of length'm' can be formed starting from index 'i'
    else if(m==0 || m-A[i+1]==0)
      {
        flag=true; // Setting the flag to true as a subsequence of length'm' is found
        return true; // Returning true to indicate that a subsequence of length'm' is found
      }

    // Recursive case: If length'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
    else
      {
        // Not using the element at index 'i' to form the subsequence of length'm'
        solve(i+1, m);

        // Using the element at index 'i' to form the subsequence of length'm'
        solve(i+1, m-A[i]);
      }
  }
}

