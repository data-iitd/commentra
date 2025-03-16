
import java.util.*;

public class Main {

    public static void main ( String [ ] args ) {

        Scanner sc = new Scanner ( System.in );

        int n = sc.nextInt ( );
        // Read the value of n from input

        int k = sc.nextInt ( );
        // Read the value of k from input

        String s = sc.next ( );
        // Read the string s from input

        int [ ] count = new int [ 26 ];
        // Initialize a list `count` with 26 zeros to count occurrences of each letter

        for ( int i = 0 ; i < s.length ( ) ; i ++ ) {
            count [ s.charAt ( i ) - 'A' ] += 1;
            // Iterate over each character in the string `s`, calculate its index in the `count` list, and increment the corresponding count
        }

        Arrays.sort ( count );
        // Sort the `count` list in descending order

        int res = 0;
        // Initialize `res` to 0, which will be used to store the result

        for ( int i = 0 ; i < 26 ; i ++ ) {
            if ( count [ i ] >= k ) {
                res += k * k;
                System.out.println ( res );
                return;
                // If the current count is greater than or equal to `k`, calculate the result using the formula `k * k` and print it, then exit the program
            }

            k -= count [ i ];
            res += count [ i ] * count [ i ];
            // If the current count is less than `k`, subtract the current count from `k` and add the square of the current count to `res`
        }

        System.out.println ( res );
        // Print the final result `res`
    }
}

