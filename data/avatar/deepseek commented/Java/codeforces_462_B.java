import java.io.* ; // Importing the necessary I/O libraries for input/output operations
import java.util.* ; // Importing the utility libraries for utility classes

public class Main { // Main class definition
    public static void main ( String [ ] args ) throws Exception { // Main method definition
        BufferedReader f = new BufferedReader ( new InputStreamReader ( System.in ) ) ; // Setting up BufferedReader to read from standard input
        PrintWriter out = new PrintWriter ( new BufferedWriter ( new OutputStreamWriter ( System.out ) ) ) ; // Setting up PrintWriter to write to standard output
        StringTokenizer st = new StringTokenizer ( f.readLine ( ) ) ; // Reading the first line of input and tokenizing it
        int n = Integer.parseInt ( st.nextToken ( ) ) ; // Parsing the first token as an integer, representing the length of the string
        int k = Integer.parseInt ( st.nextToken ( ) ) ; // Parsing the second token as an integer, representing a parameter for some operation
        c462b [ ] cards = new c462b [ 26 ] ; // Initializing an array of c462b objects with 26 elements
        for ( int i = 0 ; i < 26 ; i ++ ) { // Looping through the array to initialize each element
            cards [ i ] = new c462b ( ) ; // Initializing each c462b object
        }
        String s = f.readLine ( ) ; // Reading the string from the input
        for ( int t = 0 ; t < n ; t ++ ) { // Looping through the string to count occurrences
            cards [ s.charAt ( t ) - 'A' ].left ++ ; // Incrementing the left property of the corresponding c462b object
        }
        long ans = 0 ; // Initializing the answer variable to zero
        for ( int i = 0 ; i < k ; i ++ ) { // Looping k times to calculate the answer
            Arrays.sort ( cards ) ; // Sorting the cards array
            long change = Math.min ( cards [ 25 ].left , k - i ) ; // Calculating the minimum between the largest left value and the remaining k - i
            ans += change * change ; // Adding the square of the calculated value to ans
            cards [ 25 ].left -= change ; // Decrementing the left property of the largest element
            i += change - 1 ; // Adjusting the loop counter
        }
        out.println ( ans ) ; // Printing the result
        out.close ( ) ; // Closing the PrintWriter
    }
}

class c462b implements Comparable { // Class definition for c462b
    int left = 0 ; // Property to store the count
    @ Override
    public int compareTo ( Object o ) { // Method to compare based on the left property
        return left - ( ( c462b ) o ).left ; // Returning the difference in left properties
    }
}
