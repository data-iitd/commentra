
import java.util.*;

public class s240627521{
  public static void main(String[] args) {
    // Read the number of elements
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();

    // Initialize a list to store the elements
    List<Long> A = new ArrayList<>();

    // Input the elements into the list
    for(int i = 0; i < N; ++i) A.add(sc.nextLong());

    // Sort the list in descending order
    Collections.sort(A, Collections.reverseOrder());

    // Initialize variables to track the minimum difference and the corresponding index
    int index;
    long max = Long.MAX_VALUE;

    // Find the element in the list that minimizes the difference with twice the second largest element
    for(int i = 1; i < N; ++i) {
      // Calculate the absolute difference and update if it's smaller than the current max
      if(max > Math.abs(A.get(0) - 2 * A.get(i))) {
        max = Math.abs(A.get(0) - 2 * A.get(i));
        index = i; // Store the index of the element that gives the minimum difference
      }
    }

    // Output the largest element and the element that minimizes the difference
    System.out.println(A.get(0) + " " + A.get(index));
  }
}
