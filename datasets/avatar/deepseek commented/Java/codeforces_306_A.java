
import java.util.Arrays ; 
import java.util.Scanner ; 

public class Main { 
    public static Scanner input = new Scanner ( System.in ) ; 

    public static void main ( String [ ] args ) { 
        // Read the values of n and m from the user
        int n = input.nextInt ( ) ; 
        int m = input.nextInt ( ) ; 

        // Initialize an array of size m
        int a [ ] = new int [ m ] ; 

        // Check if n is divisible by m
        if ( n % m == 0 ) { 
            // Fill the array with equal parts if n is divisible by m
            for ( int i = 0 ; i < a.length ; i ++ ) { 
                a [ i ] = n / m ; 
            } 
        } else { 
            // Calculate the base part size
            int sub = n / m ; 

            // Fill the array with the base part size
            for ( int i = 0 ; i < a.length ; i ++ ) { 
                a [ i ] = sub ; 
            } 

            // Distribute the remainder
            int test = n - ( sub * m ) ; 
            int count = 0 ; 
            for ( int i = 0 ; i < test ; i ++ ) { 
                a [ count ] = a [ count ] + 1 ; 
                count ++ ; 
                if ( count >= a.length ) count = 0 ; 
            } 
        } 

        // Print the array elements in reverse order
        for ( int i = ( a.length - 1 ) ; i >= 0 ; i -- ) { 
            System.out.print ( a [ i ] + " " ) ; 
        } 
    } 
}

