
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; // Read the number of elements
        List < Long > list = new ArrayList < > ( ) ; 
        for ( int i = 0 ; i < n ; i ++ ) 
            list.add ( sc.nextLong ( ) ) ; // Read the elements and store them in the list
        
        List < Long > odd = new ArrayList < > ( ) ; // List to store odd numbers
        long sum = 0 ; // Initialize sum of numbers
        
        for ( long i : list ) { // Iterate through the list
            if ( i % 2 == 0 ) 
                sum += i ; // Add to sum if the number is even
            else 
                odd.add ( i ) ; // Add to odd list if the number is odd
        }
        
        Collections.sort ( odd ) ; // Sort the list of odd numbers
        
        for ( long i : odd ) 
            sum += i ; // Add all odd numbers to the sum
        
        if ( odd.size ( ) % 2 != 0 ) 
            sum -= odd.get ( 0 ) ; // Subtract the smallest odd number if the count of odd numbers is odd
        
        System.out.println ( sum ) ; // Print the final sum
    } 
}
