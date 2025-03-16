
import java.util.* ; // Importing the utility class Scanner

public class Main { // Main class definition
    public static void main ( String [ ] args ) { // Main method definition
        new Main ( ).solve ( new Scanner ( System.in ) ) ; // Creating an instance of the Main class and calling the solve method with the Scanner object as an argument
    }

    private void solve ( Scanner sc ) { // solve method definition with Scanner as a parameter
        int A = sc.nextInt ( ) ; // Reading the first integer value from the standard input
        int B = sc.nextInt ( ) ; // Reading the second integer value from the standard input
        int n = sc.nextInt ( ) ; // Reading the third integer value from the standard input

        if ( A == 0 ) { // Checking if A is equal to zero
            if ( B == 0 ) { // Checking if B is also equal to zero
                System.out.println ( 1 ) ; // If both A and B are zero, print 1
            } else {
                System.out.println ( "No solution" ) ; // If A is zero but B is not, print "No solution"
                return ; // Exit the method
            }
            return ; // Exit the method
        }

        if ( B % A != 0 ) { // Checking if B is not divisible by A
            System.out.println ( "No solution" ) ; // If B is not divisible by A, print "No solution"
            return ; // Exit the method
        }

        B /= A ; // Dividing B by A
        boolean neg = B < 0 ; // Checking if B is negative

        if ( neg && n % 2 == 0 ) { // Checking if n is even and B is negative
            System.out.println ( "No solution" ) ; // If both conditions are true, print "No solution"
            return ; // Exit the method
        }

        if ( neg ) B = - B ; // If B is negative, make it positive

        for ( int x = 0 ; x <= B ; x ++ ) { // Iterating through all possible values of x from 0 to B
            if ( Math.pow ( x , n ) == B ) { // Checking if x raised to the power of n is equal to B
                System.out.println ( neg ? - x : x ) ; // Printing the value of x with its sign
                return ; // Exit the method
            }
        }

        System.out.println ( "No solution" ) ; // If no solution is found, print "No solution"
    }
}