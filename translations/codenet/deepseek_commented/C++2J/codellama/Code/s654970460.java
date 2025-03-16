import java.util.Scanner;  // Import the Scanner class to read input from the user.

public class Main {  // Define a class named Main.
  public static void main(String[] args) {  // Define a main function which is the entry point of the program.
    Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input from the user.
    int n = sc.nextInt();  // Read an integer input from the user and store it in the variable 'n'.
    int[] a = new int[101];  // Declare an array 'a' of size 101 to store the input elements.
    for(int i = 0; i < n; i++)  // Loop to take 'n' integer inputs and store them in the array 'a'.
      a[i] = sc.nextInt();
    System.out.print(a[n-1]);  // Output the last element of the array 'a'.
    for(int i = 1; i < n; i++)  // Loop to output the remaining elements of the array 'a' in reverse order.
      System.out.print(" " + a[n-i-1]);
    System.out.println();  // End the line after outputting all the elements.
  }
}
