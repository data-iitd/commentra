
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Create a new Scanner object to read input from the standard input stream
    Scanner sc = new Scanner(System.in);

    // Read an integer value `n` from the user input using the Scanner object
    int n = sc.nextInt();

    // Check if the number `n` has a digit `9` in its last digit or in its tens digit
    if(n % 10 == 9 || n / 10 % 10 == 9) {
      // If the condition is true, print the message "Yes" to the standard output stream
      System.out.println("Yes");
    } else {
      // If the condition is false, print the message "No" to the standard output stream
      System.out.println("No");
    }

    // Close the Scanner object to release system resources
    sc.close();
  }
}