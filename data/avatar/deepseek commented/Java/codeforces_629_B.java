
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Initialize Scanner object to read input
        int n = sc.nextInt ( ) ; // Read the number of entries
        int [ ] FfriendPerDay = new int [ 367 ] ; // Array to store the number of female friends per day
        int [ ] MfriendPerDay = new int [ 367 ] ; // Array to store the number of male friends per day
        int answer = 0 ; // Variable to store the maximum number of friends on any single day

        // Loop through each entry
        for ( int i = 0 ; i < n ; i ++ ) { 
            char c = sc.next ( ).charAt ( 0 ) ; // Read the gender (M or F)
            int a = sc.nextInt ( ) ; // Read the start day
            int b = sc.nextInt ( ) ; // Read the end day

            // Update the friend counts for each day in the range
            for ( int j = a ; j <= b ; j ++ ) { 
                if ( c == 'M' ) 
                    MfriendPerDay [ j ] ++ ; // Increment male friend count
                else 
                    FfriendPerDay [ j ] ++ ; // Increment female friend count

                // Determine which gender has the lower count and update the answer
                if ( MfriendPerDay [ j ] < FfriendPerDay [ j ] ) { 
                    if ( MfriendPerDay [ j ] > answer ) 
                        answer = MfriendPerDay [ j ] ; // Update answer if current male count is greater
                } else { 
                    if ( FfriendPerDay [ j ] > answer ) 
                        answer = FfriendPerDay [ j ] ; // Update answer if current female count is greater
                } 
            } 
        } 

        // Output the result, which is twice the maximum number of friends on any single day
        System.out.println ( answer * 2 ) ; 
    } 
}
