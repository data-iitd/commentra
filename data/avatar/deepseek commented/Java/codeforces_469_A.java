
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Initialize Scanner to read input
        int n = sc.nextInt ( ) ; // Read the total number of levels
        int levels = sc.nextInt ( ) ; // Read the number of levels the user has completed
        int sum = 0 ; 
        int sum2 = 0 ; 
        int sum3 = 0 ; 
        int [ ] arr = new int [ levels ] ; // Initialize array to store completed levels
        int count = 0 ; // Initialize count to track the number of levels the user has completed
        
        // Read the levels completed by the user
        for ( int i = 0 ; i < levels ; i ++ ) { 
            arr [ i ] = sc.nextInt ( ) ; 
        } 
        
        int level2 = sc.nextInt ( ) ; // Read the number of levels the second user has completed
        int level3 = levels + level2 ; // Calculate the total number of levels
        int [ ] arr2 = new int [ level3 ] ; // Initialize array to store all levels
        
        // Copy levels from arr to arr2
        for ( int i = 0 ; i < arr.length ; i ++ ) { 
            arr2 [ i ] = arr [ i ] ; 
        } 
        
        // Read additional levels for arr2
        for ( int i = arr.length ; i < level3 ; i ++ ) { 
            arr2 [ i ] = sc.nextInt ( ) ; 
        } 
        
        // Generate a sequence of numbers from 1 to n
        int [ ] arr3 = new int [ n ] ; 
        int j = 0 ; 
        for ( int i = 0 ; i < n ; i ++ ) { 
            arr3 [ i ] = ++ j ; 
        } 
        
        // Check if all numbers from 1 to n are present in arr2
        for ( int i = 0 ; i < n ; i ++ ) { 
            for ( int x = 0 ; x < arr2.length ; x ++ ) { 
                if ( arr3 [ i ] == arr2 [ x ] ) { 
                    count ++ ; 
                    break ; 
                } 
            } 
        } 
        
        // Print the result based on whether all levels were completed
        if ( count == n ) { 
            System.out.println ( "I become the guy." ) ; 
        } else { 
            System.out.println ( "Oh, my keyboard!" ) ; 
        } 
    } 
}
