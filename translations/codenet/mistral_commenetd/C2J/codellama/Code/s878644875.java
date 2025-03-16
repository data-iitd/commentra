
import java.util.Scanner; // Import the Scanner class from the java.util package

public class Main { // Declare a public class called Main
  public static void main(String[] args) { // Declare a public static void method called main that takes an array of String arguments
    Scanner sc = new Scanner(System.in); // Create a new Scanner object called sc that reads from the standard input
    char[] s = sc.nextLine().toCharArray(); // Read a line of text from the standard input and store it in an array of characters called s
    char[] t = sc.nextLine().toCharArray(); // Read a line of text from the standard input and store it in an array of characters called t
    int hit = 0; // Initialize a counter variable called hit to 0
    for (int i = 0; i < 3; i++) { // Start a for loop that iterates from 0 to 2 (3 times)
      if (s[i] == t[i]) hit++; // If the i-th character of string s is equal to the i-th character of string t, increment the counter variable hit
    }
    System.out.println(hit); // Print the value of the counter variable hit to the standard output followed by a newline character
  }
}

