import java.util.Scanner; // Import the Scanner class to read input from the user

public class Main { // Define a public class named Main
  public static void main(String[] args) { // Define the main method
    Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
    int a = scanner.nextInt(); // Read an integer from the standard input and assign it to variable a
    int b = scanner.nextInt(); // Read another integer from the standard input and assign it to variable b
    System.out.println(a * b); // Multiply the values of variables a and b and print the result to the standard output
  }
}
