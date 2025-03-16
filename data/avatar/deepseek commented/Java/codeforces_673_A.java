
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; // Read the number of elements in the list `a`
        ArrayList < Integer > a = new ArrayList < Integer > ( ) ; 
        
        int value ; 
        for ( int i = 0 ; i < n ; i ++ ) { 
            value = sc.nextInt ( ) ; // Read each integer value
            a.add ( value ) ; // Add the value to the list `a`
        } 
        
        int result , pos = 0 , flag = 0 ; 
        
        if ( a.get ( 0 ) > 15 ) { 
            result = 15 ; // If the first element is greater than 15, set result to 15
        } else { 
            for ( int i = 1 ; i < n ; i ++ ) { 
                if ( a.get ( i ) - a.get ( i - 1 ) > 15 ) { 
                    pos = i - 1 ; // Find the position where the difference is greater than 15
                    flag = 1 ; // Set flag to 1 indicating such a position is found
                    break ; 
                } 
            } 
            if ( flag == 1 ) { 
                result = a.get ( pos ) + 15 ; // Set result to the element at pos plus 15
            } else { 
                result = a.get ( n - 1 ) + 15 ; // Otherwise, set result to the last element plus 15
            } 
        } 
        
        if ( result > 90 ) { 
            result = 90 ; // If result is greater than 90, set it to 90
        } 
        
        System.out.println ( result ) ; // Print the final result
    } 
}
