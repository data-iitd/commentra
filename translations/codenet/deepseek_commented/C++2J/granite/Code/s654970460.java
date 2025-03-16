
import java.util.*;  // Import the necessary classes for input and output operations.

public class s654970460{  // Define the main class which contains the main method.
  public static void main(String[] args) {  // Define the main method which is the entry point of the program.
    Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input from the user.
    int n = sc.nextInt();  // Input the number of elements for the array 'a'.
    int[] a = new int[n];  // Create an array 'a' of size 'n' to store the integer inputs.
    for(int i = 0; i < n; i++)  // Loop to take 'n' integer inputs and store them in the array 'a'.
      a[i] = sc.nextInt();
    System.out.print(a[n-1]);  // Output the last element of the array 'a'.
    for(int i = 1; i < n; i++)  // Loop to output the remaining elements of the array 'a' in reverse order.
      System.out.print(" " + a[n-i-1]);
    System.out.println();  // End the line after outputting all the elements.
  }
}
