
// Import the Scanner class for input operations
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input operations
        Scanner sc = new Scanner(System.in);
        
        // Declare variables for input and processing
        int a, b, c, d, e, f, g, T;
        String z;
        
        // Read the input string
        z = sc.nextLine();
        
        // Get the size of the input string
        a = z.length();
        
        // Check for consecutive identical characters in the string
        for (int i = 0; i < a - 1; i++)
        {
            // If two consecutive characters are the same, print "Bad" and exit
            if (z.charAt(i) == z.charAt(i + 1))
            {
                System.out.println("Bad");
                return;
            }
        }
        
        // If no consecutive identical characters were found, print "Good"
        System.out.println("Good");
    }
}

