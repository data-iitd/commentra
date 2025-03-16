import java.util.Scanner; // Import the Scanner class to read input

public class AverageCalculator { // Define a public class named AverageCalculator

 public static void main(String[] args) { // Beginning of main function

 int a, b, n; // Declare three integer variables

 Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input

 System.out.println("Enter two integers: "); // Prompt user to enter two integers
 a = scanner.nextInt(); // Read the first integer and store in variable a
 b = scanner.nextInt(); // Read the second integer and store in variable b

 n = (a + b) / 2; // Calculate the average of a and b and store the result in variable n

 System.out.printf("The average of %d and %d is: %d\n", a, b, n); // Display the average on standard output

 scanner.close(); // Close the Scanner object
 }
}
