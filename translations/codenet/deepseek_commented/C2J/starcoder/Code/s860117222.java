import java.util.Scanner;  // Import the Scanner class

public class Main {  // Define the main class
  public static void main(String[] args) {  // Define the main function
    Scanner input = new Scanner(System.in);  // Create a Scanner object to read from the standard input

    long a = input.nextLong();  // Read a long integer from the user
    long b = input.nextLong();  // Read a long integer from the user
    long c = input.nextLong();  // Read a long integer from the user

    long d = c - a - b;  // Calculate the difference between c and the sum of a and b
    if ((d > 0) && ((4 * a * b) < d * d))  // Check if the difference is positive and satisfies the specific condition
      System.out.println("Yes");  // Print "Yes" if the condition is met
    else
      System.out.println("No");  // Print "No" otherwise
  }
}
