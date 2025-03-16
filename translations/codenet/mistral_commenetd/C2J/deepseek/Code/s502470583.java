import java.util.Scanner; // Import the Scanner class to read input from the user

public class Main { // Start of the Main class
  public static void main(String[] args) { // Start of the main method
    Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
    int a, b, c, d; // Declare four integer variables a, b, c, and d

    // Read two integers from the user and store them in variables a and b
    a = scanner.nextInt();
    b = scanner.nextInt();

    // Multiply the two integers and store the result in variable c
    c = a * b;

    // Multiply each integer with 2 and add them to get the value of d
    d = 2 * a + 2 * b;

    // Print the values of c and d on the console
    System.out.println(c + " " + d);

    // End of the main method and return
  } // End of the main method
} // End of the Main class <END-OF-CODE>