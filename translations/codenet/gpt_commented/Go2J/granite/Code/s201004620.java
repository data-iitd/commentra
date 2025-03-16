
import java.util.Scanner;

public class s201004620{
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    
    // Read the weather condition from standard input
    String S = scanner.nextLine();
    
    // Use a switch statement to determine the next weather condition based on the input
    switch (S) {
    case "Sunny":
      // If the input is "Sunny", print "Cloudy" as the next condition
      System.out.println("Cloudy");
      break;
    case "Cloudy":
      // If the input is "Cloudy", print "Rainy" as the next condition
      System.out.println("Rainy");
      break;
    case "Rainy":
      // If the input is "Rainy", print "Sunny" as the next condition
      System.out.println("Sunny");
      break;
    }
  }
}
