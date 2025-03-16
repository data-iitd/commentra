// Optimize input/output operations
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    // Read the number of elements in the array
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    
    // Initialize a vector to store the elements
    List<Long> A = new ArrayList<Long>();
    
    // Read the elements into the vector
    for (int i = 0; i < N; i++) {
      A.add(Long.parseLong(br.readLine()));
    }

    // Initialize a variable to keep track of the maximum difference
    long answer = 0;
    
    // Iterate through all pairs of elements to find the maximum difference
    for (int i = 0; i < N - 1; ++i) {
      for (int j = i + 1; j < N; ++j) {
        // Calculate the absolute difference between the two elements
        long diff = Math.abs(A.get(i) - A.get(j));
        
        // Update the maximum difference found so far
        answer = Math.max(answer, diff);
      }
    }
    
    // Output the maximum difference
    System.out.println(answer);
  }
}

