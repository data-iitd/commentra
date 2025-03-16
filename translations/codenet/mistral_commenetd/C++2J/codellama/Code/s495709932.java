
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    // Set up fast I/O
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());

    // Initialize a vector of size N with integers
    int[] A = new int[N];
    for (int i = 0; i < N; i++) {
      A[i] = Integer.parseInt(br.readLine());
    }

    // Initialize the answer variable to 0
    long answer = 0;

    // Outer loop iterates through each element in the vector except the last one
    for (int i = 0; i < N - 1; i++) {
      // Inner loop iterates through the remaining elements in the vector starting from the next element
      for (int j = i + 1; j < N; j++) {
        // Calculate the absolute difference between the current and next elements
        long diff = Math.abs(A[i] - A[j]);

        // Update the answer variable with the maximum difference found so far
        answer = Math.max(answer, diff);
      }
    }

    // Print the answer
    System.out.println(answer);
  }
}

