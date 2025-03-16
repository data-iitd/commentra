import java.util.* ; 
import static java.lang.Math.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Step 1: Read the input value `n` which represents the number of elements to process.
        int n = sc.nextInt ( ) ; 
        
        // Step 2: Read the array of size `3 * n` from the standard input.
        int [ ] array = new int [ 3 * n ] ; 
        for ( int i = 0 ; i < array.length ; i ++ ) 
            array [ i ] = sc.nextInt ( ) ; 
        
        // Step 3: Sort the array in ascending order.
        Arrays.sort ( array ) ; 
        
        // Step 4: Initialize a variable `head` to point to the second last element of the array.
        int head = array.length - 2 ; 
        
        // Step 5: Initialize a variable `res` to store the result.
        long res = 0 ; 
        
        // Step 6: Iterate `n` times, in each iteration:
        // - Add the value at the `head` position to `res`.
        // - Decrement `head` by 2.
        for ( int i = 0 ; i < n ; i ++ ) { 
            res += array [ head ] ; 
            head -= 2 ; 
        } 
        
        // Step 7: Print the result `res`.
        System.out.println ( res ) ; 
    } 
}
