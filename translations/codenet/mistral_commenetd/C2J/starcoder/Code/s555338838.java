import java.util.*;

public class BubbleSort {
  public static void main(String[] args) {
    // Declare variables
    int key, i, j, len, a[];

    // Read the length of the array from the user
    System.out.print("Enter the length of the array: ");
    len = Integer.parseInt(System.console().readLine());

    // Read the elements of the array from the user
    System.out.print("Enter " + len + " integers: ");
    a = new int[len];
    for(i = 0;i < len;i++) {
      a[i] = Integer.parseInt(System.console().readLine());
    }

    // Sort the array using bubble sort algorithm
    for(j = 1;j < len;j++){
      // Iterate through the array and compare each element with the current key
      for(i = 0;i < len;i++) {
        // If the current element is not the first one, print it with a space
        if(i!= 0) System.out.print(" " + a[i]);
        // Otherwise, print it without a space
        else System.out.print(a[i]);
      }
      // Print a new line after each pass
      System.out.println("");

      // Set the current key to the next element
      key = a[j];

      // Swap the current key with the previous element if it is greater
      for(i = j - 1;i >= 0 && a[i] > key;i--) {
        a[i + 1] = a[i];
      }

      // Swap the current key with the previous element
      a[i + 1] = key;
    }

    // Print the sorted array
    for(i = 0;i < len;i++) {
      // If the current index is not the first one, print it with a space
      if(i!= 0) System.out.print(" " + a[i]);
      // Otherwise, print it without a space
      else System.out.print(a[i]);
    }
    // Print a new line after printing the sorted array
    System.out.println("");
  }
}
