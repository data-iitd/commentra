import java.util.* ; // Importing the Java Util library for Scanner class

public class Main { // Defining the main class
    public static void main ( String [ ] args ) { // Starting the main method
        long mod = ( long ) 1e9 + 7 ; // Assigning the value of 1e9 + 7 to a long variable named mod
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input

        int n = sc.nextInt ( ) ; // Reading the first integer input and assigning it to the variable n
        int k = sc.nextInt ( ) ; // Reading the second integer input and assigning it to the variable k
        sc.close ( ) ; // Closing the Scanner object after reading all inputs

        ArrayList < Integer > len = new ArrayList < > ( ) ; // Creating an empty ArrayList named len to store the lengths of subsequences
        int l = 1 ; // Initializing the variable l to 1

        while ( l <= n ) { // Starting a while loop that runs as long as l is less than or equal to n
            int r = n / ( n / l ) ; // Calculating the right end of the current subsequence
            len.add ( r - l + 1 ) ; // Adding the length of the current subsequence to the ArrayList len
            l = r + 1 ; // Incrementing the variable l to consider the next subsequence
        }

        int q = len.size ( ) ; // Assigning the size of the ArrayList len to the variable q
        long [ ] dp = new long [ k * ( q + 1 ) ] ; // Creating an array named dp of size k * (q + 1) to store the dynamic programming results

        for ( int j = 1 ; j <= q ; j ++ ) { // Starting a for loop that runs from 1 to q
            dp [ j ] = len.get ( j - 1 ) + dp [ j - 1 ] ; // Calculating the dp value for the current subsequence length using the previous dp value and the length of the current subsequence
        }

        for ( int i = 1 ; i < k ; i ++ ) { // Starting a nested for loop that runs from 1 to k - 1 for the number of overlapping subsequences
            for ( int j = 1 ; j <= q ; j ++ ) { // Starting an inner for loop that runs from 1 to q for the length of the current subsequence
                dp [ i * ( q + 1 ) + j ] = dp [ i * ( q + 1 ) + j - 1 ] + dp [ ( i - 1 ) * ( q + 1 ) + q - j + 1 ] * len.get ( j - 1 ) ; // Calculating the dp value for the current combination of subsequence length and number of overlapping subsequences using the dp values of the previous combinations and the length of the current subsequence
                dp [ i * ( q + 1 ) + j ] %= mod ; // Taking the modulo of the dp value to ensure it doesn't exceed the value of mod
            }
        }

        System.out.println ( dp [ k * ( q + 1 ) - 1 ] ) ; // Printing the final result, which is the dp value for the combination of subsequence length and number of overlapping subsequences that matches the given input
    }
}
