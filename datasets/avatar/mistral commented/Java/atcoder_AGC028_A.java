#######
// Import necessary libraries
#######
import java.math.BigInteger;  // For handling big integers
import java.util.*;           // For Scanner and other utility classes
import java.util.stream.*;    // For using Stream API

public class Main {
  // Initialize a Scanner object for reading input
  static Scanner scanner = new Scanner(System.in);

  // Main method to start the program
  public static void main(String[] args) {
    // Read input values for n and m
    int n = scanner.nextInt();
    int m = scanner.nextInt();

    // Calculate the greatest common divisor (GCD) of n and m
    int gcd = BigInteger.valueOf(n).gcd(BigInteger.valueOf(m)).intValue();

    // Read input strings s and t
    String s = scanner.next();
    String t = scanner.next();

    // Perform the required calculation and print the result
    long result = IntStream.range(0, gcd)
                          .filter(k -> s.charAt(k * n / gcd) != t.charAt(k * m / gcd))
                          .mapToLong(k -> -1)
                          .findAny()
                          .orElse(BigInteger.valueOf(n).multiply(BigInteger.valueOf(m)).divide(BigInteger.valueOf(gcd)).longValue());

    // Print the result
    System.out.println(result);
  }
}
