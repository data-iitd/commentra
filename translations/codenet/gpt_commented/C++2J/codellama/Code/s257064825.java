
// Optimize input/output operations
import java.io.*;
import java.util.*;

// Define 'int' as 'long long int' for larger integer support
// Note: Java does not support 'long long int'
// Hence, we use 'long' instead
// Also, Java does not support 'char'
// Hence, we use 'String' instead

public class Main {
    public static void main(String[] args) {
        // Declare a string to hold the input
        String str;
        // Read the input string from the user
        Scanner sc = new Scanner(System.in);
        str = sc.nextLine();
        
        // Initialize a variable to hold the sum of digits
        long sum = 0;
        
        // Iterate through each character in the string
        for(int i = 0; i < str.length(); i++)
        {
            // Convert character to integer and add to sum
            sum += (str.charAt(i) - 48); // '48' is the ASCII value of '0'
        }
        
        // Check if the sum of digits is divisible by 9
        if(sum % 9 == 0)
        {
            // If divisible, print "Yes"
            System.out.println("Yes");
        }
        else
        {
            // If not divisible, print "No"
            System.out.println("No");
        }
    }
}

