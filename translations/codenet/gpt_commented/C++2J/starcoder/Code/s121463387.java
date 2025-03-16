import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Declare variables for input number 'n' and current number 'x'
    int n, x;
    String s;

    // Read the upper limit 'n' from user input
    Scanner in = new Scanner(System.in);
    n = in.nextInt();

    // Loop through numbers from 1 to n
    for(int i = 1; i <= n; i++){
      x = i; // Assign the current number to 'x'
      s = Integer.toString(x); // Convert 'x' to string for digit analysis

      // Check if 'x' is divisible by 3 or ends with the digit 3
      if(x % 3 == 0 || x % 10 == 3){
        System.out.print(" " + i); // Print the number if condition is met
        continue; // Skip to the next iteration
      }
      else {
        // Get the number of digits in 'x'
        int k = s.length();
        // Loop through each digit of 'x' from the most significant to the least
        while(k > 0){
          k = k - 1; // Decrease the digit index
          int j = (int) Math.pow(10, k); // Calculate the place value for the current digit
          // Check if the current digit is 3
          if((x / j) % 10 == 3){
            System.out.print(" " + i); // Print the number if it contains the digit 3
            break; // Exit the loop as we found a 3
          }
        }
      }
    }
    
    System.out.println(); // Print a newline after all numbers are processed
  }
}
