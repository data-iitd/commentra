import java.util.*;

// Update 2019/12/13

public class Main {

  // Create a Scanner object for input
  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    // Read three long integers from input
    long n = nextLong(); // Total number of elements
    long a = nextLong(); // First position
    long b = nextLong(); // Second position

    // Calculate the absolute difference between positions a and b
    long sa = Math.abs(a - b);

    // Initialize the answer variable
    long ans = 0;

    // Check if the difference is even
    if (sa % 2 == 0) {
      // If even, the answer is half the difference
      ans = sa / 2;
    } else {
      // If odd, calculate the minimum distance to the edges for both positions
      long AAA = Math.min((n - a), (a - 1)); // Distance from a to the nearest edge
      long BBB = Math.min((n - b), (b - 1)); // Distance from b to the nearest edge

      // Set ans to the minimum distance to the edge
      ans = Math.min(AAA, BBB); // Move one position to the edge

      // Decrease the difference by 1 to make it even
      sa -= 1;
      ans += 1; // Increment the answer since we moved one position

      // Now the difference is even, add half of the new difference to the answer
      ans += sa / 2;
    }

    // Output the final answer
    System.out.println(ans);

    // Uncomment the line below for debugging purposes
    // System.out.println(1/2);
  }

  // Method to read a string from input
  static String next() {
    return sc.next();
  }

  // Method to read an integer from input
  static int nextInt() {
    return Integer.parseInt(sc.next());
  }

  // Method to read a long integer from input
  static long nextLong() {
    return Long.parseLong(sc.next());
  }

  // Method to read a double from input
  static double nextDouble() {
    return Double.parseDouble(sc.next());
  }

  // Method to split a string into an array of strings
  static String[] splitString(String s) {
    return s.split("");
  }

  // Method to convert a string into a character array
  static char[] splitChar(String s) {
    return s.toCharArray();
  }

  // Method to convert a character to its integer value
  static int charToInt(char aaa) {
    return aaa - 48; // ASCII conversion
  }

  // Method to find the maximum integer in an array
  public static int maxInt(int[] a, int lng) {
    int max = a[0]; // Initialize max with the first element
    for (int i = 1; i < lng; i++) {
      max = Math.max(max, a[i]); // Update max if a larger value is found
    }
    return max; // Return the maximum value
  }

  // Method to find the minimum integer in an array
  public static int minInt(int[] a, int lng) {
    int min = a[0]; // Initialize min with the first element
    for (int i = 1; i < lng; i++) {
      min = Math.min(min, a[i]); // Update min if a smaller value is found
    }
    return min; // Return the minimum value
  }

  // Method to find the maximum long in an array
  public static long maxLong(long[] a, int lng) {
    long max = a[0]; // Initialize max with the first element
    for (int i = 1; i < lng; i++) {
      max = Math.max(max, a[i]); // Update max if a larger value is found
    }
    return max; // Return the maximum value
  }

  // Method to find the minimum long in an array
  public static long minLong(long[] a, int lng) {
    long min = a[0]; // Initialize min with the first element
    for (int i = 1; i < lng; i++) {
      min = Math.min(min, a[i]); // Update min if a smaller value is found
    }
    return min; // Return the minimum value
  }
}
