import java.util.* ; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the main class named Main

    public static void main ( String [ ] args ) { // Defining the main method that is executed when the program runs
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object named sc to read input from the standard input
        int n = sc.nextInt ( ) ; // Reading the first integer value from the standard input and assigning it to the variable n
        int b = sc.nextInt ( ) ; // Reading the second integer value from the standard input and assigning it to the variable b
        long [ ] ans = new long [ n ] ; // Creating an array of long type named ans with a length equal to the value of the variable n
        LinkedList < Long > q = new LinkedList < > ( ) ; // Creating an empty LinkedList of long type named q

        for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop that iterates from 0 to n-1
            int t = sc.nextInt ( ) ; // Reading the current test case's first integer value and assigning it to the variable t
            int d = sc.nextInt ( ) ; // Reading the current test case's second integer value and assigning it to the variable d

            // The following while loop is used to remove the smallest element from the queue if it is less than or equal to the current test case's first integer value t
            while ( ! q.isEmpty ( ) && q.getFirst ( ) <= t ) {
                q.pollFirst ( ) ; // Removing the smallest element from the queue
            }

            // The following if statement checks whether the size of the queue is less than or equal to the value of the variable b
            if ( q.size ( ) <= b ) {
                // If the condition is true, then the answer for the current test case is the sum of the last element in the queue and the difference d
                ans [ i ] = ( q.isEmpty ( ) ? t : q.getLast ( ) ) + d ;
                // Adding the answer to the queue
                q.add ( ans [ i ] ) ;
            } else {
                // If the condition is false, then the answer for the current test case is -1
                ans [ i ] = - 1 ;
            }
        }

        // The following for loop is used to print the answers for all the test cases
        for ( int i = 0 ; i < n ; ++ i ) {
            System.out.print ( ans [ i ] + " " ) ; // Printing the answer for the current test case followed by a space
        }

        sc.close ( ) ; // Closing the scanner object
    }
}