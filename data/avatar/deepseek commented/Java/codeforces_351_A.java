
import java.io.* ;
import java.util.* ;

final public class Main {
    public static void main ( String [ ] args ) throws IOException {
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
        StringBuilder sb = new StringBuilder ( ) ;

        // Step 1: Reading Input
        int n = Integer.parseInt ( br.readLine ( ) ) ; // Read the integer n
        StringTokenizer st = new StringTokenizer ( br.readLine ( ) ) ; // Read the second line of input

        // Step 2: Processing Input
        Double [ ] arr = new Double [ 2 * n ] ; // Array to store the floating-point numbers
        int non_int = 0 ; // Counter for non-integer values
        double sum_before = 0 , sum = 0 ; // Variables to store the sum of all numbers and the sum of their integer parts

        for ( int i = 0 ; i < 2 * n ; i ++ ) {
            double num = Double.parseDouble ( st.nextToken ( ) ) ; // Convert each token to a double
            sum_before += num ; // Add to the sum of all numbers
            if ( num != Math.floor ( num ) ) non_int ++ ; // Increment counter if the number is not an integer
            sum += Math.floor ( num ) ; // Add the integer part of the number to the sum of integer parts
            arr [ i ] = num ; // Store the number in the array
        }

        // Step 3: Calculating Results
        double max_sum = Math.min ( n , non_int ) + sum ; // Calculate the maximum possible sum
        double min_sum = Math.max ( 0 , non_int - n ) + sum ; // Calculate the minimum possible sum
        double ans ; // Variable to store the result

        if ( min_sum > sum_before )
            ans = ( min_sum - sum_before ) ; // If the minimum sum is greater than the actual sum
        else if ( max_sum < sum_before )
            ans = ( sum_before - max_sum ) ; // If the maximum sum is less than the actual sum
        else {
            double x = sum_before - Math.floor ( sum_before ) ; // Calculate the fractional part of the sum
            ans = Math.min ( 1 - x , x ) ; // Find the smallest difference to 0 or 1
        }

        // Step 4: Output
        System.out.printf ( "%.3f" , ans ) ; // Print the result with a precision of three decimal places
    }
}