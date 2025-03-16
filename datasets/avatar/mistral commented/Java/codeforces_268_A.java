import java.util.* ; // Importing the utility class Scanner from the Java standard library

public class Main { // Defining the main class named Main

    public static void main ( String [ ] args ) { // Defining the main method that is executed when the program runs
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream

        int n = Integer.parseInt ( sc.nextLine ( ) ) ; // Reading the first line of the input containing the number of integers n

        int result = 0 ; // Initializing the variable result to zero

        int [ ] h = new int [ n ] ; // Creating an integer array h of size n
        int [ ] g = new int [ n ] ; // Creating an integer array g of size n

        for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each index i from 0 to n-1 in the first for loop
            h [ i ] = sc.nextInt ( ) ; // Reading an integer value from the standard input stream and assigning it to the current index of array h
            g [ i ] = sc.nextInt ( ) ; // Reading an integer value from the standard input stream and assigning it to the current index of array g
        }

        for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each index i from 0 to n-1 in the second for loop
            for ( int j = 0 ; j < n ; j ++ ) { // Nested for loop iterating through each index j from 0 to n-1
                if ( h [ i ] == g [ j ] ) { // Checking if the current element of array h is equal to the current element of array g
                    result ++ ; // Incrementing the result variable if the condition is true
                }
            }
        }

        System.out.println ( result ) ; // Printing the final result to the standard output stream
    }
}
