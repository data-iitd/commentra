
import java.util.*;
import java.io.*;

public class s559238064{
    public static void main(String[] args) throws IOException {
        // Define variables for input and processing
        long a, b, c, d, e, f, g, T;
        String z;
        
        // Read the input string
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        z = br.readLine();
        
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
