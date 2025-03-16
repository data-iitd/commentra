import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read the number of elements to be sorted
    int n = sc.nextInt();
    
    // Initialize an array to hold the elements
    int[] a = new int[n];
    
    // Read the elements into the array
    for(int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    
    // Call the bubbleSort method to sort the array and get the number of swaps
    int count = bubbleSort(a, n);
    
    // Print the sorted array
    for(int i = 0; i < n; i++) {
      if(i < n - 1) {
        System.out.print(a[i] + " "); // Print elements in the same line with space
      } else {
        System.out.println(a[i]); // Print the last element followed by a newline
      }
    }
    
    // Print the total number of swaps made during sorting
    System.out.println(count);
  }

  // Method to perform bubble sort on the array
  public static int bubbleSort(int[] a, int n) {
    boolean flag = true; // Flag to check if any swaps were made
    int count = 0; // Counter for the number of swaps
    
    // Continue sorting until no swaps are made in a complete pass
    while(flag == true) {
      flag = false; // Reset flag for this pass
      // Traverse the array from the end to the beginning
      for(int j = n - 1; j > 0; j--) {
        // Compare adjacent elements and swap if they are in the wrong order
        if(a[j] < a[j - 1]) {
          int free = a[j]; // Temporary variable to hold the value
          a[j] = a[j - 1]; // Swap the elements
          a[j - 1] = free; // Complete the swap
          count++; // Increment the swap counter
          flag = true; // Set flag to true indicating a swap occurred
        }
      }
    }
    // Return the total number of swaps made
    return count;
  }
}
