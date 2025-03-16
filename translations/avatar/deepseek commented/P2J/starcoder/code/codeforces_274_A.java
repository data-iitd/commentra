
import java.util.*;

public class Main {

    public static void main ( String [ ] args ) {

        Scanner sc = new Scanner ( System.in );

        int num, k = sc.nextInt ( );  // Read the number of elements and the divisor
        int [ ] arr = new int [ num ];  // Initialize an array of integers
        Set < Integer > different = new HashSet < > ( );  // Initialize a set to keep track of unique elements not divisible by k
        int temp = 0;  // Initialize a variable to store the maximum length of the set

        for ( int i = 0 ; i < num ; i++ ) {
            arr [ i ] = sc.nextInt ( );  // Read the array of integers
        }

        Arrays.sort ( arr );  // Sort the array

        for ( int x : arr ) {
            if ( x % k!= 0 ||!different.contains ( x // k ) ) {  // Check if x is not divisible by k or x//k is not in the set
                different.add ( x );  // Add x to the set if the condition is true
            }
            temp = Math.max ( different.size ( ), temp );  // Update temp with the maximum length of the set
        }

        System.out.println ( temp );  // Print the maximum number of unique elements not divisible by k

    }

}

