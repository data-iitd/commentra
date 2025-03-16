
// Importing the 'java.util.Scanner' class for input/output operations
import java.util.Scanner;

public class s102334995{
  public static void main(String[] args) {
    // Creating a 'Scanner' object to read input from the standard input
    Scanner scanner = new Scanner(System.in);

    // Declaring two integer variables 'a' and 'b'
    int a = scanner.nextInt();
    int b = scanner.nextInt();

    // Multiplying the variables 'a' and 'b' and printing the result
    System.out.println(a * b);

    // Multiplying the sum of 'a' and 'b' with 2 and printing the result
    System.out.println((a + b) * 2);

    // Closing the 'Scanner' object
    scanner.close();
  }
}

// End of the code