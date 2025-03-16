
import java.util.Scanner;

public class s878644875{
  public static void main(String[] args) {
    // Declare two character arrays to hold the input strings
    char[] s = new char[4];
    char[] t = new char[4];
    
    // Create a Scanner object to read user input
    Scanner scanner = new Scanner(System.in);
    
    // Read the first string from user input
    scanner.nextLine().getChars(0, 4, s, 0);
    
    // Read the second string from user input
    scanner.nextLine().getChars(0, 4, t, 0);
    
    // Initialize a counter to keep track of matching characters
    int hit = 0;
    
    // Loop through the first three characters of both strings
    for (int i = 0; i < 3; i++){
      // Check if the characters at the same position in both strings match
      if (s[i] == t[i]) 
        hit++; // Increment the hit counter if there's a match
    }
    
    // Output the total number of matching characters
    System.out.println(hit);
    
    // Close the Scanner object to release system resources
    scanner.close();
  }
}
