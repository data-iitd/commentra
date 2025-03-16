
import java.util.* ; 
import java.lang.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner scan = new Scanner ( System.in ) ; 
        long N = scan.nextLong ( ) ; 
        long A = scan.nextLong ( ) ; 
        long B = scan.nextLong ( ) ; 
        long k = 0 ; 

        // Check if the values of N, A, and B are within the specified ranges
        if ( 1 <= N && N <= Math.pow ( 10 , 18 ) && 0 <= A && 0 <= B && 0 < A + B && A + B <= Math.pow ( 10 , 18 ) ) { 

            // Calculate the number of complete cycles (k) of A and B that fit into N
            if ( A + B <= N ) { 
                k = N / ( A + B ) ; 
                if ( N - k * ( A + B ) > A ) { 
                    System.out.println ( A * k + ( N - k * ( A + B ) ) - ( N - ( k * ( A + B ) + A ) ) ) ; 
                } else { 
                    System.out.println ( A * k + ( N - k * ( A + B ) ) ) ; 
                } 
            } 
            // If the sum of A and B is greater than N and A is less than or equal to N
            else if ( A + B > N && A <= N ) { 
                System.out.println ( A ) ; 
            } 
            // If none of the above conditions are met, print N
            else { 
                System.out.println ( N ) ; 
            } 
        } 
    } 
}

