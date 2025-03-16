
import java.util.*;

public class Main {

    public static void main ( String [ ] args ) {

        List < Integer > li = new ArrayList < > ( );
        int ind = 0;
        // Initialize an empty list and a variable to keep track of the index

        for ( int i = 1 ; i < 371 ; i++ ) {
            List < Integer > temp = new ArrayList < > ( );
            int p = i, q = i;
            int count = 0;
            // Initialize an empty temporary list and set p and q to the current value of i
            // Initialize a counter to count the number of digits in i

            while ( p!= 0 ) {
                p /= 10;
                count++;
            }
            // Count the number of digits in i by repeatedly dividing p by 10

            if ( count == 1 ) {
                li.add ( i );
            }
            // If i has 1 digit, append it to the list li

            if ( count == 2 ) {
                while ( q!= 0 ) {
                    int x = q % 10;
                    q /= 10;
                    temp.add ( x );
                }
                li.addAll ( temp.subList ( 0, temp.size ( ) - 1 ) );
            }
            // If i has 2 digits, extract the digits and reverse them, then append to li

            if ( count == 3 ) {
                while ( q!= 0 ) {
                    int x = q % 10;
                    q /= 10;
                    temp.add ( x );
                }
                li.addAll ( temp.subList ( 0, temp.size ( ) - 1 ) );
            }
            // If i has 3 digits, extract the digits and reverse them, then append to li
        }

        li.remove ( li.size ( ) - 1 );
        li.remove ( li.size ( ) - 1 );
        // Remove the last two elements from li

        int n = Integer.parseInt ( args [ 0 ] );
        // Take an integer input from the user

        System.out.println ( li.get ( n - 1 ) );
        // Print the nth element of li based on the user's input

    }

}

