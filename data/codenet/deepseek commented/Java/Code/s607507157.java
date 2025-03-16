
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read an integer input from the user
    int n = sc.nextInt();
    
    // Check if the number ends with 9 or contains a 9 in any of its digits
    if(n % 10 == 9 || n / 10 == 9) {
      // Print "Yes" if the condition is true
      System.out.println("Yes");
    } else {
      // Print "No" if the condition is false
      System.out.println("No");
    }
  }
}

