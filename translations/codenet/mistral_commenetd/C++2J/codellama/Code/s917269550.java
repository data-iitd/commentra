
import java.util.Scanner; // Import Scanner class for input/output

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Create a new Scanner object
    long x = sc.nextLong(); // Read the first long integer from the standard input
    long y = sc.nextLong(); // Read the second long integer from the standard input
    long diff = Math.abs(x - y); // Calculate the absolute difference between x and y
    if (diff <= 1) { // Check if the absolute difference is less than or equal to 1
      System.out.println("Brown"); // If the condition is true, print "Brown" to the standard output
    } else {
      System.out.println("Alice"); // If the condition is false, print "Alice" to the standard output
    }
  }
}

