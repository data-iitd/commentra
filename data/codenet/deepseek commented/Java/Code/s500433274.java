import java.math.*; // Importing the Math library for handling large numbers
import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {

    public static void main(String[] args) {
        BigInteger a, b, c; // Declaring BigInteger variables to handle large integers
        Scanner cin = new Scanner(System.in); // Creating a Scanner object to read input
        
        // Loop to read input until there is no more input
        while (cin.hasNext()) {
            a = cin.nextBigInteger(); // Reading the first large integer
            b = cin.nextBigInteger(); // Reading the second large integer
            
            c = a.max(b); // Finding the maximum of the two large integers
            
            // Comparing the values of a, b, and c to determine the relationship
            if (a.equals(c) && !b.equals(c)) 
                System.out.println("GREATER"); // Printing if a is greater than b
            else if (b.equals(c) && !a.equals(c))
                System.out.println("LESS"); // Printing if b is greater than a
            else 
                System.out.println("EQUAL"); // Printing if a and b are equal
        }
        
        cin.close(); // Closing the Scanner object to free up resources
    }
}
