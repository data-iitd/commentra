import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        // Optimize input/output operations
        Scanner sc = new Scanner(System.in);
        
        // Declare a string to hold the input
        String str = sc.next();
        
        // Initialize a variable to hold the sum of digits
        int sum = 0;
        
        // Iterate through each character in the string
        for(char x : str.toCharArray())
        {
            // Convert character to integer and add to sum
            sum += (x - 48); // '48' is the ASCII value of '0'
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

