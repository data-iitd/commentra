
import java.util.*;

public class s240627521{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt(); // Read the number of elements in the array A
    long[] A = new long[N];
    for(int i=0;i<N;++i) A[i] = sc.nextLong(); // Read the elements of the array A
    Arrays.sort(A); // Sort the array A in ascending order
    int index = 0;
    long max = Long.MAX_VALUE; // Initialize max with a large value
    for(int i=1;i<N;++i) { // Iterate through the array to find the optimal pair
      if(max>Math.abs(A[N-1]-2*A[N-1-i])) { // Check if the current difference is smaller than the previous minimum
        max = Math.abs(A[N-1]-2*A[N-1-i]); // Update the minimum difference
        index = i; // Store the index of the current element
      }
    }
    System.out.println(A[N-1]+" "+A[N-1-index]); // Output the first and the found optimal pair
  }
}
