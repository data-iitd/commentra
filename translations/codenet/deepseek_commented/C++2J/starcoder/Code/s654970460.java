import java.util.*;  // Include the necessary header files for input and output operations.

public class Main{  // Define the main class which is the entry point of the program.
  public static void main(String[] args){  // Define the main function which is the entry point of the program.
    int n, a[] = new int[101], i;  // Declare an integer variable 'n' to store the number of elements, an array 'a' of size 101, and an integer variable 'i' for looping.
    Scanner input = new Scanner(System.in);  // Create a Scanner object to read input from stdin.
    n = input.nextInt();  // Input the number of elements for the array 'a'.
    for(i = 0; i < n; i++)  // Loop to take 'n' integer inputs and store them in the array 'a'.
      a[i] = input.nextInt();
    System.out.print(a[n-1]);  // Output the last element of the array 'a'.
    for(i = 1; i < n; i++)  // Loop to output the remaining elements of the array 'a' in reverse order.
      System.out.print(" " + a[n-i-1]);
    System.out.println();  // End the line after outputting all the elements.
  }
}
