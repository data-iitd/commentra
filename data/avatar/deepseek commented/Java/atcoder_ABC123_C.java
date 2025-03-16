
import java.util.ArrayDeque ; 
import java.util.Queue ; 
import java.util.Random ; 
import java.util.Scanner ; 

public class Main { 
    private static Scanner sc = new Scanner ( System.in ) ; 

    public static void main ( String [ ] args ) { 
        // Read the value of N
        long N = sc.nextLong ( ) ; 

        // Initialize min to 0 and find the minimum of the first five inputs
        long min = 0 ; 
        for ( int i = 0 ; i < 5 ; i ++ ) { 
            if ( i == 0 ) 
                min = sc.nextLong ( ) ; 
            else 
                min = Math.min ( min , sc.nextLong ( ) ) ; 
        } 

        // Calculate the result and print it
        p ( ( long ) Math.ceil ( ( double ) N / min ) + 4 ) ; 
    } 

    // Overloaded print methods to handle different data types
    static void p ( String ans ) { 
        System.out.println ( ans ) ; 
    } 

    static void p ( int ans ) { 
        System.out.println ( ans ) ; 
    } 

    static void p ( ) { 
        System.out.println ( ) ; 
    } 

    static void p ( long ans ) { 
        System.out.println ( ans ) ; 
    } 

    static void p ( double ans ) { 
        System.out.println ( ans ) ; 
    } 
}

