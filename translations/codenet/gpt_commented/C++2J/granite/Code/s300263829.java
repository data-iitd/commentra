
import java.util.Scanner; // Import the Scanner class from the java.util package to read user input

public class s300263829{ // Define a class named s300263829 with a public access modifier
  public static void main(String[] args) { // Define a main method that serves as the entry point for the program
    Scanner scanner = new Scanner(System.in); // Create an instance of the Scanner class to read user input
    int a = scanner.nextInt(); // Read an integer from user input and store it in variable a
    int b = scanner.nextInt(); // Read another integer from user input and store it in variable b
    System.out.println("The product is: " + a * b); // Display the product of a and b using string concatenation
  }
}
