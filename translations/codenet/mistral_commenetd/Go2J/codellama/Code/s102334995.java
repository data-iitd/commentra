// Importing the 'Scanner' class for input/output operations
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declaring two integer variables 'a' and 'b'
    int a, b;

    // Creating an object of the 'Scanner' class
    Scanner sc = new Scanner(System.in);

    // Reading input values for variables 'a' and 'b' from the standard input
    a = sc.nextInt();
    b = sc.nextInt();

    // Multiplying the variables 'a' and 'b' and printing the result
    System.out.println(a * b);

    // Multiplying the sum of 'a' and 'b' with 2 and printing the result
    System.out.println((a + b) * 2);
  }
}

// End of the code 