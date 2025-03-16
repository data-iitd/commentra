

import java.util.Scanner;

public class s344381425{
    public static void main(String[] args) {
        // Declare three integer variables to store input values
        int a, b, c;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from standard input and assign them to a, b, and c
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        
        // Check if a is less than b and b is less than c
        if (a < b && b < c) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // Otherwise, print "No"
            System.out.println("No");
        }
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
