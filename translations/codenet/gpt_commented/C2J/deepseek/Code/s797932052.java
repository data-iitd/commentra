public class Main {
  public static void main(String[] args) {
    // Declare two integer variables to hold user input
    int a, b;

    // Create a Scanner object to read input from the user
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    
    // Read the first integer from user input
    a = scanner.nextInt();
    
    // Read the second integer from user input
    b = scanner.nextInt();
    
    // Check if the product of a and b is even
    if((a * b) % 2 == 0) {
      // If the product is even, print "Even"
      System.out.println("Even");
    } else {
      // If the product is odd, print "Odd"
      System.out.println("Odd");
    }
    
    // Return 0 to indicate successful completion of the program
