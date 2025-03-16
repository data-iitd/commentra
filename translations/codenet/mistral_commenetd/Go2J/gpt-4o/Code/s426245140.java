// Import the Scanner class for reading input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Define a variable named "s" to store user input
        String s = scanner.nextLine();
        
        // Check if the first three characters of the string "s" form an identical sequence
        if ((s.length() >= 4) && ((s.charAt(0) == s.charAt(1) && s.charAt(1) == s.charAt(2)) || 
            (s.charAt(1) == s.charAt(2) && s.charAt(2) == s.charAt(3)))) {
            // If the condition is true, print "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No" to the standard output
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
