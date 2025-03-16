
import java.util.Scanner; // Import standard input/output library

public class Main{ // Beginning of main class

 public static void main(String[] args){ // Beginning of main function

  int a, b, n; // Declare and initialize three integer variables

  Scanner input = new Scanner(System.in); // Create a Scanner object

  System.out.print("Enter two integers: "); // Prompt user to enter two integers
  a = input.nextInt(); // Read two integers from standard input and store in variables a and b
  b = input.nextInt();

  n=(a+b)/2; // Calculate the average of a and b and store the result in variable n

  System.out.printf("The average of %d and %d is: %d\n",a,b,n); // Display the average on standard output

 } // End of main function

} // End of main class

