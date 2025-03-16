
import java.util.*; // Importing the utility class Scanner from java.util package

public class Main {
  // A private static method to calculate the sum of digits of a number
  private static long split(long n, long k) {
    long sum = 0; // Initializing sum to 0
    while (n > 0) { // While number n is greater than 0
      sum += n % k; // Adding the remainder of n divided by k to sum
      n /= k; // Dividing n by k
    }
    return sum; // Returning the sum
  }

  // A private static method to find the smallest number k such that split(n, k) = s
  private static long solve(long n, long s) {
    long k; // Initializing k as a variable to loop through
    for (k = 2; k*k <= n || k < 100; k++) { // Looping through numbers from 2 to the square root of n or less than 100
      if (split(n, k) == s) { // If the sum of digits of n divided by k equals s
        return k; // Return k as the solution
      }
    }
    while (k <= n) { // Looping through numbers greater than or equal to the square root of n
      long a = n / k; // Calculating the quotient of n divided by k
      long b = n % k; // Calculating the remainder of n divided by k
      if ((a + b - s) % a == 0) { // Checking if (a + b - s) is divisible by a
        long dk = (a + b - s) / a; // Calculating the quotient of (a + b - s) divided by a
        if (dk >= 0 && b - dk*a >= 0) { // Checking if dk is non-negative and b - dk*a is non-negative
          return k + dk; // Return k + dk as the solution
        }
      }
      k = n / a + 1; // Incrementing k by 1 if the current value of k is not the solution
    }
    if (n == s) { // Checking if n is equal to s
      return n+1; // Return n+1 as the solution if n is equal to s
    }
    return -1; // Return -1 if no solution is found
  }

  // The main method to read input and call the solve method
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in); // Creating a new Scanner object to read input from the console
    long nl = s.nextLong(); // Reading the first long integer from the console and storing it in nl
    long sl = s.nextLong(); // Reading the second long integer from the console and storing it in sl
    System.out.println(solve(nl, sl)); // Calling the solve method with nl and sl as arguments and printing the result to the console