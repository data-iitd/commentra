
import java.util.*;
import java.io.*;

public class Main {
    public static void main ( String [ ] args ) {
        // Read the first line of input and create a Counter object for the bought colors
        Scanner sc = new Scanner ( System.in );
        String [ ] bought_count = sc.nextLine ( ).split ( " " );
        Counter < String > bought_count_obj = new Counter < > ( );
        for ( String color : bought_count ) {
            bought_count_obj.add ( color );
        }
        
        // Read the second line of input and create a Counter object for the colors to be made
        String [ ] made_count = sc.nextLine ( ).split ( " " );
        Counter < String > made_count_obj = new Counter < > ( );
        for ( String color : made_count ) {
            made_count_obj.add ( color );
        }
        
        // Initialize the result variable to store the total number of colors that can be made
        int res = 0;
        
        // Iterate over each color in the'made_cout' Counter
        for ( String color : made_count_obj.keySet ( ) ) {
            // Check if the color is not in the 'bought_count' Counter
            if (! bought_count_obj.containsKey ( color ) ) {
                // If a color is not bought, print -1 and exit
                System.out.println ( - 1 );
                return;
            }
            // Calculate the minimum of the counts of the current color in both 'bought_count' and'made_cout'
            // and add this to the result
            res += Math.min ( bought_count_obj.getCount ( color ), made_count_obj.getCount ( color ) );
        }
        
        // Print the final result
        System.out.println ( res );
    }
}

