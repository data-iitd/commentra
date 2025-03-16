
import java.util.Scanner;

public class s201004620{
  public static void main(String[] args) {
    // Declare a string variable S to store the weather input
    String S;
    
    // Create a Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    
    // Read a string input from the user and store it in S
    S = scanner.nextLine();
    
    // Use a switch statement to determine the weather based on the input
    switch (S) {
      case "Sunny" : 
        // If the input is "Sunny", print "Cloudy"
        System.out.println("Cloudy");
        break;
      case "Cloudy" : 
        // If the input is "Cloudy", print "Rainy"
        System.out.println("Rainy");
        break;
      case "Rainy" : 
        // If the input is "Rainy", print "Sunny"
        System.out.println("Sunny");
        break;
    }
    
    // Close the Scanner object
    scanner.close();
  }
}
