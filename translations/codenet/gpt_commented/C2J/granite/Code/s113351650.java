
import java.util.Scanner;

public class s113351650{
  
  public static void main(String[] args) {
    
    // Create a Scanner object to read user input
    Scanner scanner = new Scanner(System.in);
    
    // Prompt the user for input and read an integer value into 'x'
    int x = scanner.nextInt();
    
    // Check if the input value is 0
    if (x == 0) 
      // If true, print "1" to the output
      System.out.println("1");
    
    // Check if the input value is 1
    if (x == 1) 
      // If true, print "0" to the output
      System.out.println("0");
    
    // Close the Scanner object to release system resources
    scanner.close();
    
  }
  
}
