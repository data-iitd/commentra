import java.util.*;

public class Main {
  // Function to calculate the sum of digits of 'n' in base 'k'
  private static long split(long n, long k) {
    long sum = 0; // Initialize sum to 0
    // Loop until 'n' becomes 0
    while (n > 0) {
      sum += n % k; // Add the last digit in base 'k' to sum
      n /= k; // Remove the last digit from 'n'
    }
    return sum; // Return the calculated sum
  }

  // Function to find the smallest base 'k' such that the sum of digits of 'n' in base 'k' equals 's'
  private static long solve(long n, long s) {
    long k; // Variable to hold the base
    // Loop to find a suitable base 'k' starting from 2
    for (k = 2; k*k <= n || k < 100; k++) {
      // Check if the sum of digits in base 'k' equals 's'
      if (split(n, k) == s) {
        return k; // Return the found base 'k'
      }
    }
    // Continue searching for 'k' beyond 100 until 'n'
    while (k <= n) {
      long a = n / k; // Calculate the quotient of n divided by k
      long b = n % k; // Calculate the remainder of n divided by k
      // Check if we can adjust 'k' to satisfy the condition
      if ((a + b - s) % a == 0) {
        long dk = (a + b - s) / a; // Calculate the adjustment needed for 'k'
        // Ensure the adjustment is valid
        if (dk >= 0 && b - dk*a >= 0) {
          return k + dk; // Return the adjusted base
        }
      }
      k = n / a + 1; // Update 'k' for the next iteration
    }
    // If 'n' is equal to 's', return 'n + 1' as the next base
    if (n == s) {
      return n + 1;
    }
    return -1; // Return -1 if no suitable base is found
  }

  // Main method to execute the program
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in); // Create a Scanner object for input
    long nl = s.nextLong(); // Read the value of 'n'
    long sl = s.nextLong(); // Read the value of 's'
    System.out.println(solve(nl, sl)); // Call solve and print the result
  }
}
