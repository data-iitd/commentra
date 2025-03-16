/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main {
    public static void main (String[] args) throws java.lang.Exception
    {
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Declare two integer variables to hold the input values
        int a, b;
        
        // Read two integers from the user
        a = in.nextInt();
        b = in.nextInt();
        
        // Check if either of the integers is even
        if (a % 2 == 0 || b % 2 == 0)
            // If either number is even, print "No"
            System.out.println("No");
        else
            // If both numbers are odd, print "Yes"
            System.out.println("Yes");
    }
}
