import java.util.Scanner; // Importing Scanner class for input

public class Main {
  public static void main(String[] args) { // Main method is the entry point of the program
    Scanner sc = new Scanner(System.in); // Initialize Scanner object to read input
    int n = sc.nextInt(); // Read the size of the array
    int[] a = new int[n]; // Initialize the array with size n
    for(int i = 0; i<n; i++) { // Read n integers from the user and store them in the array
      a[i] = sc.nextInt();
    }
    int count = bubbleSort(a, n); // Call the bubbleSort method to sort the array and get the count of swaps
    for(int i = 0; i<n; i++) { // Print the sorted array
      if(i<n-1){
        System.out.print(a[i] + " ");
      } else {
        System.out.println(a[i]);
      }
    }
    System.out.println(count); // Print the number of swaps made during the sorting process
  }

  public static int bubbleSort(int[] a, int n) { // Bubble sort method to sort the array
    boolean flag = true; // Flag to check if any swaps were made
    int count = 0; // Initialize the swap count
    while(flag == true) { // Continue sorting until no swaps are made
      flag = false; // Assume no swaps will be made
      for(int j = n-1; j>0; j--) { // Iterate through the array from the end to the beginning
        if(a[j]<a[j-1]) { // If the current element is smaller than the previous element
          int free = a[j]; // Swap the elements
          a[j] = a[j-1];
          a[j-1] = free;
          count++; // Increment the swap count
          flag = true; // Set flag to true as a swap was made
        }
      }
    }
    return count; // Return the total number of swaps made
  }
}
