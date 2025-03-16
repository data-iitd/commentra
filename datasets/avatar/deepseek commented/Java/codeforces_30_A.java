
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        new Main ( ).solve ( new Scanner ( System.in ) ) ; 
    } 

    private void solve ( Scanner sc ) { 
        // Step 1: Reading Input Values
        int A = sc.nextInt ( ) ; 
        int B = sc.nextInt ( ) ; 
        int n = sc.nextInt ( ) ; 

        // Step 2: Handling Special Case A == 0
        if ( A == 0 ) { 
            if ( B == 0 ) 
                System.out.println ( 1 ) ; 
            else 
                System.out.println ( "No solution" ) ; 
            return ; 
        } 

        // Step 3: Checking Divisibility
        if ( B % A != 0 ) { 
            System.out.println ( "No solution" ) ; 
            return ; 
        } 

        // Step 4: Normalizing B
        B /= A ; 
        boolean neg = B < 0 ; 
        if ( neg && n % 2 == 0 ) { 
            System.out.println ( "No solution" ) ; 
            return ; 
        } 
        if ( neg ) 
            B = - B ; 

        // Step 5: Iterating to Find Solution
        for ( int x = 0 ; x <= B ; x ++ ) { 
            if ( Math.pow ( x , n ) == B ) { 
                System.out.println ( neg ? - x : x ) ; 
                return ; 
            } 
        } 

        // Step 6: No Solution Found
        System.out.println ( "No solution" ) ; 
    } 
}

