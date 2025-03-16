
import java.io.* ;  // Importing required Java classes for input and output
import java.util.* ;  // Importing required Java classes for string tokenization

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) throws Exception {
        BufferedReader f = new BufferedReader ( new InputStreamReader ( System.in ) ) ;  // Reading input from standard input
        PrintWriter out = new PrintWriter ( new BufferedWriter ( new OutputStreamWriter ( System.out ) ) ) ;  // Writing output to standard output
        StringTokenizer st = new StringTokenizer ( f.readLine ( ) ) ;  // Tokenizing the first line of input

        int n = Integer.parseInt ( st.nextToken ( ) ) ;  // Reading the number of cards
        int k = Integer.parseInt ( st.nextToken ( ) ) ;  // Reading the number of queries

        c462b [ ] cards = new c462b [ 26 ] ;  // Creating an array of size 26 to store the cards
        for ( int i = 0 ; i < 26 ; i ++ ) {  // Initializing the cards array with default values
            cards [ i ] = new c462b ( ) ;
        }

        String s = f.readLine ( ) ;  // Reading the sequence of cards
        for ( int t = 0 ; t < n ; t ++ ) {  // Iterating through each character in the sequence
            cards [ s.charAt ( t ) - 'A' ].left ++ ;  // Incrementing the left counter of the corresponding card
        }

        long ans = 0 ;  // Initializing the answer variable to zero
        for ( int i = 0 ; i < k ; i ++ ) {  // Iterating through each query
            Arrays.sort ( cards ) ;  // Sorting the cards array in descending order of their left counters
            long change = Math.min ( cards [ 25 ].left , k - i ) ;  // Calculating the number of cards to be moved
            ans += change * change ;  // Adding the square of the number of cards moved to the answer
            cards [ 25 ].left -= change ;  // Decreasing the left counter of the highest card by the number of cards moved
            i += change - 1 ;  // Skipping the next i-1 cards as they will have the same left counter
        }

        out.println ( ans ) ;  // Writing the answer to the standard output
        out.close ( ) ;  // Closing the output stream
    }

    static class c462b implements Comparable <c462b> {  // Defining an inner class to represent a card
        int left = 0 ;  // The left counter of the card

        @Override
        public int compareTo ( c462b o ) {  // Overriding the compareTo method for custom comparison
            return left - o.left ;
        }
    }
}