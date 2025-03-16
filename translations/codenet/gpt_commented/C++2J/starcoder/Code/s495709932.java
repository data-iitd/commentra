import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Optimize input/output operations
    Scanner in = new Scanner(System.in);
    
    // Read the number of elements in the array
    int N = in.nextInt();
    
    // Initialize a vector to store the elements
    int[] A = new int[N];
    
    // Read the elements into the vector
    for (int i = 0; i < N; ++i) A[i] = in.nextInt();

    // Initialize a variable to keep track of the maximum difference
    int answer = 0;
    
    // Iterate through all pairs of elements to find the maximum difference
    for (int i = 0; i < N - 1; ++i) {
      for (int j = i + 1; j < N; ++j) {
        // Calculate the absolute difference between the two elements
        int diff = Math.abs(A[i] - A[j]);
        
        // Update the maximum difference found so far
        answer = Math.max(answer, diff);
      }
    }
    
    // Output the maximum difference
    System.out.println(answer);
  }
}
