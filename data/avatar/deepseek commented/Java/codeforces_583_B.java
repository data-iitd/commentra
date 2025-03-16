
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; 
        while ( in.hasNext ( ) ) { 
            int n = in.nextInt ( ) ; // Read the size of the arrays
            int [ ] a = new int [ n ] ; // Initialize array a
            int [ ] b = new int [ n ] ; // Initialize array b
            int s = - 1 ; // Initialize the counter s to -1
            
            // Read n integers into array a
            for ( int i = 0 ; i < n ; i ++ ) { 
                a [ i ] = in.nextInt ( ) ; 
                b [ i ] = 0 ; // Initialize array b to all zeros
            }
            
            int tem = 1 ; // Initialize tem to 1
            int q = 0 ; // Initialize q to 0
            
            // Enter a while loop that continues until q equals n
            while ( q != n ) { 
                s ++ ; // Increment the counter s
                
                // If tem is 1, process elements from the start of a to the end
                if ( tem == 1 ) { 
                    for ( int i = 0 ; i < n ; i ++ ) { 
                        if ( a [ i ] <= q && b [ i ] == 0 ) { 
                            b [ i ] = 1 ; // Mark the element as processed
                            q ++ ; // Increment the processed element counter
                        } 
                    }
                    tem = 0 ; // Toggle tem to 0
                } 
                
                // If tem is 0, process elements from the end of a to the start
                else { 
                    for ( int i = n - 1 ; i >= 0 ; i -- ) { 
                        if ( a [ i ] <= q && b [ i ] == 0 ) { 
                            b [ i ] = 1 ; // Mark the element as processed
                            q ++ ; // Increment the processed element counter
                        } 
                    }
                    tem = 1 ; // Toggle tem to 1
                } 
            }
            
            // Print the value of s
            System.out.println ( s ) ; 
        } 
    } 
}

