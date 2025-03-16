
import java.util.ArrayList ;  // Importing the ArrayList and Scanner classes
import java.util.Scanner ;

public class Main {
    static int [ ] a = null ;   // Declaring and initializing four integer arrays a, b, c, and d to null
    static int [ ] b = null ;
    static int [ ] c = null ;
    static int [ ] d = null ;
    static int n = 0 ;          // Declaring and initializing two integer variables n and m to zero
    static int m = 0 ;
    static int q = 0 ;           // Declaring and initializing an integer variable q to zero
    static long ans = - 100L ;   // Declaring and initializing a long variable ans to a very large negative number

    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;  // Creating a new Scanner object named sc to read input from the standard input

        n = sc.nextInt ( ) ;                     // Reading the first integer n from the standard input
        m = sc.nextInt ( ) ;                     // Reading the second integer m from the standard input
        q = sc.nextInt ( ) ;                     // Reading the third integer q from the standard input

        a = new int [ q ] ;                      // Allocating memory for the array a of size q and initializing it to null
        b = new int [ q ] ;                      // Allocating memory for the array b of size q and initializing it to null
        c = new int [ q ] ;                      // Allocating memory for the array c of size q and initializing it to null
        d = new int [ q ] ;                      // Allocating memory for the array d of size q and initializing it to null

        for ( int i = 0 ; i < q ; ++ i ) {        // A for loop that reads q integers from the standard input and stores them in arrays a, b, c, and d
            a [ i ] = sc.nextInt ( ) - 1 ;        // Reading the integer a[i] from the standard input and storing it in the array a after subtracting 1 from it
            b [ i ] = sc.nextInt ( ) - 1 ;        // Reading the integer b[i] from the standard input and storing it in the array b after subtracting 1 from it
            c [ i ] = sc.nextInt ( ) ;           // Reading the integer c[i] from the standard input and storing it in the array c
            d [ i ] = sc.nextInt ( ) ;           // Reading the integer d[i] from the standard input and storing it in the array d
        }

        dfs ( new ArrayList < Integer > ( ) ) ;   // Calling the recursive function dfs with an empty ArrayList as an argument

        System.out.println ( ans ) ;             // Printing the value of the long variable ans to the standard output
    }

    public static void dfs ( ArrayList < Integer > list ) {   // A recursive function named dfs that takes an ArrayList named list as an argument
        if ( list.size ( ) == n ) {                       // A conditional statement that checks if the size of the ArrayList list is equal to the integer n
            long score = 0L ;                             // Declaring and initializing a long variable score to zero

            for ( int i = 0 ; i < q ; ++ i ) {             // A for loop that calculates the score based on the condition that (list.get(b[i]) - list.get(a[i]) == c[i])
                score += ( list.get ( b [ i ] ) - list.get ( a [ i ] ) == c [ i ] ) ? d [ i ] : 0L ;
            }

            ans = Math.max ( ans , score ) ;             // Updating the value of the long variable ans with the maximum value of ans and the score calculated in the for loop
            return ;                                     // Returning from the function after updating the value of ans
        }

        if ( ! list.isEmpty ( ) ) {                      // A conditional statement that checks if the ArrayList list is not empty
            for ( int num = list.get ( list.size ( ) - 1 ) ; num <= m ; ++ num ) { // A for loop that adds the integer num to the ArrayList list and recursively calls the function dfs
                list.add ( num ) ;
                dfs ( list ) ;
                list.remove ( list.size ( ) - 1 ) ;
            }
        } else {                                         // If the ArrayList list is empty
            for ( int num = 1 ; num <= m ; ++ num ) {      // A for loop that adds the integer num to the ArrayList list and recursively calls the function dfs
                list.add ( num ) ;
                dfs ( list ) ;
                list.remove ( list.size ( ) - 1 ) ;
            }
        }
    }
}

