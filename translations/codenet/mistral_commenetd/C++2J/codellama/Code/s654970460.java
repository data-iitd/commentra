import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Start of the Main class
  public static void main(String[] args) { // Start of the main function
    Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the command line
    int n = sc.nextInt(); // Read the size of the array from the user input
    int a[] = new int[n]; // Allocate memory for the array 'a' of size 'n'
    int i; // Declare an integer variable 'i' as a counter

    for(i=0; i<n;i++)
    {
      a[i] = sc.nextInt(); // Read each element of the array 'a' from the user input
    }

    System.out.print(a[n-1]); // Print the last element of the array

    for(i=1;i<n;i++)
    {
      System.out.print(" " + a[n-i-1]); // Print the current element with a space before it
    }

    System.out.println(); // Print a newline character at the end
  }
}
