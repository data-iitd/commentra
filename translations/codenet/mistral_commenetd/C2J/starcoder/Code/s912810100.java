
import java.util.Scanner; // Import the Scanner class from the Java standard library

public class Main { // Start of the Main class
  public static void main(String[] args) { // Start of the main function
    Scanner input = new Scanner(System.in); // Create a Scanner object to read from the standard input

    int a, b, x, y; // Declare variables a, b, x, and y as integers

    a = input.nextInt(); // Read an integer from the standard input and store it in variable a
    b = input.nextInt(); // Read an integer from the standard input and store it in variable b

    x = a*b; // Multiply the values of variables a and b and store the result in variable x
    y = (a+b)*2; // Add the values of variables a and b, then multiply the result by 2 and store it in variable y

    System.out.println(x + " " + y); // Print the values of variables x and y to the standard output, followed by a newline character
  }
}
