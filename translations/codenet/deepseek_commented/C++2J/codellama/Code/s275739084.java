import java.util.Scanner; // Import the Scanner class for input operations.
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Create a Scanner object to take input from the command line.
    int A = sc.nextInt(); // Read an integer from the user and store it in variable A.
    int B = sc.nextInt(); // Read an integer from the user and store it in variable B.
    int C = A + B; // Calculate the sum of A and B and store it in variable C.
    if (A % 3 != 0 && B % 3 != 0 && C % 3 != 0) { // Check if neither A, B, nor the sum C is divisible by 3.
      System.out.println("Impossible"); // If the condition is true, print "Impossible" to the console.
    } else {
      System.out.println("Possible"); // Otherwise, print "Possible" to the console.
    }
    sc.close(); // Close the Scanner object.
  }
}
