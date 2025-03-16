// Package main is the entry point of the program
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// Define the main function
public class Main {
  // Initialize the input reader
  static Input input = new Input(new BufferedReader(new InputStreamReader(System.in)));

  // Define the main function
  public static void main(String[] args) {
    // Read the first integer from the input
    int n = input.nextInt();

    // Read the second integer array from the input
    int[] s = input.nextIntArray();

    // Initialize a boolean slice of size n
    boolean[] u = new boolean[n];

    // Initialize two integer variables m and f
    long m = 0, f = 0;

    // Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
    for (int c = 1; c < n-1; c++) {
      // Initialize a variable f to 0
      f = 0;

      // Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
      for (int k = 0; c < n-1-k*c; k++) {
        // Set the boolean value of the current index to true
        u[k*c] = true;

        // Check if the boolean value of the last index of the current subarray is already set to true
        // If it is, break the inner loop as we don't need to check further
        if (u[n-1-k*c]) { break; }

        // Calculate the sum of the current and previous subarrays
        f += s[n-1-k*c] + s[k*c];

        // Update the value of m if the current sum is greater than the previous maximum sum
        if (m < f) { m = f; }

        // Set all the boolean values of the current subarray to false
      }

      // Iterate through all the indices of the current subarray and set their boolean values to false
      for (int k = 0; k*c < n-1; k++) { u[k*c] = false; }
    }

    // Print the maximum sum
    System.out.println(m);
  }
}

// Define the Input class and its methods for reading input
class Input {
  // Initialize the input reader
  private BufferedReader reader;

  // Define the constructor
  public Input(BufferedReader reader) {
    this.reader = reader;
  }

  // Define the nextLine method
  public String nextLine() {
    // Read a line from the input and return it as a string
  }

  // Define the nextInt method
  public int nextInt() {
    // Read an integer from the input and return it
  }

  // Define the nextIntArray method
  public int[] nextIntArray() {
    // Read an array of integers from the input and return it
  }
}

// Define the Input class and its methods for reading input ends here

