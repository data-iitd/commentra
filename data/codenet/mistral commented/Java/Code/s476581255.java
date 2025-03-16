
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Initialize a Scanner object to read input from the standard input stream
    Scanner sc = new Scanner(System.in);

    // Read an integer `n` as input
    int n = sc.nextInt();

    // Initialize an integer array `a` of size `n`
    int[] a = new int[n];

    // Use a for loop to read `n` integers from the standard input stream and store them in the array `a`
    for(int i = 0; i<n; i++) {
      a[i] = sc.nextInt(); // Read an integer from the standard input stream and store it in the current index of the array `a`
    }

    // Call the `bubbleSort` method with the array `a` and its size `n` as arguments
    int count = bubbleSort(a, n);

    // Print the sorted array `a` to the standard output stream
    for(int i = 0; i<n; i++) {
      if(i<n-1){
        System.out.print(a[i] + " "); // Print the current element of the array `a` followed by a space if it's not the last element
      }else {
        System.out.println(a[i]); // Print the last element of the array `a` on a new line
      }
    }

    // Print the number of swaps made during the sorting process to the standard output stream
    System.out.println(count);
  }

  // The `bubbleSort` method sorts an integer array `a` of size `n` using the bubble sort algorithm
  public static int bubbleSort(int[] a,int n) {
    boolean flag = true; // Initialize a boolean flag to keep track of whether any swaps were made during a pass through the array
    int count = 0; // Initialize a counter to keep track of the number of swaps made during the sorting process

    // Use a while loop to continue sorting the array as long as swaps are made during a pass through the array
    while(flag == true) {
      flag = false; // Initialize the flag to false to assume no swaps were made during this pass through the array
      for(int j = n-1;j>0; j--) {
        // Swap adjacent elements if they are in the wrong order
        if(a[j]<a[j-1]) {
          int free = a[j]; // Swap the elements at indices `j` and `j-1`
          a[j] = a[j-1];
          a[j-1] = free;
          count++; // Increment the counter by 1 for each swap made
          flag = true; // Set the flag to true to indicate that swaps were made during this pass through the array
        }
      }
    }

    // Return the number of swaps made during the sorting process
    return count;
  }
}