
import java.util.Arrays ; 
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; 
        // Step 1: Read the input value n, which represents the number of elements in the array.
        int n = in.nextInt ( ) ; 
        int [ ] a = new int [ n ] ; 
        
        // Step 2: Create an array 'a' of size n and read n elements from the input.
        for ( int i = 0 ; i < n ; i ++ ) { 
            a [ i ] = in.nextInt ( ) ; 
        } 
        
        // Step 3: Sort the array 'a'.
        Arrays.sort ( a ) ; 
        
        // Step 4: Find the minimum element in the sorted array 'a'.
        int min = a [ 0 ] ; 
        
        // Step 5: Check if all elements in the array are divisible by the minimum element. If not, print -1 and exit.
        for ( int value : a ) { 
            if ( value % min != 0 ) { 
                System.out.println ( - 1 ) ; 
                return ; 
            } 
        } 
        
        // Step 6: If all elements are divisible, print the minimum element.
        System.out.println ( min ) ; 
    } 
}

