
import java.util.*; // Import the necessary classes and packages

public class s579031873{ // Define the main class
  public static void main(String[] args) { // Define the main method
    Scanner sc = new Scanner(System.in); // Create a scanner object to read input from the standard input
    int N = sc.nextInt(); // Read the value of N from the standard input
    int X = sc.nextInt(); // Read the value of X from the standard input
    int[] a = new int[N]; // Create an array of integers with length N
    int min = Integer.MAX_VALUE; // Initialize the minimum value variable
    for (int i = 0; i < N; i++) { // Loop through N elements
      a[i] = sc.nextInt(); // Read the value into the array
      X -= a[i]; // Subtract the value from X
      if (a[i] < min) min = a[i]; // Update the minimum value if the current value is smaller
    }
    int ans = N + X / min; // Calculate the final answer by adding the quotient of X divided by the minimum value
    System.out.println(ans); // Print the final answer to the standard output
  }
}
