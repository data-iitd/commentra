import java.util.* ;  // Importing necessary utility classes from the Java standard library
import java.io.* ;    // Importing necessary I/O classes from the Java standard library
import java.math.* ;  // Importing necessary math classes from the Java standard library

public class Main {
    // Declaring the main method, which is the entry point of the Java application

    public static void main ( String hi [ ] ) throws Exception {
        // Declaring the main method with a String array argument and an Exception as a thrown exception

        BufferedReader infile = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
        // Creating a BufferedReader object to read input from the standard input stream

        char [ ] arr = infile.readLine ( ).toCharArray ( ) ;
        // Reading the first line of input as a character array and storing it in the 'arr' variable

        int N = arr.length ;
        // Declaring and initializing the length of the character array 'arr' in the variable 'N'

        HashSet < String > set = new HashSet < String > ( ) ;
        // Creating an empty HashSet object to store unique strings

        int K = Integer.parseInt ( infile.readLine ( ) ) ;
        // Reading the second line of input as an integer and storing it in the variable 'K'

        int res = 0 ;
        // Declaring and initializing an integer variable 'res' to store the result

        for ( int k = 0 ; k < K ; k ++ ) {
            // Starting a for loop that iterates 'K' times

            String input = infile.readLine ( ) ;
            // Reading a string as input and storing it in the 'input' variable

            int a = 0 ;
            int b = 0 ;
            // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the character array 'arr'

            for ( int i = 0 ; i < N ; i ++ ) {
                // Starting a nested for loop that iterates through each index of the character array 'arr'

                if ( arr [ i ] == input.charAt ( 0 ) )
                    a ++ ;  // Incrementing the 'a' variable if the character at the current index matches the first character of the input string

                else if ( arr [ i ] == input.charAt ( 1 ) )
                    b ++ ;  // Incrementing the 'b' variable if the character at the current index matches the second character of the input string

                else {
                    res += Math.min ( a , b ) ;  // Adding the minimum of 'a' and 'b' to the 'res' variable if the current character is different from both characters in the input string
                    a = b = 0 ;  // Resetting the 'a' and 'b' variables to zero
                }
            }

            res += Math.min ( a , b ) ;  // Adding the minimum of 'a' and 'b' to the 'res' variable after the end of the outer for loop
        }

        System.out.println ( res ) ;
        // Printing the final result to the standard output stream
    }
}
