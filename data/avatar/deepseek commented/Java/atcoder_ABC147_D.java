import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        long startTime = System.currentTimeMillis ( ) ; 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; // Read the number of elements
        long div = ( long ) Math.pow ( 10 , 9 ) + 7 ; // Define the modulo constant
        long [ ] A = new long [ n ] ; // Initialize array A to store n long integers
        long ans = 0 ; // Initialize the answer variable

        // Read n long integers from the user and store them in array A
        for ( int i = 0 ; i < n ; i ++ ) { 
            A [ i ] = sc.nextLong ( ) ; 
        } 

        // Iterate over each bit position from 0 to 59
        for ( int i = 0 ; i < 60 ; i ++ ) { 
            long a = 0 ; // Initialize the contribution for the current bit position
            long count1 = 0 ; // Count of elements with the current bit set to 1

            // Count the number of elements with the current bit set to 1
            for ( int j = 0 ; j < n ; j ++ ) { 
                if ( ( A [ j ] >> i & 1 ) == 1 ) count1 ++ ; 
            } 

            // Calculate the contribution of the current bit position
            a = a + count1 * ( n - count1 ) ; 

            // Shift the contribution left by 1 bit for each lower bit position and take modulo
            for ( int j = 0 ; j < i ; j ++ ) { 
                a = ( a << 1 ) % div ; 
            } 

            // Add the contribution to the answer and take modulo
            ans += a ; 
            ans %= div ; 
        } 

        // Print the result
        System.out.println ( ans ) ; 
        long endTime = System.currentTimeMillis ( ) ; 
    } 
}
