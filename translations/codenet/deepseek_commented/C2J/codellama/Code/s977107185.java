
import java.util.Scanner;

public class BubbleSort {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt(); // Read the size of the array

    int[] A = new int[N]; // Declare an array of size N

    for(int i = 0; i < N; i++) {
      A[i] = sc.nextInt(); // Read the elements of the array
    }

    int tmp, count = 0; // Declare variables for temporary variable for swapping, and swap counter

    // Implement Bubble Sort
    for(int i = 0; i < N - 1; i++) {
      for(int j = N - 1; j > i; j--) {
        if(A[j] < A[j - 1]) {
          tmp = A[j]; // Swap A[j] and A[j-1]
          A[j] = A[j - 1];
          A[j - 1] = tmp;
          count++; // Increment the swap counter
        }
      }
    }

    for(int i = 0; i < N; i++) {
      System.out.print(A[i] + " "); // Print the sorted array elements
    }

    System.out.println(); // Print a newline character to end the line

    System.out.println(count); // Print the number of swaps

  }

}

