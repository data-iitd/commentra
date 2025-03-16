// Include the Scanner class for input and output operations
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare two integer variables a and b to store user input
    int a, b;
    
    // Create a Scanner object to read user input
    Scanner sc = new Scanner(System.in);
    
    // Prompt the user to enter two integers
    System.out.print("Enter two integers: ");
    
    // Read two integers from user input and store them in variables a and b
    a = sc.nextInt();
    b = sc.nextInt();
    
    // Calculate the product of a and b and display the result
    System.out.println("The product is: " + a * b);
    
    // Close the Scanner object
    sc.close();
  }
}

