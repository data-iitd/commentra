import java.util.Scanner ;  // Importing the Scanner class for user input

public class Main {
    public static void main ( String [ ] args ) {  // Main method to start the program
        Scanner s = new Scanner ( System.in ) ;  // Creating a new Scanner object to read user input
        
        long x = s.nextInt ( ) ;  // Reading the first integer value from user input
        long y = s.nextInt ( ) ;  // Reading the second integer value from user input
        long a = s.nextInt ( ) ;  // Reading the third integer value from user input
        long b = s.nextInt ( ) ;  // Reading the fourth integer value from user input
        
        long j = 2 , i , x1 = 0 , y1 = 0 , c = 0 ;  // Initializing variables
        boolean ans = true ;  // Initializing a boolean variable to keep track of the result

        c = Math.max ( x , y ) ;  // Finding the maximum value between x and y

        if ( c > b ) {  // Checking if the maximum value is greater than b
            System.out.println ( "0" ) ;  // If true, printing 0 and setting ans to false
            ans = false ;
        }

        while ( c % Math.min ( x , y ) != 0 && ans ) {  // Loop to find the greatest common divisor (GCD)
            if ( x > y ) {  // If x is greater than y
                c = x * j ;  // Multiplying x by j and updating c
                j ++ ;  // Incrementing j
            } else {
                c = y * j ;  // Multiplying y by j and updating c
                j ++ ;  // Incrementing j
            }

            if ( c > b ) {  // Checking if the current value of c is greater than b
                System.out.println ( "0" ) ;  // If true, printing 0 and setting ans to false
                ans = false ;
                break ;  // Exiting the loop
            }
        }

        if ( ans ) {  // If the GCD has been found
            long count = 0 ;  // Initializing a counter variable
            i = a ;  // Starting the loop from a

            for ( i = a ; i <= b ; i ++ ) {  // Loop to find the number of times c divides i
                if ( i % c == 0 ) break ;  // If i is divisible by c, breaking the loop
            }

            if ( i != b + 1 ) {  // Checking if the last number in the range is divisible by c
                System.out.println ( ( ( b - i ) / c ) + 1 ) ;  // Printing the result
            } else {
                System.out.println ( "0" ) ;  // If the last number is not divisible by c, printing 0
            }
        }
    }
}
