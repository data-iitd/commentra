
import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    
    // Read an integer input from the user and store it in the 'count' variable
    int count = scanner.nextInt();
    
    // Initialize a variable 'total' to 0 to accumulate the sum of numbers
    int total = 0;
    
    // Use a for loop to iterate from 1 to 'count', incrementing by 1 each time
    for (int ix = 1; ix <= count; ix++) {
      // Add the current value of 'ix' to 'total'
      total += ix;
    }
    
    // Print the value of 'total' to the console
    System.out.println(total);
  }
}

