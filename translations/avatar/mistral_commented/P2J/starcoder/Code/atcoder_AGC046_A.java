
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // Create a Scanner object
        Scanner input = new Scanner( System.in );

        // Ask the user for an integer input and assign it to the variable x
        int x = input.nextInt();

        // Calculate the greatest common divisor (gcd) of 360 and the user input x
        int gcd_value = gcd( 360, x );

        // Print the result of the division of 360 by the gcd
        System.out.println( 360 / gcd_value );

    }

    // Function to calculate the greatest common divisor (gcd) of two integers
    public static int gcd( int a, int b ) {

        // If b is 0, then the gcd is a
        if ( b == 0 ) {
            return a;
        }

        // If a is 0, then the gcd is b
        if ( a == 0 ) {
            return b;
        }

        // If a is greater than b, then gcd(a,b) = gcd(a-b,b)
        if ( a > b ) {
            return gcd( a - b, b );
        }

        // If a is less than b, then gcd(a,b) = gcd(a,b-a)
        return gcd( a, b - a );

    }

}

