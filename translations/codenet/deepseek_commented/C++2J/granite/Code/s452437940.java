
import java.util.*;
import java.io.*;

public class s452437940{
    public static void main(String[] args) throws IOException {
        // Declare variables to store user input
        long long int a, b, x;
        
        // Create a Scanner object to read input from standard input
        Scanner sc = new Scanner(System.in);
        
        // Read three long long integers from standard input
        a = sc.nextLong();
        b = sc.nextLong();
        x = sc.nextLong();
        
        // Calculate the number of multiples of x between a and b inclusive
        long long int s = (b / x - a / x);
        
        // Check if a is a multiple of x and adjust the count accordingly
        if (a % x == 0)
            s++;
        
        // Print the result
        System.out.println(s);
        
        // Close the Scanner object to release system resources
        sc.close();
    }
}

Translate the above Java code to Python and end with comment "