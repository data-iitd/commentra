// Package main is the entry point of the program

import (
  "bufio" // Import bufio package for reading input
  "fmt"   // Import fmt package for printing output
  "os"    // Import os package for reading from standard input
  "strconv" // Import strconv package for converting strings to integers
  "strings" // Import strings package for splitting strings
)

// Define the main function
public class Main {
  // Define the main function
  public static void main(String[] args) {
    // Initialize the input reader
    Input input = new Input(bufio.NewReaderSize(System.in,1000000));

    // Read the first integer from the input
    int n = input.NextInt();

    // Read the second integer array from the input
    int[] s = input.NextIntArray();

    // Initialize a boolean array of size n
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
  BufferedReader reader;
  public Input(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream),1000000);
  }
  public Input(Reader reader) {
    this.reader = new BufferedReader(reader,1000000);
  }
  public String next() {
    try {
      return reader.readLine();
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }
  public int nextInt() {
    try {
      return Integer.parseInt(next());
    } catch (NumberFormatException e) {
      throw new RuntimeException(e);
    }
  }
  public int[] nextIntArray() {
    String[] line = next().split(" ");
    int[] arr = new int[line.length];
    for (int i = 0; i < line.length; i++) {
      arr[i] = Integer.parseInt(line[i]);
    }
    return arr;
  }
}

// Define the Input class and its methods for reading input ends here

