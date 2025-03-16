
import java.util.* ; 

public class Main { 
    public static void main ( String args [ ] ) { 
        // Step 1: Read the number of elements N from the standard input
        Scanner scanner = new Scanner ( System.in ) ; 
        int N = scanner.nextInt ( ) ; 
        
        // Step 2: Read N integers from the standard input and add them to the list L
        List < Integer > L = new ArrayList < > ( ) ; 
        for ( int i = 0 ; i < N ; i ++ ) { 
            L.add ( scanner.nextInt ( ) ) ; 
        } 
        
        // Step 3: Sort the list L in ascending order
        Collections.sort ( L ) ; 
        
        // Step 4: Initialize a counter to zero
        int count = 0 ; 
        
        // Step 5: Use two nested loops to iterate through the list L, selecting pairs of elements (a, b) where a < b
        for ( int i = 0 ; i < N ; i ++ ) { 
            for ( int j = i + 1 ; j < N ; j ++ ) { 
                int a = L.get ( i ) ; 
                int b = L.get ( j ) ; 
                
                // Step 6: For each pair (a, b), call the find method to determine the number of elements in the list L
                // that are greater than a + b and are located after the index j+1
                int res = find ( L , j + 1 , a + b ) ; 
                
                // Step 7: Add the result of the find method to the counter count
                count = count + res ; 
            } 
        } 
        
        // Step 8: After all pairs have been processed, print the value of count
        System.out.println ( count ) ; 
    } 
    
    // Step 9: The find method uses a binary search algorithm to efficiently find the number of elements in the list L
    // that are greater than a + b and are located after the index from
    public static int find ( List < Integer > li , int from , int target ) { 
        int low = from ; 
        int upp = li.size ( ) - 1 ; 
        int mid = ( upp - low + 1 ) % 2 == 0 ? ( low + upp ) / 2 + 1 : ( low + upp ) / 2 ; 
        
        if ( upp - low < 0 ) { 
            return 0 ; 
        } else if ( li.get ( from ) >= target ) { 
            return 0 ; 
        } else if ( li.get ( upp ) < target ) { 
            return upp - low + 1 ; 
        } 
        
        while ( upp - low > 1 ) { 
            if ( li.get ( mid ) >= target ) { 
                upp = mid ; 
            } else { 
                low = mid ; 
            } 
            mid = ( upp - low + 1 ) % 2 == 0 ? ( low + upp ) / 2 + 1 : ( low + upp ) / 2 ; 
        } 
        
        return low - from + 1 ; 
    } 
}