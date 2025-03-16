import java.io.* ; 
import java.util.* ; 

public class Main { 
    // Constructor initializes the output stream and the scanner
    Main ( ) { 
        super ( System.out , true ) ; 
    } 

    Scanner sc = new Scanner ( System.in ) ; 

    public static void main ( String [ ] $ ) { 
        Main o = new Main ( ) ; 
        o.main ( ) ; 
        o.flush ( ) ; 
    } 

    // Main method reads two integers, n and k, from the input
    void main ( ) { 
        int n = sc.nextInt ( ) ; 
        int k = sc.nextInt ( ) ; 
        int [ ] bb = new int [ n ] ; 
        for ( int i = 0 ; i < n ; i ++ ) 
            bb [ i ] = sc.nextInt ( ) ; 

        // Initialize an array to store the result
        int [ ] aa = new int [ n ] ; 
        int m = 0 ; 

        // Process the array bb in reverse order
        for ( int a = n - 1 ; a >= 0 ; a -- ) { 
            int j = 0 ; 
            while ( bb [ a ] > 0 ) { 
                if ( aa [ j ] >= a + k ) 
                    bb [ a ] -- ; 
                j ++ ; 
            } 
            for ( int j_ = m ++ ; j_ > j ; j_ -- ) 
                aa [ j_ ] = aa [ j_ - 1 ] ; 
            aa [ j ] = a ; 
        } 

        // Print the contents of the array aa, incrementing each element by 1
        for ( int i = 0 ; i < n ; i ++ ) 
            print ( aa [ i ] + 1 + " " ) ; 
        println ( ) ; 
    } 
}
