
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the Main class
    int INF = Integer.MAX_VALUE ; // Initializing INF with the maximum value of an integer

    public static void main ( String [ ] args ) { // Main method to start the program
        new Main ( ).solve ( ) ; // Creating an instance of the Main class and calling the solve method
    }

    void solve ( ) { // Method to solve the problem
        Scanner sc = new Scanner ( System.in ) ; // Creating a Scanner object to read input from the console

        int N = sc.nextInt ( ) ; // Reading the number of elements in the array from the console
        long X = sc.nextLong ( ) ; // Reading the value of X from the console
        long [ ] x = new long [ N ] ; // Creating an array of size N to store the elements
        long [ ] xsum = new long [ N + 1 ] ; // Creating an array of size N+1 to store the sum of elements up to that index

        for ( int i = 0 ; i < N ; i ++ ) { // Loop to read and store the elements in the array
            x [ i ] = sc.nextInt ( ) ;
            xsum [ i + 1 ] = xsum [ i ] + x [ i ] ; // Updating the sum of elements up to the current index
        }

        long ans = X * N + 5 * xsum [ N ] ; // Initializing the answer with the first calculation

        for ( int i = 1 ; i < N ; i ++ ) { // Loop to find the minimum cost
            long cost = X * i + 5 * ( xsum [ N ] - xsum [ N - i ] ) ; // Calculating the cost for the current i
            for ( int j = 5 , k = N - i ; k >= 0 ; j += 2 , k -= i ) { // Nested loop to check the cost for different j and k
                if ( cost > ans ) { // If the cost is greater than the current answer, break the loop
                    break ;
                }
                cost += j * ( xsum [ k ] - xsum [ Math.max ( k - i , 0 ) ] ) ; // Updating the cost with the sum of elements between k and k-i
            }
            ans = Math.min ( ans , cost ) ; // Updating the answer with the minimum cost found so far
        }

        System.out.println ( ans + N * X ) ; // Printing the final answer
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further clarification.