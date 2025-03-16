
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the Main class

    public static void main ( String [ ] args ) { // Starting point of the program
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input

        int n = sc.nextInt ( ) ; // Reading the first integer input 'n'
        int levels = sc.nextInt ( ) ; // Reading the second integer input 'levels'

        int sum = 0 ; // Initializing sum variable to 0
        int sum2 = 0 ; // Initializing sum2 variable to 0
        int sum3 = 0 ; // Initializing sum3 variable to 0
        int [ ] arr = new int [ levels ] ; // Creating an integer array 'arr' of size 'levels'
        int count = 0 ; // Initializing count variable to 0

        for ( int i = 0 ; i < levels ; i ++ ) { // Loop to read 'levels' number of integers and store them in 'arr'
            arr [ i ] = sc.nextInt ( ) ;
        }

        int level2 = sc.nextInt ( ) ; // Reading the third integer input 'level2'
        int level3 = levels + level2 ; // Calculating the size of 'arr2'
        int [ ] arr2 = new int [ level3 ] ; // Creating an integer array 'arr2' of size 'level3'

        for ( int i = 0 ; i < arr.length ; i ++ ) { // Loop to copy elements of 'arr' to 'arr2'
            arr2 [ i ] = arr [ i ] ;
        }

        for ( int i = arr.length ; i < level3 ; i ++ ) { // Loop to read 'level2' number of integers and store them in 'arr2'
            arr2 [ i ] = sc.nextInt ( ) ;
        }

        int [ ] arr3 = new int [ n ] ; // Creating an integer array 'arr3' of size 'n'
        int j = 0 ; // Initializing 'j' variable to 0

        for ( int i = 0 ; i < n ; i ++ ) { // Loop to initialize 'arr3' with numbers from 1 to 'n'
            arr3 [ i ] = ++ j ;
        }

        for ( int i = 0 ; i < n ; i ++ ) { // Outer loop to compare each element of 'arr3' with 'arr2'
            for ( int x = 0 ; x < arr2.length ; x ++ ) { // Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
                if ( arr3 [ i ] == arr2 [ x ] ) { // If a match is found
                    count ++ ; // Increment the count variable
                    break ; // Exit the inner loop
                }
            }
        }

        if ( count == n ) { // If all elements of 'arr3' are present in 'arr2'
            System.out.println ( "I become the guy." ) ; // Print the message
        } else { // Otherwise
            System.out.println ( "Oh, my keyboard!" ) ; // Print the error message
        }

        sc.close ( ) ; // Closing the Scanner object
    }
}