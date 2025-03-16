
import java.util.* ; // Importing the utility class Scanner

public class Main {
    final static long mod = 1000000007 ; // Defining a constant value for modulus

    public static void main ( String [ ] args ) { // Main method to start the program
        Scanner sc = new Scanner ( System.in ) ; // Creating an object of Scanner class to read input

        int n = sc.nextInt ( ) ; // Reading the first integer input representing the length of the string
        int q = sc.nextInt ( ) ; // Reading the second integer input representing the number of queries

        char [ ] c = sc.next ( ).toCharArray ( ) ; // Reading the string as a character array

        int [ ] [ ] range = new int [ q ] [ 2 ] ; // Declaring and initializing a 2D array to store the range of each query

        for ( int i = 0 ; i < q ; i ++ ) { // Loop to read the range of each query
            range [ i ] [ 0 ] = sc.nextInt ( ) ; // Reading the starting index of the range
            range [ i ] [ 1 ] = sc.nextInt ( ) ; // Reading the ending index of the range
        }

        int [ ] frag = new int [ n + 1 ] ; // Declaring and initializing an array to store the frequency of 'AC' substring
        int [ ] rui = new int [ n + 1 ] ; // Declaring and initializing an array to store the running sum of 'AC' substring frequency

        for ( int i = 2 ; i <= n ; i ++ ) { // Loop to iterate through the string from index 2 to the end
            if ( c [ i - 2 ] == 'A' && c [ i - 1 ] == 'C' ) { // Checking if the current position is an 'AC' substring
                frag [ i ] ++ ; // Incrementing the frequency of 'AC' substring at the current position
            }
            rui [ i ] = rui [ i - 1 ] + frag [ i ] ; // Updating the running sum of 'AC' substring frequency
        }

        for ( int i = 0 ; i < q ; i ++ ) { // Loop to iterate through each query
            int left = range [ i ] [ 0 ] ; // Storing the starting index of the current query range
            int right = range [ i ] [ 1 ] ; // Storing the ending index of the current query range
            System.out.println ( rui [ right ] - rui [ left ] ) ; // Printing the result of the current query
        }
    }
}

