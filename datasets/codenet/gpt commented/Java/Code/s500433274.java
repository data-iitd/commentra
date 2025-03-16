import java.math.*; // Importing BigInteger class for handling large integers
import java.util.Scanner; // Importing Scanner class for user input

public class Main {

    public static void main(String[] args) {
        // Declare BigInteger variables to hold the input values
        BigInteger a, b, c;
        
        // Create a Scanner object to read input from the console
        Scanner cin = new Scanner(System.in);
        
        // Loop to continuously read input until there are no more inputs
        while(cin.hasNext()) {
            // Read two BigInteger values from the input
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            
            // Determine the maximum of the two BigInteger values
            c = a.max(b);
            
            // Compare the values and print the appropriate message
            if(a.equals(c) && !b.equals(c)) 
                System.out.println("GREATER"); // 'a' is greater than 'b'
            else if(b.equals(c) && !a.equals(c))
                System.out.println("LESS"); // 'b' is greater than 'a'
            else 
                System.out.println("EQUAL"); // 'a' and 'b' are equal
        }
        
        // Close the Scanner to free up resources
        cin.close();
    }
}
