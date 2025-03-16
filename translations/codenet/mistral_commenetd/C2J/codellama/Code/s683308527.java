
import java.util.Scanner; // Import the Scanner class for reading input from the user

public class Main { // Start of the Main class
  public static void main(String[] args) { // Start of the main function
    Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the user
    int n = sc.nextInt(); // Read an integer 'n' from the user input
    sc.nextLine(); // Ignore the newline character

    while(n-- > 0) { // Start of the while loop that processes each string
      String s = sc.nextLine(); // Read a string from the user input
      int i = 0; // Initialize an integer variable 'i' to keep track of the index of the string

      while(i < s.length() && s.substring(i,i+7).equals("Hoshino")) { // Start of the inner while loop that replaces the substring "Hoshino" with "aana"
        s = s.substring(0,i) + "aana" + s.substring(i+7); // Replace the substring "Hoshino" with "aana"
        i += 4; // Increment the index by 4 to skip the replaced substring
      }

      System.out.println(s); // Print the modified string to the standard output
    }
  }
}

