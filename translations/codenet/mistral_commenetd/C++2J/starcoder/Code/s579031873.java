import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in); // Create a new Scanner object for reading the standard input stream.
    int N = in.nextInt(); // Read an integer from the standard input stream and assign it to "N".
    int X = in.nextInt(); // Read an integer from the standard input stream and assign it to "X".

    int ans = 0; // Initialize an integer variable named "ans" to zero.
    int min = 1000000000; // Initialize an integer variable named "min" to a large value.

    for (int i = 0; i < N; i++) { // Start of a for loop that iterates from 0 to N-1.
      int tmp = in.nextInt(); // Read an integer from the standard input stream and assign it to "tmp".

      X -= tmp; // Subtract "tmp" from "X".
      ans++; // Increment "ans" by 1.

      if (tmp < min) min = tmp; // If "tmp" is smaller than the current minimum value, update the minimum value.
    }

    ans += X / min; // Divide "X" by the minimum value and add the quotient to "ans".

    System.out.println(ans); // Output the value of "ans" to the standard output stream.
  }
}

