
import java.io.* ; // For handling input and output streams
import java.util.* ; // For using Scanner class

public class Main {
    // Constructor for creating an instance of Main class and setting output stream to System.out
    Main ( ) {
        super ( System.out , true ) ;
    }

    Scanner sc = new Scanner ( System.in ) ; // Creating a Scanner object for reading input

    public static void main ( String [ ] $ ) {
        Main o = new Main ( ) ; // Creating an instance of Main class
        o.main ( ) ; // Calling the main method of Main class
        o.flush ( ) ; // Flushing the output buffer
    }

    // Method to compare two character arrays aa and bb starting from their respective indices i and j
    int compare ( char [ ] aa , int i , char [ ] bb , int j , int m ) {
        // Iterating through the character arrays until the length m is reached
        while ( m -- > 0 ) {
            char a = Character.toUpperCase ( aa [ i ] ) ; // Converting the characters to uppercase
            char b = Character.toUpperCase ( bb [ j ] ) ;

            if ( a != b ) // If characters are not equal, return the difference of their ASCII values
                return a - b ;

            i ++ ; // Incrementing the index i in aa
            j ++ ; // Incrementing the index j in bb
        }

        // If all characters match, return 0
        return 0 ;
    }

    // Main method to read input and process it
    void main ( ) {
        int n = sc.nextInt ( ) ; // Reading the number of character arrays to be processed
        char [ ] [ ] ss = new char [ n ] [ ] ; // Creating a 2D array to store the character arrays

        // Reading the character arrays and storing them in the 2D array
        for ( int i = 0 ; i < n ; i ++ ) {
            ss [ i ] = sc.next ( ).toCharArray ( ) ;
        }

        char [ ] cc = sc.next ( ).toCharArray ( ) ; // Reading the character array to be compared with the input character arrays
        int m = cc.length ; // Finding the length of the character array cc

        char c = sc.next ( ).charAt ( 0 ) ; // Reading the character to be matched with the character array cc
        char c_ = Character.toUpperCase ( c ) ; // Converting the character to uppercase
        char a = c == 'a' ? 'b' : 'a' ; // Determining the character a based on the character c
        char a_ = Character.toUpperCase ( a ) ; // Converting the character a to uppercase

        boolean [ ] lucky = new boolean [ m ] ; // Creating a boolean array to keep track of the matching indices in cc

        // Iterating through each character in cc and comparing it with all characters in each character array in ss
        for ( int j = 0 ; j < m ; j ++ ) {
            for ( int i = 0 ; i < n ; i ++ ) {
                int l = ss [ i ].length ; // Finding the length of the character array in ss at the current index i

                if ( m - j >= l && compare ( cc , j , ss [ i ] , 0 , l ) == 0 ) { // If the length of cc minus the current index j is greater than or equal to the length of the character array in ss at the current index i, and if the comparison of the substrings starting from the current indices in cc and ss returns 0, then set the boolean value at the current index j in lucky to true
                    for ( int h = 0 ; h < l ; h ++ ) { // Iterating through each character in the character array in ss at the current index i
                        lucky [ j + h ] = true ; // Setting the boolean value at the current index j+h in lucky to true
                    }
                }
            }
        }

        // Iterating through each character in cc and updating it based on the boolean values in lucky
        for ( int j = 0 ; j < m ; j ++ ) {
            if ( lucky [ j ] ) { // If the boolean value at the current index j in lucky is true
                if ( Character.toLowerCase ( cc [ j ] ) == c ) { // If the character at the current index j in cc is equal to the character c in lowercase
                    cc [ j ] = Character.isUpperCase ( cc [ j ] ) ? a_ : a ; // Update the character at the current index j in cc based on the character a
                } else {
                    cc [ j ] = Character.isUpperCase ( cc [ j ] ) ? c_ : c ; // Update the character at the current index j in cc based on the character c
                }
            }
        }

        // Printing the updated character array cc
        println ( cc ) ;
    }
}