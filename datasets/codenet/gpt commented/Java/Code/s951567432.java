import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Read an integer input from the user which represents the count
    int count = new Scanner(System.in).nextInt();
    
    // Initialize a variable to hold the total sum
    int total = 0;
    
    // Loop from 1 to the specified count and accumulate the sum
    for (int ix = 1; ix <= count; ix++) {
      total += ix; // Add the current number to the total
    }
    
    // Output the total sum to the console
    System.out.println(total);
  }
}
