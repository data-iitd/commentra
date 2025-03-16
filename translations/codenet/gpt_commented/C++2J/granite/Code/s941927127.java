
import java.util.Scanner;
import java.util.Arrays;

public class s941927127{
  public static void main(String[] args) {
    // Declare a string variable to hold the input
    String W;
    
    // Create a Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    
    // Read input string from the user
    W = scanner.nextLine();
    
    // Sort the characters in the string in ascending order
    char[] charArray = W.toCharArray();
    Arrays.sort(charArray);
    W = new String(charArray);

    // Iterate through the sorted string, checking pairs of characters
    for (int i = 0; i < W.length(); i += 2)
    {
      // Check if the current character is not equal to the next character
      if (W.charAt(i)!= W.charAt(i + 1))
      {
        // If they are not equal, print "No" and exit the program
        System.out.println("No");
        return;
      }
    }
    
    // If all pairs are equal, print "Yes"
    System.out.println("Yes");
  }
}
