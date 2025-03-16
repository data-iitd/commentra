
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

// Define the main class
public class s447509781{
  // Define the main method
  public static void main(String[] args) {
    // Initialize the input reader
    Input input = new Input(new BufferedReader(new InputStreamReader(System.in)));

    // Read the first integer from the input
    int n = input.nextInt();

    // Read the second integer array from the input
    int[] s = input.nextIntArray();

    // Initialize a boolean array of size n
    boolean[] u = new boolean[n];

    // Initialize two long variables m and f
    long m = 0, f = 0;

    // Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
    for (int c = 1; c < n-1; c++) {
      // Initialize f to 0
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
  // Define the BufferedReader for reading input
  BufferedReader reader;

  // Define the constructor for the Input class
  public Input(BufferedReader reader) {
    this.reader = reader;
  }

  // Define the method for reading a line from the input
  public String nextLine() {
    // Read a line from the input and return it as a string
  }

  // Define the method for reading an integer from the input
  public int nextInt() {
    // Read an integer from the input and return it
  }

  // Define the method for reading an array of integers from the input
  public int[] nextIntArray() {
    // Read an array of integers from the input and return it
  }
}

// Define the Input class and its methods for reading input ends here

