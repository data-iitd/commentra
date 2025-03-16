
import java.io.* ;  // Importing required Java packages for input and output operations
import java.util.* ;  // Importing required Java package for string tokenization

final public class Main {
    public static void main ( String [ ] args ) throws IOException {
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;  // Creating a BufferedReader object to read input from the standard input stream
        StringBuilder sb = new StringBuilder ( ) ;                                       // Creating a StringBuilder object to store the output string

        // Reading the number of test cases
        int n = Integer.parseInt ( br.readLine ( ) ) ;

        // Reading the elements of the array
        StringTokenizer st = new StringTokenizer ( br.readLine ( ) ) ;
        Double [ ] arr = new Double [ 2 * n ] ;
        int non_int = 0 ;                                                               // Initializing variables
        double sum_before = 0 , sum = 0 ;

        // Iterating through the array elements and performing the required operations
        for ( int i = 0 ; i < 2 * n ; i ++ ) {
            double num = Double.parseDouble ( st.nextToken ( ) ) ;
            sum_before += num ;                                                          // Adding the current number to the sum_before variable
            if ( num != Math.floor ( num ) ) non_int ++ ;                               // Incrementing the non_int variable if the current number is not an integer
            sum += Math.floor ( num ) ;                                                  // Adding the floor value of the current number to the sum variable
            arr [ i ] = num ;                                                             // Assigning the current number to the corresponding index of the array
        }

        // Calculating the maximum and minimum sums
        double max_sum = Math.min ( n , non_int ) + sum ;
        double min_sum = Math.max ( 0 , non_int - n ) + sum ;

        // Calculating the answer based on the given conditions
        double ans ;
        if ( min_sum > sum_before ) ans = ( min_sum - sum_before ) ;
        else if ( max_sum < sum_before ) ans = ( sum_before - max_sum ) ;
        else {
            double x = sum_before - Math.floor ( sum_before ) ;
            ans = Math.min ( 1 - x , x ) ;
        }

        // Printing the answer
        System.out.printf ( "%.3f" , ans ) ;
    }
}

These comments should provide a clear understanding of the logical blocks in the given Java code.