
import java.util.HashMap ;  // Importing HashMap class for hash table
import java.util.HashSet ; // Importing HashSet class for set data structure
import java.util.Scanner ;  // Importing Scanner class for reading input

public class Main {

    public static void main ( String [ ] args ) {
        // Initializing Scanner object for reading input
        Scanner sc = new Scanner ( System.in ) ;

        // Reading the first two integers from the input
        int n = sc.nextInt ( ) ;
        int m = sc.nextInt ( ) ;

        // Creating an array of strings to store input strings
        String arrs [ ] = new String [ n ] ;

        // Iterating through the array and storing each string
        for ( int i = 0 ; i < n ; i ++ ) {
            arrs [ i ] = sc.next ( ) ; // Reading a string from the input
        }

        // Initializing an integer array to store the length of substrings between "G" and "S"
        int [ ] length = new int [ n ] ;
        int index = 0 ; // Index for storing the current index in the length array
        int returnDex = 0 ; // Index for storing the index of the string with "G" before "S"

        // Iterating through each string in the array and finding the length of substrings between "G" and "S"
        for ( String tmp : arrs ) {
            int dexG = tmp.indexOf ( "G" ) ; // Finding the index of "G" in the current string
            int dexS = tmp.indexOf ( "S" ) ; // Finding the index of "S" in the current string

            // Checking if "G" comes before "S" in the current string
            if ( dexG > dexS ) {
                returnDex = i ; // Storing the index of the string with "G" before "S"
                break ; // Exiting the loop as we have found the required string
            }

            // Storing the length of the substring between "G" and "S" in the length array
            length [ index ++ ] = dexS - dexG ;
        }

        // Creating a HashSet to store the unique lengths of substrings
        HashSet set = new HashSet < Integer > ( ) ;

        // Iterating through the length array and adding each unique length to the HashSet
        for ( int len : length ) {
            set.add ( len ) ;
        }

        // Checking if there is a string with "G" before "S"
        if ( returnDex == - 1 ) {
            // Printing the result if there is no such string
            System.out.println ( returnDex ) ;
        } else {
            // Printing the size of the HashSet if there is a string with "G" before "S"
            System.out.println ( set.size ( ) ) ;
        }
    }
}

These comments should provide a clear understanding of the logic behind each block of code.