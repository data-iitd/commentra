import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Create a new Scanner object to read from standard input
    int N = sc.nextInt(); // Read the number of elements
    int X = sc.nextInt(); // Read the target value
    int ans = 0; // Initialize the answer variable
    int min = 1000000000; // Initialize the minimum value variable
    for (int i = 0; i < N; i++) { // Loop through N elements
      int tmp = sc.nextInt(); // Read the value into the temporary variable
      X -= tmp; // Subtract the value from X
      ans++; // Increment the answer count
      if (tmp < min) min = tmp; // Update the minimum value if the current value is smaller
    }
    ans += X / min; // Calculate the final answer by adding the quotient of X divided by the minimum value
    System.out.println(ans); // Print the final answer to the standard output
  }
}

