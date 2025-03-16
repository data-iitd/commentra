
import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Declare a string variable to hold the input
    String W;
    
    // Read input string from the user
    Scanner sc = new Scanner(System.in);
    W = sc.next();
    
    // Sort the characters in the string in ascending order
    char[] arr = W.toCharArray();
    Arrays.sort(arr);

    // Iterate through the sorted string, checking pairs of characters
    for (int i = 0; i < arr.length - 1; i++)
    {
      // Check if the current character is not equal to the next character
      if (arr[i]!= arr[i + 1])
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

