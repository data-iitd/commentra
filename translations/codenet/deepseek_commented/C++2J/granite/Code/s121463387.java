
import java.util.Scanner;

public class s121463387{
  public static void main(String[] args) {
    // Declare variables to store input and intermediate results
    int n, x;
    String s;

    // Create a Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);

    // Read the value of n from standard input
    n = scanner.nextInt();

    // Loop through numbers from 1 to n
    for(int i = 1; i <= n; i++) {
      // Initialize x with the current number i and convert it to a string
      x = i;
      s = Integer.toString(x);

      // Check if the number is divisible by 3 or ends with 3
      if(x % 3 == 0 || x % 10 == 3) {
        System.out.print(" " + i); // Output the number if the condition is met
        continue;
      } else {
        // Check each digit of the number to see if it contains 3
        int k = s.length();
        while(k > 0) {
          k = k - 1;
          int j = (int)Math.pow(10, k);
          if((x / j) % 10 == 3) {
            System.out.print(" " + i); // Output the number if '3' is found in any digit
            break;
          }
        }
      }
    }

    // Output a newline character at the end of the program
    System.out.println();

    // Close the Scanner object
    scanner.close();
  }
}
