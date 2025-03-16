import java.util.* ; // Importing the Java Util library for Scanner class

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String args [ ] ) {
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream
        int n = sc.nextInt ( ) ; // Reading the number of rows and columns of the 2D char array from the standard input stream

        // Allocating memory for the 2D char array and the String array
        char arr [ ] [ ] = new char [ n ] [ n ] ;
        String str [ ] = new String [ n ] ;

        // Reading the strings from the standard input stream and storing them in the String array
        for ( int i = 0 ; i < n ; i ++ ) {
            str [ i ] = sc.next ( ) ; // Reading a single line of input as a String
        }

        // Converting each String to a 2D char array and storing it in the corresponding position of the 2D char array
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < n ; j ++ ) {
                arr [ i ] [ j ] = str [ i ].charAt ( j ) ; // Assigning the character at the (i, j) position of the current String to the corresponding position of the 2D char array
            }
        }

        // Initializing two variables 'a' and 'b' with the characters at the first position of the first row of the 2D char array
        char a = arr [ 0 ] [ 0 ] ;
        char b = arr [ 0 ] [ 1 ] ;

        // Checking if the first characters of the first row are equal or not
        if ( a == b ) {
            System.out.println ( "NO" ) ; // Printing "NO" if they are equal
        } else {
            boolean res = true ; // Initializing a boolean variable 'res' to true

            // Checking if there exists any pair of distinct characters in the 2D char array such that they form a diagonal line
            for ( int i = 0 ; i < n ; i ++ ) {
                for ( int j = 0 ; j < n ; j ++ ) {
                    // Checking if the current pair (i, j) and (j, i) form a diagonal line
                    if ( ( i == j || i + j == n - 1 ) ) {
                        // Checking if the characters at the current position of the 2D char array are equal to 'a' or 'b'
                        if ( arr [ i ] [ j ] != a ) {
                            res = false ; // Setting 'res' to false if any pair of distinct characters is found on a diagonal line
                            break ; // Exiting the inner loop as soon as a pair of distinct characters is found
                        }
                    } else {
                        // Checking if the characters at the current position of the 2D char array are equal to 'b'
                        if ( arr [ i ] [ j ] != b ) {
                            res = false ; // Setting 'res' to false if any character other than 'a' or 'b' is found at a position not on a diagonal line
                            break ; // Exiting the inner loop as soon as a character other than 'a' or 'b' is found
                        }
                    }
                }
            }

            // Printing "YES" if all the characters in the 2D char array form either a single diagonal line of 'a's and 'b's or two separate diagonal lines of 'a's and 'b's
            if ( res ) {
                System.out.println ( "YES" ) ;
            } else {
                System.out.println ( "NO" ) ; // Printing "NO" if any character other than 'a' or 'b' is found at a position not on a diagonal line
            }
        }
    }
}
