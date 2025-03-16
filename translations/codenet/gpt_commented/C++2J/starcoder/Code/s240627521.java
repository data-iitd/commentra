import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    // Read the number of elements
    int N;
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();

    // Initialize a vector to store the elements
    int[] A = new int[N];

    // Input the elements into the vector
    for(int i = 0; i < N; ++i) A[i] = sc.nextInt();

    // Sort the vector in descending order
    Arrays.sort(A);
    Arrays.sort(A, Collections.reverseOrder());

    // Initialize variables to track the minimum difference and the corresponding index
    int index;
    int max = Integer.MAX_VALUE;

    // Find the element in the vector that minimizes the difference with twice the second largest element
    for(int i = 1; i < N; ++i) {
      // Calculate the absolute difference and update if it's smaller than the current max
      if(max > Math.abs(A[0] - 2 * A[i])) {
        max = Math.abs(A[0] - 2 * A[i]);
        index = i; // Store the index of the element that gives the minimum difference
      }
    }

    // Output the largest element and the element that minimizes the difference
    System.out.println(A[0] + " " + A[index]);
  }
}

