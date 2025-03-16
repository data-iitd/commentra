
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Optimize input/output operations
        Scanner scanner = new Scanner(System.in);
        
        // Declare variables for input and processing
        String z;
        int a;
        
        // Read the input string
        z = scanner.next();
        
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

