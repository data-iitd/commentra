
import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Read the number of elements in the vector
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();

    // Initialize a vector of size N with integers
    int[] A = new int[N];
    for (int i = 0; i < N; ++i) { // Iterate through each element in the vector and read its value
      A[i] = in.nextInt();
    }

    // Initialize the answer variable to 0
    int answer = 0;

    // Outer loop iterates through each element in the vector except the last one
    for (int i = 0; i < N - 1; ++i) {
      // Inner loop iterates through the remaining elements in the vector starting from the next element
      for (int j = i + 1; j < N; ++j) {
        // Calculate the absolute difference between the current and next elements
        int diff = Math.abs(A[i] - A[j]);

        // Update the answer variable with the maximum difference found so far
        answer = Math.max(answer, diff);
      }
    }

    // Print the answer
    System.out.println(answer);
  }
}

