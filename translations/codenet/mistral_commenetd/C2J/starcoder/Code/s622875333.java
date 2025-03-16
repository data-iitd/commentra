
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // Infinite loop until user inputs 0 for both n and r
    while (true) {
      System.out.print("Enter the number of elements in array a: ");
      int n = sc.nextInt();
      System.out.print("Enter the number of rotations: ");
      int r = sc.nextInt();

      if (n == 0 && r == 0) { // Exit the loop if n and r are both 0
        break;
      }

      // Initialize array a with the given size
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = n - i; // Set the initial values of array a
      }

      // Rotate the array r times
      for (int i = 0; i < r; i++) {
        System.out.println();
        // Print the current state of array a before rotation
        for (int j = 0; j < n; j++) {
          System.out.print(a[j] + " ");
        }
        System.out.println();

        // Create a copy of array a and store it in array b
        int[] b = new int[n];
        for (int j = 0; j < n; j++) {
          b[j] = a[j]; // Copy each element of array a to array b
        }

        // Read the number of elements to be rotated and the position from user
        System.out.print("Enter the number of elements to be rotated: ");
        int c = sc.nextInt();
        System.out.print("Enter the position: ");
        int p = sc.nextInt();

        // Rotate the array b by c positions to the left
        for (int j = 0; j < c; j++) {
          b[j] = b[j + 1]; // Shift each element of array b one position to the left
        }

        // Rotate the first part of array a by c positions to the left
        for (int j = 0; j < c; j++) {
          a[j] = b[p - 1 + j]; // Shift each element of the first part of array a by c positions to the left
        }

        // Rotate the second part of array a by (p-c) positions to the right
        for (int j = c; j < n; j++) {
          a[j] = b[j - c]; // Shift each element of the second part of array a by (p-c) positions to the right
        }

        // Print the current state of array a after rotation
        System.out.println();
        for (int j = 0; j < n; j++) {
          System.out.print(a[j] + " ");
        }
        System.out.println();
      }

      // Print the first element of the final array a
      System.out.println();
      System.out.println("The first element of the final array is: " + a[0]);
    }
  }
}

